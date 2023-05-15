package main

import (
	"fmt"
	"strings"
)

func init() {
	fmt.Println("this 'init()' function is called when package is  initialized")
}
func main() {
	// var name string
	// name = "satyam"
	// var name1 string = "satyam"
	// name2, age := "satyam", 23
	// fmt.Println(name, name1, name2, age)

	// emoji := []string{"😀", "😃", "😚", "satyam"} //slice is a variable-length sequence that stores the homogeneous type of data. 
	// fmt.Println(emoji)

	var myChar byte = 'a'
	myChar2 := "a"[0]
	myChar3 := 'a'

	myString := "hello"
	myStringBytes := []byte(myString)

	myStringBytes[0] = 'H'
	// myString[1] = 'E' //!  wont work
	myString = string(myStringBytes)
	fmt.Println(myString, myChar, myChar2, myChar3)

	var myMap map[string]string
	// myMap["name"] = "satyam" //?   panic: assignment to entry in nil map
	fmt.Println(myMap)
	myMap = make(map[string]string)
	fmt.Println(myMap)
	myMap["name"] = "satyam"
	fmt.Println(myMap)

	var myMap1 map[string]string = map[string]string{}
	myMap1["name"] = "satyam"
	fmt.Println(myMap1)

	myMap2 := map[string]string{}
	myMap2["name"] = "satyam"
	fmt.Println(myMap2)

	var year int = 1999
	var birthYear *int = &year
	birthYear1 := &year
	fmt.Println(birthYear, *birthYear, birthYear1, *birthYear1)

	const PI float64 = 3.14
	fmt.Println(PI)

	for i := 0; i < 4; i++ {
		fmt.Printf("GeeksforGeeks\t\t\t")
	}
	// Infinite loop
	for {
		fmt.Printf("GeeksforGeeks\n")
		break
		// continue
	}

	//while loop
	i := 0
	for i < 3 {
		i += 2
	}

	rvariable := []string{"GFG", "Geeks", "GeeksforGeeks"}

	// i and j stores the value of rvariable
	// i store index number of individual string and
	// j store individual string of the given array
	for idx, val := range rvariable {
		fmt.Println(idx, val)
	}
	for idx, char := range "XabCd" {
		fmt.Println(idx, char, string(char)) //? here char is of type rune
	}

	mmap := map[int]string{
		22: "Geeks",
		33: "GFG",
		44: "GeeksforGeeks",
	}
	for key, value := range mmap {
		fmt.Println(key, value)
	}

	chnl := make(chan int)
	go func() {
		chnl <- 100
		chnl <- 1000
		chnl <- 10000
		chnl <- 100000
		close(chnl)
	}()
	for i := range chnl {
		fmt.Println(i)
	}

	var p int = 10
	var q int = 20
	swap(&p, &q)
	fmt.Println(p, q)

	fmt.Println(joinstr("GEEK", "GFG"))
	fmt.Println(joinstr("Geeks", "for", "Geeks"))

	// Passing arguments in anonymous function
	value := func(ele string) string {
		return ele + "hh"
	}("GeeksforGeeks")
	fmt.Println(value)

	names := []string{"stanley", "david", "oscar"}
	vals := make([]interface{}, len(names)+1)
	for i, v := range names {
		vals[i] = v
	}
	vals[3] = 5
	PrintAll(vals) //? PrintAll need interface type, so will have to vert every thing to interface
	//? PrintAll(names) wont work

}
func PrintAll(vals []interface{}) {
	for _, val := range vals {
		fmt.Println(val)
	}
}
func joinstr(elements ...string) string {
	return strings.Join(elements, "-")
}
func swap(a, b *int) (int, int) {
	var temp int = *a
	*a = *b
	*b = temp
	return *a, *b
}
