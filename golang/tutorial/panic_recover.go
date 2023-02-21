package main

import (
	"fmt"
)

func main() {
	fmt.Println("start")
	//******
	//before including this output was
	// start, about to panic, Error, something bad happened, end
	//but after it became
	// start, about to panic, Error, something bad happened, something bad happened //?no end

    //recover is only useful in deferred functions
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("Error", err)
		}
	}()
	//******
	panicker()
	// defer func() { // this defer wouldnt have solve the  problem as this is not known TO MAIN yet
	// 	if err := recover(); err != nil {
	// 		fmt.Println("Error", err)
	// 	}
	// }()
	fmt.Println("end")

}
func panicker() {
	fmt.Println("about to panic")
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("Error", err)
			// this err won't go to main function, so we have to repanic the same Error
			panic(err)
		}
	}()
	panic("something bad happened")
	fmt.Println("done panicking")
}

// start, about to panic, Error, something bad happened, end
