
package main

import (
	"fmt"
	"time"
)

func func1(channel chan int) {
	for i := 0; i < 5; i++ {
		fmt.Println("1->i:", i)
		channel <- i
		time.Sleep(5 * time.Millisecond)
	}
}

func func2(channel chan int) {
	for i := 0; i < 5; i++ {
		fmt.Println("2->i:", i)
		channel <- i
		time.Sleep(5 * time.Millisecond)
	}
}

func printFunc1(channel chan int) {
	for i := 0; i < 5; i++ {
		val := <-channel
		fmt.Println("from func1", val)
	}
}

func printFunc2(channel chan int) {
	for i := 0; i < 5; i++ {
		val := <-channel
		fmt.Println("from func2", val)
	}
}

func main() {
	chan1 := make(chan int)
	chan2 := make(chan int)
	go func1(chan1)
	go func2(chan2)
	// // var fromFunc1, fromFunc2 int
	// // for i := 0; i < 5; i++ {
	// // 	fromFunc1 = <- chan1
	// // 	fromFunc2 = <- chan2
	// // 	fmt.Println(fromFunc1, fromFunc2)
	// // }
	go printFunc1(chan1)
	go printFunc2(chan2)
	time.Sleep(time.Second)
}

