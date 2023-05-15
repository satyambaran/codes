// You can edit this code!
// Click here and start typing.
package main

import "fmt"

func swap(a *int, b *int) {
    *a, *b = *b, *a
}
func main() {
    fmt.Println("Hello, 世界")
    a := 1
    b := 2
    swap(&a, &b)
    fmt.Println(a, b)

    const c = 5

    // Golang doesn't have the inheritance concept. But to support code reuse and polymorphism functionality, it provides a composition, embedding, and interfaces.

    // Go does not have optional parameters, nor does it support method overloading.
    //
}
