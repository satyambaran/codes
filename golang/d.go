// package main

// import (
// 	"fmt"
// 	"time"
// )

// type InComing struct {
// 	// MobileNumber string `json:"mobileNumber"`
// 	Amount      string `json:"amount`
// 	SIPAmount   string `json:"sip_amount`
// 	UPIId       string `json:"upi"`
// 	ProductInfo string `json:"product"`
// 	ChitsGoalId string `json:"chitsGoalId"`
// 	MerchandId  string `json:"merchandId"`
// }

// type hellofun func()

// func hello() {
// 	fmt.Println("Hello world!")
// }
// func hello2() {
// 	fmt.Println("Hello world!")
// }

// func greet(k hellofun) {
// 	k()
// 	defer fmt.Println("World")
// 	fmt.Println("Hello")
// 	time.Sleep(1 * time.Second)
// 	defer fmt.Println("World2")
// }
// func main() {
// 	// encodeDetails := jwt.MapClaims{
// 	// 	"user_id": "user_id",
// 	// 	"exp":     "unixTime",
// 	// 	"source":  "source",
// 	// }
// 	// fmt.Println(reflect.TypeOf(encodeDetails))
// 	// token := jwt.NewWithClaims(jwt.SigningMethodHS256, encodeDetails)

// 	// fmt.Println(token)
// 	// secret := "secret"
// 	// key := []byte(secret)
// 	// tokenString, _ := token.SignedString(key)
// 	// fmt.Println("tokenString", tokenString)
// 	// tokenParts := strings.Split(tokenString, ".")
// 	// fmt.Println(tokenParts)

// 	// retPart, _ := base64.StdEncoding.DecodeString(tokenParts[0])
// 	// fmt.Println(string(retPart))

// 	// retPart1, _ := base64.StdEncoding.DecodeString(tokenParts[1])
// 	// fmt.Println(string(retPart1))

// 	// retPart2, _ := base64.StdEncoding.DecodeString(tokenParts[2])
// 	// fmt.Println(string(retPart2))

// 	// go hello()
// 	// defer fmt.Println("World3")
// 	// greet(hello2)
// 	// defer fmt.Println("World4")
// 	k := []int{}
// 	k = append(k, 5)
// 	fmt.Println(k[0])
// 	for i, j := range k {
// 		fmt.Println(i, j)
// 	}
// 	// mp := map[string]string{}
// 	// mp["44"] = "yes"
// 	var mp map[string]string

// 	for k, i := range mp {
// 		fmt.Println(k, i)
// 	}
// 	if val, ok := mp["44"]; ok {
// 		fmt.Println(val, ok)
// 	}
// }

package main

import (
	"fmt"
)

type Body struct {
	Msg interface{}
}
type Empty interface {
}
type Program struct {
	Name string
}

func main() {
	c := Body{}
	c.Msg = "5"
	fmt.Printf("%#v %T %v \n", c.Msg, c.Msg, c.Msg) // Output: "5" string
	c.Msg = 5
	fmt.Printf("%#v %T \n", c.Msg, c.Msg) //Output:  5 int

	var a Empty
	a = 5
	a = 6.5
	a = "hello"
	a = Program{}
	fmt.Println(a)

	var b interface{}
	b = a
	b = 9
	b = "bye"
	b = Program{}
	fmt.Println(b)
}
