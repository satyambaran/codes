// //? class, function and new
// // class Car {
// // 	constructor(make, model, year) {
// // 		this.make = make;
// // 		this.model = model;
// // 		this.year = year;
// // 	}
// // }
// function Car(make, model, year) {
// 	this.make = make;
// 	this.model = model;
// 	this.year = year;
// }
// const car1 = new Car("Eagle", "Talon TSi", 1993);
// console.log(car1.make);
// const car2 = new Car("Eagle");
// console.log(car2);

// function Cycle(make, model, year) {
// 	this.make = make;
// 	this.model = model;
// 	this.year = year;
// 	return 5;
// }
// const cycle1 = new Cycle("Eagle", "Talon TSi", 1993);
// console.log(cycle1); //Cycle { make: 'Eagle', model: 'Talon TSi', year: 1993 }

// function Person(name, age, sex) {
// 	this.name = name;
// 	this.age = age;
// 	this.sex = sex;
// }
// const rand = new Person("Rand McNally", 33, "M");
// const ken = new Person("Ken Jones", 39, "M");
// function Bike(make, model, year, owner) {
// 	this.make = make;
// 	this.model = model;
// 	this.year = year;
// 	this.owner = owner;
// }
// const bike1 = new Bike("Eagle", "Talon TSi", 1993, rand);
// const bike2 = new Bike("Nissan", "300ZX", 1992, ken);
// console.log(bike1, bike2, bike2.owner.name);

// class Man {
// 	constructor(name) { //todo    The constructor method is called automatically when a new object is created.
// 		this.name = name;
// 	}
// 	greet() {
// 		console.log(`Hello, my name is ${this.name}`);
// 	}
// }

// const p = new Man("Satyam");
// p.greet(); // Hello, my name is Satyam
// //!
// //*
// //?
// //todo


class Car {
	constructor(brand) {
		this.carname = brand;
	}
	present() {
		return "I have a " + this.carname;
	}
}

class Model extends Car {           	//? extends keyword is used to create a child class, which  inherits all the methods from  prent
	constructor(brand, mod) {
		super(brand);  					//?  super keyword is used to call the constructor of its parent class to access the parent's properties and methods.

		//? If there is a constructor present in the subclass, it needs to first call super() before using "this".


		this.model = mod;
	}
	show() {
		return (
			this.present() +
			", I repeat, I have a " +
			this.carname +
			", it is a " +
			this.model +
			this.show
		);
	}
}

let myCar = new Model("Ford", "Mustang");
console.log(myCar.show());


class Rectangle {
	height = 0;
	width;
	#height = 0;
	#width;
	constructor(height, width) {
		this.#height = height;
		this.#width = width;
	}
}
