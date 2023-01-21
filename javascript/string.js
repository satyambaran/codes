let text = "AppleBananaKiwi";
let length = text.length;
let part = text.slice(7);
let part1 = text.slice(7, 13);
let part2 = text.slice(-12); // counting from back
let part3 = text.slice(-12, -6);
console.log(part, part1, part2, part3);

//todo    substring(start, end)
//todo    substr(start, length)


let newText = text.replace("na", "ma"); // only replace the first match
console.log(newText); // AppleBamanaKiwi

let x = 123e5;    // 12300000
let y = 123e-5;   // 0.00123
// JavaScript Numbers are Always 64-bit Floating Point
x = 0.2 + 0.1; // 0.30000000000000004
x = (0.2 * 10 + 0.1 * 10) / 10; //0.3
let myNumber = 2;
// Execute until Infinity
while (myNumber != Infinity) {
    myNumber = myNumber * myNumber;
}

let newNum = 31;
console.log(newNum.toString(2));// converts to binary
console.log(newNum.toString(16)); // converts to hexa decimal
console.log(newNum.toString(8).toString(4));
console.log(newNum.toExponential())


x = Number(" 10  ") //10
x = parseInt("-10.33") //-10
x = parseFloat(" -10.33 ") // -10.33
x = parseInt("10 years") //10
x = parseInt("years 10") //NaN



let cars = [];
cars[2] = "BMW";
cars[0] = "Saab";
console.log(cars)   // ['Saab', <1 empty item>, 'BMW' ]
cars = new Array("Saab", "Volvo", "BMW")
console.log(cars.length, cars[-1]/**undefined */)

//?
cars.forEach(myFunction); // forEach() method calls a function (a callback function) once for each array element
function myFunction(val) {
    console.log(val)
}
cars.push("rajdoot")

console.log(cars.join(" * "))
let car = cars.pop(); //todo     delete and return from end, can do same thing from front using 'shift'
//todo               pop   <--->  shift 
//todo               push  <--->  unshift 
console.log(car)

cars.sort();
console.log(cars)
cars.reverse();
console.log(cars)

const numArr = [40, 100, 1, 5, 25, 10];
numArr.sort(function (a, b) { return Math.sqrt(b) % 10 - Math.sqrt(a) % 10 });

let numArr1 = numArr.map(func)
console.log(numArr, numArr1)
numArr1 = numArr.map((val) => {
    return 3 * val;
})
let over18 = numArr.filter((val) => {
    return val > 18;
});
console.log(numArr, numArr1, over18)
function func(val) {
    return 2 * val
}


console.log(Math.max.apply(null, numArr), Math.min.apply(null, numArr), numArr.includes(1000))


for (let x of numArr) { console.log(x) }; // 40, 25, 10, 5, 1, 100 // for of statement loops through the values of an iterable object
for (let x in numArr) { console.log(x) }; // 0,1,2,3   //for in statement loops through the properties of an Object
let entries = numArr.entries()
for (let x of entries) { console.log(x) }

//? break, continue, 


const letters = new Set(["b"]);
letters.add("a");
console.log(letters.has("b"))


const fruits = new Map([
    ["apples", 500],
    ["bananas", 300],
    ["oranges", 200]
]);
fruits.set("apples", 200);
fruits.set("papaya", 200);
fruits.get("apples");
fruits.delete("apples");



//? regexp ?//


//? regexp ?//


// // The try statement allows you to define a block of code to be tested for errors while it is being executed.

// // The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.
// try {
//     // Block of code to try
//     //? throw "Too big";    // throw a text 
//     //? throw 500;          // throw a number
//     throw new Error("was in try, in catch now");
// }
// catch (err) {
//     console.log(err)
//     // Block of code to be executed, if an error occurs in the try block.
// }
// finally {
//     // Block of code to be executed regardless of the try / catch result
// }


//! types of error
// RangeError	    if you use a number that is outside the range of legal values //? num.toPrecision(500);   // A number cannot have 500 significant digits
// ReferenceError	//? An illegal reference has occurred,  if you use (reference) a variable that has not been declared
// SyntaxError	    //? if you try to evaluate code with a syntax error
// TypeError	   //? if you use a value that is outside the range of expected types       let num = 1; num.toUpperCase();  // You cannot convert a number to upper case



//! scope
// Block scope
// Function scope  //? Each function creates a new scope.
// Global scope

//! this
let thi = this; //When used alone, this refers to the global object.
console.log("this ", thi)


//todo      In an object method, this refers to the object.
//todo      Alone, this refers to the global object.
//todo      In a function, this refers to the global object.
//todo      In a function, in strict mode, this is undefined.
//todo      In an event, this refers to the element that received the event.


const person = {
    firstName: "John",
    lastName: "Doe",
    id: 5566,
    fullName: function () {
        return this.firstName + " " + this.lastName;
    },
    fun: () => {
        return this.firstName + " " + this.lastName;
    },
    fun2: function myFunction() {
        return this;
    },
    obj: this
};
console.log(person.fullName(), person.fun(), person.fun2().id, person.obj/** we received global this */) //? John Doe undefined undefined 5566 {}


// With the bind() method, an object can borrow a method from another object.
const person1 = {
    firstName: "a",
    lastName: "b",
    fullName: function () {
        return this.firstName + " " + this.lastName;
    }
}
const person2 = {
    firstName: "c",
    lastName: "d",
}
console.log(person1.fullName(), "     ", person1.fullName.call(person2), "     ", person1.fullName(person2));
// a b       c d       a b

let hello = () => {
    return "Hello World!";
}
hello = function () {
    return "Hello World!";
}

// In regular functions the this keyword represented the object that called the function

// With arrow functions the this keyword always represents the object that defined the arrow function.


