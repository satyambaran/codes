package main

import (
	"fmt"
	"time"
)

// use -race flag to test all this scenario
func main() {
	ch := make(chan int, 5)
	defer func() {
		close(ch) // here at least we're gracefully shutting down channel,
	}()
	go read(ch)
	ch <- 1
	ch <- 2
	time.Sleep(10 * time.Millisecond)
	//once main function's last statment is executed, program will shut down
	// so even  though read function is still expecting values in chan, it'll shutdown after sleep because main is hutting down
	// we are not getting error from go side, but this is incorrect way of writing code

}
func read(ch chan int) {
	for i := range ch {
		fmt.Println(i)
	}
}
