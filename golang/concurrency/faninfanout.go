package main

import (
    "fmt"
    "sync"
)

func main() {
    list := []int{2, 5, 3, 1, 9, 6, 4}
    streamChan := stream(&list)

    const numWorkers = 3
    workers := make([]chan int, numWorkers)
    for i := 0; i < numWorkers; i++ {
        workers[i] = consume(streamChan)
    }

    mergedChan := merge(workers...)
    printWg := &sync.WaitGroup{}
    printWg.Add(1)
    go print(mergedChan, printWg)

    printWg.Wait()
}

func stream(ints *[]int) chan int {
    streamChan := make(chan int)
    go func(ints *[]int) {
        for _, val := range *ints {
            streamChan <- val
        }
        close(streamChan)
    }(ints)
    return streamChan
}

func consume(streamChan chan int) chan int {
    squaredChan := make(chan int)
    go func() {
        for cur := range streamChan {
            squaredChan <- (cur * cur)
        }
        close(squaredChan)
    }()
    return squaredChan
}

func merge(cs ...chan int) chan int {
    var wg sync.WaitGroup
    out := make(chan int)
    // Start an output goroutine for each input channel in cs.  output
    // copies values from c to out until c is closed, then calls wg.Done.
    output := func(c <-chan int) {
        for n := range c {
            out <- n
        }
        wg.Done()
    }
    wg.Add(len(cs))
    for _, c := range cs {
        go output(c)
    }

    // Start a goroutine to close out once all the output goroutines are
    // done.  //!!!?????todo    This must start after the wg.Add call.
    go func() {
        wg.Wait()
        close(out)  //! position of close is important
    }()
    return out
}

func print(squaredChan chan int, wg *sync.WaitGroup) {
    defer wg.Done()
    for cur := range squaredChan {
        fmt.Println(cur)
    }
}
