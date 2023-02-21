package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

// when all go routines are done processing and something(either waitGroup or channel) is still waiting then we get //?fatal error: all goroutines are asleep - deadlock!

func main() {
	example2()
}

func example() {
	//? race condition can be detected by       go run -race ./golang/tutorial/goroutines.go
	var msg = "Hello"
	go func() {
		fmt.Println(msg)
	}()
	msg = "Goodbye"
	// will print Goodbye
	go func(msg string) { // better practice
		fmt.Println(msg)
	}(msg)
	msg = "Goodbye22"
	time.Sleep(100 * time.Millisecond)
}
func example1() {
	var wg = &sync.WaitGroup{}
	wg.Add(1) // this should be done before every go routine call
	msg := "hi"
	go func(msg string) {
		fmt.Println(msg)
		wg.Done()
	}(msg)
	wg.Wait()
}

func example2() {
	var wg = &sync.WaitGroup{}
	var counter = 0

	sayHello := func(wg *sync.WaitGroup, counter int) {
		defer wg.Done()
		fmt.Println("hello ", counter) // this will print zero because we passed counter itself which was not updateed yet
	}
	sayHello2 := func(wg *sync.WaitGroup) {
		defer wg.Done()
		fmt.Println("hello2 ", counter) // this will print random things in random order, go routines are not syncronized
	}
	increment := func(wg *sync.WaitGroup) {
		defer wg.Done()
		counter++
	}
	for i := 0; i < 5; i++ {
		wg.Add(3)
		go sayHello(wg, counter)
		go sayHello2(wg)
		go increment(wg)
	}
	wg.Wait()
}

func example3() {
	wg := &sync.WaitGroup{}
	m := &sync.RWMutex{}

	// in this example we have removed concurrency completely by bounding it

	counter := 0
	sayHello := func(wg *sync.WaitGroup, counter int) {
		defer wg.Done()
		fmt.Println("hello ", counter) // this will print zero because we passed counter itself which was not updateed yet
		m.RUnlock()
	}
	increment := func(wg *sync.WaitGroup) {
		defer wg.Done()
		counter++
		m.Unlock()
	}
	for i := 0; i < 5; i++ {
		wg.Add(2)
		m.RLock() // RLock locks rw for reading. It should not be used for recursive read locking; a blocked Lock call excludes new readers from acquiring the lock. See the documentation on the RWMutex type.
		go sayHello(wg, counter)
		m.Lock() // Lock locks rw for writing. If the lock is already locked for reading or writing, Lock blocks until the lock is available.
		go increment(wg)
	}
	wg.Wait()
}

func example4() {
	//more threads can increase performance but unnecessarily more will slow it down
	runtime.GOMAXPROCS(2) //GOMAXPROCS sets the maximum number of CPUs that can be executing simultaneously and returns the previous setting.
	fmt.Printf("%v", runtime.GOMAXPROCS(-1))
}
