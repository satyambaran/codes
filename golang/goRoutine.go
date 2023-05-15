package main

import (
	"fmt"
	"time"
)

func display(str string, n int) {
	for w := 0; w < n; w++ {
		//we need to put some delay to get it printed otherwise
		fmt.Println(str)

	}
}
func display2(str string, n int) {
	for w := 0; w < n; w++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(str)

	}
}

func main() {
	//?  interpreted(python, JavaScript etc) and compiled(c, c++, go) languages
	//? 		go routine is a function which executes independently and simultaneously in connection with any other 	Goroutines present in your program
	// todo 	main function is itself a go routine
	// todo 	Goroutine like a light weighted thread. The cost of creating Goroutines is very small as compared to the thread.
	//? 		All the Goroutines are working under the main Goroutines if the main Goroutine terminated, then all the goroutine present in the program also terminated.

	//? go routine

	go display("go routine 1", 6)
	display("main", 6)

	//? only main will be displayed because, go routine starts on stack basis so main go routine already started and terminated before 'go routine 1' even could start. SO will have to add soe delay, either make loop size big ~60000 or add some delay time
	go display2("go routine 1", 6)
	display2("main", 6)

	// main 12 timmes, go routine 1 11 timmes

	// ~~> ~~>
	/*****

	Process:  A single processor system contains only one processor. So only one process can be executed at a time.


	threding: A thread is a path of execution within a process.



	multi threading (https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)#Advantages)

	multi-threading is a vehicle for accomplishing some concurrency

	it's kinda similar to Parallel Computing(which can only happen in multicore processor) and can happen in single as well as multiple core processor

	helps us acheive somewhat parallelism in a single core processor

	two threads never runs together

	when a thread is needed to wait for something, like I/O operations which might take many CPU cycles, then this time can be utilize to execute other threads. A threaded processor would switch execution to another thread that was ready to run in ready set
	t1 t2 t1
	-- -  --

	goal of multithreading hardware support is to allow quick switching between a blocked thread and another thread ready to run. It means that the hardware switches from using one register set to another.
	Thread should behave as if it were executing alone and not sharing any hardware resources with other threads

	A processor register (CPU register) is one of a small set of data holding places that are part of the computer processor. which may hold an instruction, a storage address, or any kind of data

	in a 64-bit computer, a register must be 64 bits in length
	to quickly switch between two threads, the processor is built with atleast two sets of registers

	Communication between multiple threads is easier compared to processes



	Goroutines are the way of doing tasks concurrently in golang. They exist only in the virtual space of the Go runtime and not the OS, therefore the Go Runtime scheduler is needed to manage their lifecycles. It's important to keep in mind that all the OS sees is a single user level process requesting and running multiple threads. The goroutines itself are managed by the Go Runtime Scheduler.

	thread is very expensive(>32KB) and it doesn't have inifinite stack.
	go routine(<2KB)
	go routine states:= running, blocked, runnable
	go routine allows async/await in golang

	https://towardsdatascience.com/understanding-concurrency-and-multi-threaded-programs-261047c8231f

	Go Runtime maintains three C structs

	i) G Struct : Represents a single goroutine and contains the fields necessary to keep track of its stack and current status.
	ii) M Struct :


	Channel: main purpose is to comunicate between main routine and child go routines
	pass channel as read only (name <-chan bool)

	recieve operation from an empty channel blocks the go routine and send in the channel will unblock the go routine.

	//? mutex (mutual exclusion object) is a program object that is created so that multiple program thread can take turns sharing the same resource, such as access to a file.

	*/

}

//?   	When a program is loaded into memory along with all the resources it needs to operate, it is called a process.

//?		Heap is just an area where memory is allocated or deallocated without any order. This happens when one creates an object using the new operator or something similar. This is opposed to stack where memory is deallocated on the first in last out basis.
//?		Process consist of registers, counter(keeps track of where a computer is in its program sequence), stack, heap, code.

// How Threads and Processes Work Step By Step

// The program starts out as a text file of programming code.
// The program is compiled or interpreted into binary form.
// The program is loaded into memory.
// The program becomes one or more running processes. Processes are typically independent of one another.
// Threads exist as the subset of a process.
// Threads can communicate with each other more easily than processes can.
// Threads are more vulnerable to problems caused by other threads in the same process.

// https://stackoverflow.com/questions/53791646/multiple-sync-waitgroup-usage
