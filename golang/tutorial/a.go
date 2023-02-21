package main

import (
	"fmt"
)

var i int = 42
var (
	name = "satyam"
	home = "sono"
)
var (
	name2 = "kundan"
	home2 = "blr"
)

func main() {
	// fmt.Println(i)
	// var i int // 0 initialization
	// fmt.Println(i)
	// i = 42
	// var j int = 42
	// k := 42
	// _ = 53
	// fmt.Println(i, j, k)
	// var f float64 = 42.5
	// h := int(f)
	// fmt.Println(f, h)
	// f = 42
	// h = int(f)
	// fmt.Println(f, h, string(h), strconv.Itoa(h)) // 42 42 * 42
	// var flag bool = true
	// fmt.Println(flag)
	// // int8 -127 128
	// // uint8 0 255
	// var i8 int8 = 10
	// var i32 int = 16
	// fmt.Println(i8, i32)
	// // fmt.Println(i8+i32) // wont work
	// a := 10 //1010
	// b := 3  //0011
	// fmt.Println(a&b, a|b, a^b, a&^b)
	// fl := 3.14
	// fl = 2.1e14
	// fl = 13.7e3
	// fmt.Println(fl)
	// fl = 10.2
	// fl2 := 3.7
	// fmt.Println(fl/fl2, fl*fl2, fl+fl2, fl-fl2)
	// var comp complex64 = 1 + 2i
	// fmt.Printf("%v, %T\n", comp, comp)
	// fmt.Printf("%v, %T\n", real(comp), real(comp))
	// comp = complex(1, 1)
	// fmt.Printf("%v, %T\n", imag(comp), imag(comp))
	// arr := [3]int{32, 3}
	// fmt.Println(arr[0], arr[1], arr[2])
	// arr2 := [...]int{32, 3}   //! arrays are of fixed size/capacity
	// fmt.Println(arr2[0], arr2[1])
	// arr3 := [3]int{32, 3, 3}
	// fmt.Println(arr3[0])
	// arr4 := arr3
	// arr4[1] = 4
	// fmt.Println(arr3, arr4)

	arr5 := []interface{}{"tt", 5, false}
	fmt.Println(arr5)

	a := [3]int{5, 78, 8}
	var b [5]int
	// b = a //not possible since [3]int and [5]int are distinct types
	fmt.Println(b, a)
}
