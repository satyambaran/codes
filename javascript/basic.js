// A computer program is a list of /* instructions to be executed */ by a computer.
// In a programming language, these programming instructions are called statements.
// A JavaScript program is a list of programming statements.

// !const, let & var

//? var is function scoped when it is declared within a function
// var is global scoped when declared outside of function
var tester = "hey hi";
function newFunction() {
	var hello = "hello";
}
//todo console.log(hello); // error: hello is not defined

//* var variables can be re-declared and updated in the same scope
var greeter = "declared";
var greeter = "re-dclared";
greeter = "updated";

var carName = "Volvo";
var carName;
console.log("carName", carName);

// Hoisting is a JavaScript mechanism where variables and function declarations are moved to the top of their scope before code execution.
// so
console.log(greeter);
var greeter = "say hello";
// is equivalent of this
var greeter;
console.log(greeter); // greeter is undefined
greeter = "say hello";

//? let is block scoped, which can be updated but not re-declared

//todo console.log(msg); // Cannot access 'msg' before initialization
let msg = "let doesnt work this way";

//? const declarations are block scoped which cannot be updated or re-declared
const greeting = "say Hi";
//todo greeting = "say Hello instead";// error: Assignment to constant variable.
//todo const greeting = "say Hello instead";// error: Identifier 'greeting' has already been declared

// const PI; //'const' declarations must be initialized.ts(1155)
//? CAN: Change the elements of constant array
//? CAN: Change the properties of constant object
const cars = ["Saab", "Volvo", "BMW"];
cars[0] = "Toyota";
cars.push("Audi");
// cars = ["Toyota", "Volvo", "Audi"];    // ERROR
let k = cars.pop();
console.log(k);

const constExample = {
	message: "say Hi",
	times: 4,
};
/*constExample = { //todo Assignment to constant variable.
	words: "Hello",
	number: "five",
};  */

constExample.number = "five";
constExample.times = { week: 4 };
delete constExample.message;
console.log(constExample);

//? const let & var are all hoisted to the top of their scope. But while var variables are initialized with undefined, let and const variables are not initialized.

let str = "11";
console.log(
	str + "1", // 111
	str + 1, // 111
	str - 1, // 10
	str * 2, // 22
	str + str, // 1111
	2 * str, //22
	"5" + 2 + 3, //523
	2 + "5" + 3 //253
);

console.log("1" === 1, "1" !== 1, "1" == 1, "1" != 1);
// false true true false    strtict equality/inequality

let num = 5;
console.log(3 ** 2, ++num, num++, num, --num, num--, num);
let text = "happy ";
text += "new year";
console.log(text);

//? null : null value represents the absence of any object value //treated as false
console.log(typeof null, typeof undefined);

const a = { duration: 50 };
a.speed = a.speed ?? 25; //* nullish coalescing, check if null or undefined
a.duration = a.duration ?? 10;
console.log(a.duration, a.speed);
const foo = null ?? "default string";
console.log(foo);

// https://developer.mozilla.org/en-US/docs/Web/JavxaScript/Reference/Operators/Object_initializer

const adventurer = {
	name: "Alice",
	cat: {
		name: "Dinah",
	},
	fun: (val) => {
		console.log("fun is printing", val, this.name/** undefined */);
	},
	fullName: function () {
		return this.name;
	}
};
const dogName = adventurer.dog?.name;  // Operator chaining
let fun = adventurer.fun
console.log(dogName, adventurer.fun?.(5), fun?.(5), adventurer.someNonExistentMethod?.());
// The () Operator Invokes the Function

let nameObj = {
	certName: "Satyam",
	homeName: "Kundan",
	surname: "Barnwal",
	rashiName: "Naurang",
};
let strList = ["satyam", "kumar", "barnwal"]
console.log(strList?.[4], strList?.includes("kundan"), nameObj?.["certName"]);


//? Datatypes
// String, Number, Bigint, Boolean, Undefined, Null, Symbol, Object(object, array, Date)

let x = new String("John");  // x is an object
let y = new String("John");  // y is an object
let z = "John"
console.log(x === y, y == z);
//? Comparing two JavaScript objects always returns false.
x = {
	"f": "u",
	"s": "u"
}
y = {
	"f": "u",
	"s": "u"
}
console.log(x == y); //  false


console.log(Math.random())

let xss =
	(![] + [])[+[]] +
	(![] + [])[+!+[]] +
	([![]] + [][[]])[+!+[] + [+[]]] +
	(![] + [])[!+[] + !+[]];
console.log(xss)