package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

func main() {
	// Create a Person struct
	person := Person{Name: "John Doe", Age: 30}

	// Marshal the struct to a JSON-encoded byte slice
	jsonData, err := json.Marshal(person)
	if err != nil {
		fmt.Println("Error marshalling JSON:", err)
		return
	}
	fmt.Println(string(jsonData))

	// Unmarshal the JSON-encoded byte slice to a new Person struct
	var newPerson Person
	err = json.Unmarshal(jsonData, &newPerson)
	if err != nil {
		fmt.Println("Error unmarshalling JSON:", err)
		return
	}
	fmt.Printf("Name: %s, Age: %d\n", newPerson.Name, newPerson.Age)
}
