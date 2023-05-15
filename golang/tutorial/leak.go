package main

import "fmt"

func main() {
    handler()
}

func goroutineLeak(ch chan int) {
    data := <-ch
    fmt.Println(data)
}

func handler() {
    ch := make(chan int)
    // defer close(ch) //??solution
    go goroutineLeak(ch)
    return
}

// func forgottenSender(ch chan int) {
//     data := 3

//     // This is blocked as no one is receiving the data
//     ch <- data
// }

// func handler() {
//     ch := make(chan int)

//     go forgottenSender(ch)
//     return
// }
