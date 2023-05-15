package main

import (
	"fmt"
	"math"
)

type Writer interface {
	Write([]byte) (int, error)
}

func main() {

	// in case of methods
	// if user is &/pointer type, it'll be using all the methods
	// but if user is value type, it'll be using only value method type func(c structName)funcName()(){}

	// empty interface
	var myObj interface{} = 0
	myObj = "0"
	fmt.Println(myObj)
	switch myObj.(type) {
	case int:
		fmt.Println("int")
	case string:
		fmt.Println("string")
	case float64:
		fmt.Println("float64")
	default:
		fmt.Println("Dont know")

	}
	// have no methods on it
	//every type can be cast into empty interface{} that has no methods

	// we can embed multiple interface in one interface

	var c1 Shape = Circle{2.0}
	var c2 Circle = Circle{2.1}
	var c3 Everything = Circle{2.2}
	var r1 Shape = Rectangle{2.0, 2.1}
	var r2 Rectangle = Rectangle{2.2, 2.3}
	var r3 Everything = Rectangle{2.2, 2.3}
	shapeList := []Shape{c1, c2, r1, r2, c3, r3}
	everythingList := []Everything{c2, c3, r2, r3} //? c1 and r1 are not accepatble here since already are a variable of type Shape

	for _, val := range shapeList {
		area, _ := val.area()
		perimeter, _ := val.perimeter()
		fmt.Println(area, perimeter, val)
	}
	for _, val := range everythingList {
		area, _ := val.area()
		perimeter, _ := val.perimeter()
		diagonal, _ := val.diagonal()
		fmt.Println(area, perimeter, diagonal, val)
	}
}

type Circle struct {
	radius float64
}

type Rectangle struct {
	height float64
	width  float64
}

type Shape interface {
	area() (float64, error)
	perimeter() (float64, error)
}
type Diagonal interface {
	diagonal() (float64, error)
}
type Everything interface {
	Shape
	Diagonal
}

func (c Circle) area() (float64, error) {
	return math.Pi * c.radius * c.radius, nil
}

func (c Circle) perimeter() (float64, error) {
	return math.Pi * c.radius * 2, nil
}
func (c Circle) diagonal() (float64, error) {
	return c.radius * 2, nil
}
func (r Rectangle) area() (float64, error) {
	return r.height * r.width, nil
}
func (r Rectangle) perimeter() (float64, error) {
	return 2 * (r.height + r.width), nil
}

func (r Rectangle) diagonal() (float64, error) {
	return math.Sqrt(math.Pow(r.height, 2) + math.Pow(r.width, 2)), nil
}
