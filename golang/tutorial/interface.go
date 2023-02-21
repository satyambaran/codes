package main

import (
	"fmt"
	"math"
)

// struct describes data
// interface describes behaviour of struct or any other custom type

// with written definition of all the behaviours, we dont need interface but for the sanity purpose(so that struct all contain these properties) we must keep interface definition

type Writer interface {
	Write([]byte) (int, error)
	Read([]byte) (int, error)
}

type consoleWriter struct{}

func (cw consoleWriter) Write(byt []byte) (int, error) {
	n, err := fmt.Println(string(byt))
	return n, err
}

func (cw consoleWriter) Read(byt []byte) (int, error) {
	n, err := fmt.Println(string(byt))
	return n, err
}

type IntCounter int
type Incrementer interface {
	Increment() int
}

func (ic *IntCounter) Increment() int {
	(*ic)++
	return int((*ic))
}

func main() {
	var w Writer = consoleWriter{} //? to write this way, just like virtual function in c++, all behaviours in Writer interface must be overridden by consoleWriter
	x := consoleWriter{}
	a, b := w.Write([]byte("Hello"))
	fmt.Println(a, b)
	a, b = x.Write([]byte("Hello"))
	fmt.Println(a, b)
	//?  cannot use (consoleWriter literal) (value of type consoleWriter) as Writer value in variable declaration: consoleWriter does not implement Writer (missing method Write)
	// above error is produced when we dont implement  func (cw consoleWriter) Write(byt []byte) (int, error)

	myInt := IntCounter(0)
	var inc *IntCounter = &myInt
	for i := 0; i < 10; i++ {
		fmt.Println(inc.Increment())
	}

	var c1 Shape = Circle{2.0}
	var c2 Circle = Circle{2.1}
	var r1 Shape = Rectangle{2.0, 2.1}
	var r2 Rectangle = Rectangle{2.2, 2.3}
	shapeList := []Shape{c1, c2, r1, r2}

	for _, val := range shapeList {
		area, _ := val.area()
		perimeter, _ := val.perimeter()
		fmt.Println(area, perimeter, val)
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

func (c Circle) area() (float64, error) {
	return math.Pi * c.radius * c.radius, nil
}

func (c Circle) perimeter() (float64, error) {
	return math.Pi * c.radius * 2, nil
}
func (r Rectangle) area() (float64, error) {
	return r.height * r.width, nil
}
func (r Rectangle) perimeter() (float64, error) {
	return 2 * (r.height + r.width), nil
}
