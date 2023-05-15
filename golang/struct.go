package main

import (
	"bytes"
	"fmt"
	"sort"
	"strings"
)

type author struct {
	name      string
	branch    string
	particles int
	salary    int
	address   Address
}
type Address struct {
	name, street, city, state string
	Pincode                   int
}

func (a author) show(inr int) int {
	fmt.Println("Salary: ", a.salary*inr)
	return a.salary * inr
}
func (a *author) show2(inr int) int {
	fmt.Println("Salary: ", (*a).salary*inr, a.salary*inr)
	return a.salary * inr
}
func mul(a1, a2 int) int {
	fmt.Println("Result: ", a1*a2)
	return 0
}
func main() {
	mul(1, 2)
	defer mul(10, 2)
	defer mul(100, 2)
	mul(1000, 2)
	//?? follows last in first out

	// Go methods are similar to Go function with one difference, i.e, the method contains a receiver argument in it.
	res := author{
		name:      "Sona",
		branch:    "CSE",
		particles: 203,
		salary:    34000,
		address:   Address{"Akshay", "PremNagar", "Dehradun", "Uttarakhand", 252636},
	}

	// Calling the method
	fmt.Println(res.show(100))
	fmt.Println(res.show2(100))
	//   Methods of the same name but different types can be defined in the program.
	// Functions of the same name but different type are not allowed to be defined in the program.

	var a Address

	address := Address{"Akshay", "PremNagar", "Dehradun", "Uttarakhand", 252636}
	address2 := Address{name: "Akshay", street: "PremNagar", city: "Dehradun", state: "Uttarakhand", Pincode: 252636}
	fmt.Println(address, address2, a, address.name)

	address3 := &Address{"Akshay", "PremNagar", "Dehradun", "Uttarakhand", 252636}
	fmt.Println(address3.city, (*address3).city) // both will work

	//An array is a fixed-length sequence that is used to store homogeneous elements in the memory.
	//Slice is a variable-length sequence which stores elements of a similar type
	arr := [3][3]string{{"C #", "C", "Python"}, {"Java", "Scala", "Perl"},
		{"C++", "Go", "HTML"}}
	var undeclaredArr [2]int
	arr2 := [...]int{9, 7, 6, 4, 5, 3, 2, 4}
	slice := []int{90, 60, 40, 50,
		34, 49, 30}
	sort.Ints(slice)
	fmt.Println(arr, arr2, undeclaredArr, len(arr2), slice)

	// var my_slice_1 = make([]int, 4, 7) //? length, capacity

	matrix := [3][3]int{
		{2, 3, 1},
		{6, 3, 5},
		{1, 4, 9},
	}
	//?        to use this as a slice
	sort.Slice(matrix[:], func(i, j int) bool {
		fmt.Println(i, j)
		// for x := range matrix[i] {
		// 	if matrix[i][x] == matrix[j][x] {
		// 		continue
		// 	}
		// 	return matrix[i][x] < matrix[j][x]
		// }
		return matrix[i][2] > matrix[j][2]
	})
	fmt.Println(matrix)

	slice_1 := []byte{'!', 33, 'a'} //? byte means := 8-bit unsigned integer
	fmt.Println("dd: ", slice_1)

	slice_1 = []byte{'!', '!', 'G', 'e', 'e', 'k', 's',
		'f', 'o', 'r', 'G', 'e', 'e', 'k', 's', '#', '#'}
	res1 := bytes.Split(slice_1, []byte("eek"))
	fmt.Println("Slice 1: ", res1)

	string1 := "satyam"
	byte1 := []byte(string1)
	byte1[0] = '1'
	string1 = string(byte1)
	// string1[0] = byte('k')	//? cannot assign to string1[0] (value of type byte
	// string1[0] =[] byte{'k'}	//? cannot assign to string1[0] (value of type byte
	// string1[0] = 'k' //? cannot assign to string1[0] (value of type byte
	// string1[0] = "k" //? cannot assign to string1[0] (value of type byte

	//! string is a read-only slice of bytes and the bytes of the strings can be represented in the Unicode text using UTF-8 encoding.

	fmt.Println(string1)
	for index, s := range "GeeksForGeeKs" {
		fmt.Println(s, index)
	}
	splitedStr := strings.Split(string1, "a")
	fmt.Println(splitedStr)

	str1 := "Geeks"
	str2 := "Geek"
	str3 := "geek"
	fmt.Println(str1 < str2, str1 > str2, str2 > str3, str2 < str3, strings.Compare(str1, str2), strings.Compare(str2, str3))

	var ptr *string = &str1
	var ptr2 *[]byte = &slice_1
	fmt.Println(ptr, *ptr, ptr2, *ptr2)
	print(ptr, ptr2)

	auth := author{"satyam", "BLR", 1, 1, Address{"satyam", "HSR", "BLR", "KA", 560102}} //? we need all 6 of themm
	authPtr := &auth
	fmt.Println(auth, authPtr, *authPtr, *&authPtr.name, authPtr.name, (*authPtr).name /*, authPtr->name (wont work)*/)

	//* double pointer
	var V int = 100
	var pt1 *int = &V
	var pt2 **int = &pt1
	fmt.Println(pt1, *pt2, pt2, &pt2, **pt2)

}

func print(a *string, b *[]byte) {
	fmt.Println(*a, *b)
}
