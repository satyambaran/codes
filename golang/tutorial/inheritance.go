package main

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
    k:=3
	if k==5 {

	} else if k==4 {

	} else {

	}
}
