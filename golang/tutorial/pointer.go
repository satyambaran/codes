package main

import (
	"fmt"
	"reflect"
)

type myStruct struct {
	id int
}
type counter int

func main() {
	// var a counter = 42  // even though counter is under the hood int  but you cant do  this //? var c *int = &a
	var a int = 42
	b := &a
	var c *int = &a
	fmt.Println(a, &a, b, *b, c, *c)

	arr := [3]int{1, 2, 3}
	arr_pointer := &arr
	arr_copy := arr
	arr_pointer[0] = 9
	arr_copy[0] = 10
	fmt.Println(arr, arr_copy, arr_pointer, &arr[0], &arr[1]) //32 bit integers ie 4 bytes

	// ?all assignment operations are copy operations
	// ?slices and maps create internal pointers, so even copy points the same data
	arr2 := []int{1, 2, 3}
	arr2_pointer := &arr2
	arr2_copy := arr2
	// arr2_pointer[0] = 9 //wont work
	(*arr2_pointer)[0] = 9
	arr2_copy[0] = 10
	fmt.Println(arr2, arr2_copy, arr2_pointer)

	var ms myStruct
	ms = myStruct{id: 5}
	fmt.Println()

	var ms2, ms3, ms4 *myStruct
	ms2 = &myStruct{id: 6}
	ms3 = new(myStruct)
	fmt.Println(ms, ms2, ms.id, ms2.id, (*ms2).id, ms3, ms3.id, ms4)
	// ms4 is nil but ms3 is 0

	fun("a", "a", 5, 5)
	str1 := "b"
	str2 := "b"
	// fun2(str1, str2) //todo wont work
	fun2(&str1, str2)
	fmt.Println(str1, str2)
	slicee, ff := fun3(1, 2, 3, 4)
	fmt.Println(slicee, *slicee, ff)

	ans, er := div(2.8, 0.0060)
	if er != nil {
		fmt.Println(er)
	} else {
		fmt.Println(ans)
	}

	// anonymous function
	i := 5
	func(i int) {
		fmt.Println("Anonymous Function", i)
	}(i)
	var f func(i int) = func(i int) {
		fmt.Println("Anonymous Function", i)
	}
	f(i)

	g := greeter{
		prefix: "Hi ",
		suffix: "Good night",
	}
	//? method function
    // we can  use pass by address to use public and private properties
	fmt.Println(g.greet("Satyam,\n"), g)
	fmt.Println(g.greet2("Satyam\n"), g)

}

type greeter struct {
	prefix string
	suffix string
}

func (g greeter) greet(a string) string {
	g.prefix = "Hello "
	return g.prefix + a + g.suffix
}
func (g *greeter) greet2(a string) string {
	g.prefix = "Hello "
	return g.prefix + a + g.suffix
}

func fun(a, b string, c, d int) {
	fmt.Println(a, c, &a, &b)
}
func fun2(a *string, b string) {
	fmt.Println(*a, b)
	*a = "c"
	b = "c"
	fmt.Println(a, b)
}

// func fun3(a int, slice ...int, b string) {     //wont work
//
//	func fun3(a int, slice ...int, b int) {    // wont work
func fun3(a int, slice ...int) (*[]int, string) {
	fmt.Println(a)
	fmt.Println(slice, reflect.TypeOf(slice))
	ff := "aa"
	return &slice, ff
}

func div(a, b float64) (float64, error) {
	if b == 0.0 {
		return 0.0, fmt.Errorf("Can not divide with zero")
	}
	return a / b, nil
}
