package main

import (
	"fmt"
)

type Details struct {
	place string
	//fieldName fieldType
	names   []string
	courses []string
}

type Animal struct {
	Name   string `json:"name" required max:"10"`
	Origin string `json:"origin"`
	// Bird     //illegal  cycle in declaration
}

type Bird struct {
	Animal `json:"animal"`
	Fly    bool
	Speed  float64
}

type Fish struct {
	Kind  Animal
	Fly   bool
	Speed float64
}

func main() {
	// map1 := map[string]int{
	// 	"a": 1,
	// 	"b": 2,
	// }
	// key1 := [3]int{0, 1, 2}
	// key2 := [3]int{0, 1, 2}
	// // key3 := []int{0, 1}
	// // map2 := map[[]int]int{} //slice can't be a key to a map, array can
	// map2 := map[[3]int]int{
	// 	key1: 1,
	// 	key2: 2,
	// 	// key3: 3, //wont work
	// }
	// fmt.Println(map1, map2)

	// map3 := make(map[string]int)
	// map3 = map[string]int{
	// 	"a": 1,
	// 	"b": 2,
	// }
	// map3["c"] = 3
	// delete(map3, "b")
	// fmt.Println(map3, len(map3), map3["a"], map3["b"], map3["d"])
	// idx, ok := map3["d"]
	// fmt.Println(idx, ok)
	// idx, ok = map3["a"]
	// fmt.Println(idx, ok)
	// fmt.Println(map3)
	// map5 := map3 //default assign by reference
	// delete(map5, "c")
	// fmt.Println(map3, map5)

	// details := Details{
	// 	place:   "Sono",
	// 	names:   []string{"satyam", "kundan"},
	// 	courses: []string{"sd", "aws"},
	// }
	// fmt.Println(details, details.names[1])
	// details1 := Details{
	// 	"Sono",
	// 	[]string{"satyam", "kundan"},
	// 	[]string{"sd", "aws"},
	// }
	// // details2 := Details{ // to few arguments
	// // 	"Sono",
	// // 	[]string{"satyam", "kundan"},
	// // }
	// fmt.Println(details1)

	// details3 := struct{ name string }{"satyam"}
	// fmt.Println(details3, details3.name)
	// details4 := details3
	// details5 := &details3
	// details4.name = "kundan"
	// fmt.Println(details3, details4)
	// details5.name = "kundan"
	// fmt.Println(details3, *details5)

	// random := map[interface{}]interface{}{
	// 	1:    "rr",
	// 	"rr": 1,
	// }
	// fmt.Println(random)

	// bird := Bird{Animal{"parrottttttttt", "india"}, true, 48.3}
	// bird2 := Bird{
	// 	Animal: Animal{"parrot", "india"}, // having to accept embedding
	// 	Fly:    true,
	// 	Speed:  48.3,
	// }
	// fish := Fish{Animal{"katla", "india"}, false, 48.3}
	// fish2 := Fish{
	// 	Kind:  Animal{"katla", "india"},
	// 	Fly:   false,
	// 	Speed: 48.3,
	// }
	// fmt.Println(bird.Name, bird.Animal, fish.Kind.Name, bird2, fish2, bird2.Animal)

	// k, err := json.Marshal(bird)
	// fmt.Println(string(k), err)

	// t := reflect.TypeOf(Animal{})
	// field, _ := t.FieldByName("Name")
	// fmt.Println(field)

	// // if loop
	// switch i := 2 * 3; i {
	// case 1, 3, 5, 7:
	// 	fmt.Println("odd")
	// case 2, 4, 6, 8:
	// 	fmt.Println("even")
	// default:
	// 	fmt.Println("Zero")
	// }
	// i := 10
	// switch {
	// case i <= 10:
	// 	fmt.Println("less than 10")
	// 	// break is by default added in go
	// 	// to remove that, use
	// 	fallthrough
	// case i <= 20:
	// 	fmt.Println("less than 20")
	// default:
	// 	fmt.Println("less than")
	// }

	// var inter interface{} = 1
	// switch inter.(type) {
	// case int:
	// 	fmt.Println("is int")
	// default:
	// 	fmt.Println("not int")
	// }

	// // for i:=0, j:=0; i<5;i++,j++{}// wont work
	// for i, j := 0, 0; i < 5; i, j = i+1, j+1 {
	// 	fmt.Println(i, j)
	// 	if i == 3 {
	// 		continue
	// 	}
	// 	if i == 4 {
	// 		break
	// 	}
	// }

	// arr := []int{3, 4, 5}
	// for idx, val := range arr {
	// 	fmt.Println(idx, val)
	// }

	// random2 := map[interface{}]interface{}{
	// 	1:    "rrr",
	// 	"rr": 1,
	// }
	// for idx, val := range random2 {
	// 	fmt.Println(idx, val)
	// }

	// str := "hello"
	// for idx, val := range str {
	// 	fmt.Println(idx, val, string(val))
	// }

	// //defer, panic, recover

	fmt.Println("without defer 1")
	defer fmt.Println("with defer 1") // it doesnt put it at the end of main function but after the main function returned
	defer fmt.Println("with defer 2")
	defer fmt.Println("with defer 3")
	defer fmt.Println("with defer 4") // stack
	fmt.Println("without defer 2")

	msg := "a"
	defer fmt.Println(msg)
	msg = "b"
    // will print a,  not b

    defer func(){
        if err:=recover(); err!=nil{
            fmt.Println(err)
        }
    }()
    panic("problem")
    // panic is called after defer

}
