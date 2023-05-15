package main

import (
	"fmt"
	"sync"
)

// use -race flag to test all this scenario
func main() {
	example0()
}

func example() {
	wg := &sync.WaitGroup{}
	ch := make(chan int) //? unbuffered channel only 1 int can be stored here
	for j := 0; j < 5; j++ {
		wg.Add(2)
		go func() {
			defer wg.Done()
			i := <-ch
			fmt.Println(i)
		}()
		go func() {
			i := 42
			ch <- i //we pass copy of data, so it'll be 42
			i = 27
			wg.Done()
		}()
	}
	wg.Wait()
}
func example0() {
	//! very very very important
	wg := &sync.WaitGroup{}
	ch := make(chan int)
	wg.Add(1)
	go func() {
		fmt.Println("2")
		ch <- 42 //? An unbuffered channel is a channel with a capacity of 0. When a value is sent on an unbuffered channel, the sender blocks until the value is received by the receiver.
		// code will go in deadlock

		// buffered channels allow for asynchronous communication
		i := <-ch
		fmt.Println("2", i)
		wg.Done()
	}()
	wg.Wait()
}
func example1() {
	// very important
	wg := &sync.WaitGroup{}
	ch := make(chan int)
	wg.Add(2)
	go func() {
		fmt.Println("1")
		i := <-ch //? since it was waiting already
		fmt.Println("1", i)
		ch <- 27
		wg.Done()
	}()
	go func() {
		fmt.Println("2")
		ch <- 42
		i := <-ch
		fmt.Println("2", i) //? this wont get executed until previous one is printed
		wg.Done()
	}()
	wg.Wait()
}
func example2() {
	// very important
	wg := &sync.WaitGroup{}
	ch := make(chan int)
	wg.Add(2)
	go func(ch <-chan int) {
		i := <-ch
		fmt.Println("1", i)
		wg.Done()
	}(ch)
	go func(ch chan<- int) {
		ch <- 42
		wg.Done()
	}(ch) //(ch<-) wont work
	wg.Wait()
}
func example3() {
	//imp this program wont work
	wg := &sync.WaitGroup{}
	ch := make(chan int)
	go func() {
		defer wg.Done()
		i := <-ch
		fmt.Println(i)
	}()
	for j := 0; j < 5; j++ {
		wg.Add(2)
		go func(j int) {
			i := 42
			ch <- i //we pass copy of data, so it'll be 42
			// code is stopped here at  j=1 iteration, because no one's there to read it
			fmt.Println(j)
			i = 27
			wg.Done()
		}(j)
	}
	wg.Wait() //without this wait this function would have run fine, because it wont be waiting for anything
}
func example4() {
	//?imp      this program will work,
	//todo      but some data will get lost
	wg := &sync.WaitGroup{}
	ch := make(chan int, 50) // if wouldve kept the size 3, this program would have blocked.
	// but go program can terminate itself with value still in channel
	go func() {
		defer wg.Done()
		i := <-ch
		fmt.Println(i)
	}()
	wg.Add(6)
	for j := 0; j < 5; j++ {
		go func(j int) {
			i := 42
			ch <- i // we pass copy of data, so it'll be 42
			// code wont be stopping here as we have places to store int in channels
			fmt.Println(j)
			i = 27
			wg.Done()
		}(j)
	}
	wg.Wait()
}
func example5() {
	wg := &sync.WaitGroup{}
	ch := make(chan int, 50)
	wg.Add(2)
	go func() {
		defer wg.Done()
		// for i := range ch {
		// 	fmt.Println(i)
		// }
		for {
			if i, ok := <-ch; ok {
				fmt.Println(i, ok)
			} else {
				break
			}
		}
	}()
	go func() {
		i := 42
		ch <- i
		i = 27
		ch <- i
		close(ch) // without this close,    range ch/ for{}   will keep expecting values and hence deadlock
		// after closing, we cant send message to chan but we can receive though

		wg.Done()
	}()

	wg.Wait()
}
func example6() {
	var count int
	wg := &sync.WaitGroup{}

	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func() {
			count++
			wg.Done()
		}()
	}

	wg.Wait()

	fmt.Println(count)
}
func example7() {
	var count int
	var mutex sync.Mutex
	wg := &sync.WaitGroup{}

	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func() {
			mutex.Lock()
			count++
			mutex.Unlock()
			wg.Done()
		}()
	}

	wg.Wait()

	fmt.Println(count)
}
