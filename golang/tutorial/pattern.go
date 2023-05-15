package main

import (
    "fmt"
    "sync"
)
// Channel Must Always Be Closed by the Sender
// Generator Pattern
// Error as a First-Class Citizen
// Stopping Short
// Pipeline Pattern
// Fan-out, Fan-in

func main() {
    input := []int{1, 2, 3, 4, 5, 6, 7, 8}

    doneCh := make(chan struct{})
    defer close(doneCh)

    inputCh := generator(doneCh, input)

    channels := fanOut(doneCh, inputCh)
    addResultCh := fanIn(doneCh, channels...)

    resultCh := multiply(doneCh, addResultCh)

    for res := range resultCh {
        fmt.Println(res)
    }
}
func fanOut(doneCh chan struct{}, inputCh chan int) []chan int {
    numWorkers := 10
    channels := make([]chan int, numWorkers)

    for i := 0; i < numWorkers; i++ {
        addResultCh := add(doneCh, inputCh)
        channels[i] = addResultCh
    }

    return channels
}
func fanIn(doneCh chan struct{}, resultChs ...chan int) chan int {
    finalCh := make(chan int)
    var wg sync.WaitGroup

    for _, ch := range resultChs {
        wg.Add(1)
        chClosure := ch

        go func() {
            defer wg.Done()

            for data := range chClosure {
                select {
                case <-doneCh:
                    return
                case finalCh <- data:
                }
            }
        }()
    }

    go func() {
        wg.Wait()
        close(finalCh)
    }()

    return finalCh
}
func generator(doneCh chan struct{}, input []int) chan int {
    inputCh := make(chan int)

    go func() {
        defer close(inputCh)

        for _, data := range input {
            select {
            case <-doneCh:
                return
            case inputCh <- data:
            }
        }
    }()

    return inputCh
}
func add(doneCh chan struct{}, inputCh chan int) chan int {
    addRes := make(chan int)

    go func() {
        defer close(addRes)

        for data := range inputCh {
            result := data + 1

            select {
            case <-doneCh:
                return
            case addRes <- result:
            }
        }
    }()

    return addRes
}

func multiply(doneCh chan struct{}, inputCh chan int) chan int {
    multiplyRes := make(chan int)

    go func() {
        defer close(multiplyRes)

        for data := range inputCh {
            result := data * 2

            select {
            case <-doneCh:
                return
            case multiplyRes <- result:
            }
        }
    }()

    return multiplyRes
}

// func main() {
//     handler()
// }
// func handler() {
//     input := []int{1, 2, 3, 4, 5, 6}
//     inputCh := generator(input)

//     for data := range inputCh {
//         fmt.Println("EXITING!")
//         if data == 3 {

//             return
//         }
//     }
// }

// func generator(input []int) chan int {
//     inputCh := make(chan int)

//     go func() {
//         defer close(inputCh)
//         for _, data := range input {
//             inputCh <- data
//         }
//     }()

//     return inputCh
// }

// func handler() {
//     input := []int{1, 2, 3, 4, 5, 6}

//     // Explicit cancellation
//     doneCh := make(chan struct{})
//     defer close(doneCh)

//     inputCh := generator(doneCh, input)

//     for data := range inputCh {
//         fmt.Println(data)
//         if data == 3 {
//             return
//         }
//     }
// }

// func generator(doneCh chan struct{}, input []int) chan int {
//     inputCh := make(chan int)

//     go func() {
//         defer close(inputCh)

//         for _, data := range input {
//             select {
//             case <-doneCh:
//                 return
//             case inputCh <- data:
//             }
//         }
//     }()

//     return inputCh
// }
