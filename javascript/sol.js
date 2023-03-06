// const count = true;

// let countValue = new Promise(function (resolve, reject) {
//     if (count) {
//         resolve("There is a count value.");
//         resolve("There a count value.");
//     } else {
//         reject("There is no count value");
//     }
// });

// countValue
//     .then((message) => {
//         console.log(message);
//     })
//     .then(function (mes) {
//         console.log(mes);
//     })
//     .catch((err) => {
//         console.log(err);
//     })
//     .finally(function (msg) {
//         console.log(msg);
//     });
// // ########################################

let myPromise = new Promise(function (myResolve, myReject) {
    let x = 0;
    // x = 5;
    if (x == 0) {
        myResolve("OK");
    } else {
        myReject("Error");
    }
});
function myDisplayer(something = 5) {
    console.log(something);
}

myPromise
    .catch(function (error) {
        myDisplayer(error + "hfhdh");
    })
    .then(
        function (value) {
            myDisplayer(value + "10");
        },
        function (error) {
            myDisplayer(error);
        }
    );
// myPromise
//     .then(
//         function (value) {
//             myDisplayer(value);
//         },
//         function (error) {
//             myDisplayer(error);
//         }
//     )
//     .catch(function (error) {
//         myDisplayer(error + "hfhdh");
//     });
// // ########################################
// function myDisplayer(something = 5) {
//     console.log(something);
// }

// function myCalculator(num1, num2, funcCall, myCallback) {
//     let sum = num1 + num2;
//     funcCall;
//     myCallback(sum);
// }

// myCalculator(5, 5, myDisplayer(), myDisplayer);

// // ########################################

// // setInterval(myFunction, 5000);

// function myFunction() {
//     let d = new Date();
//     console.log(d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds());
// }

// // setTimeout(function () {
// //     myFunction();
// // }, 3000);

// let newPromise = new Promise(function (myResolve, myReject) {
//     setTimeout(function () {
//         myResolve("print something");
//     }, 3000);
// });
// newPromise.then((s) => {
//     myFunction();
// });

// ############################################

// async function foo(id) {
//     return new Promise(function (resolve, reject) {
//         let success = false;
//         let error = "yy";
//         if (success) {
//             return resolve(success);
//         } else {
//             return reject(error);
//         }
//     });
// }

// async function bar() {
//     try {
//         var result = await foo("someID");
//         console.log(result);
//     } catch (error) {
//         console.log(error);
//     }
// }

// // await bar();
// bar();

// async function myFunction() {
//     // throw new Error("ttt");
//     return "Hello";
// }
// myFunction()
//     .then(function (value) {
//         console.log(value);
//     })
//     .catch((val) => {
//         console.log(val, "rejected");
//     });
// ##################################

// class Car {
//     constructor(name) {
//         this.name = name;
//     }
//     static hello(x) {
//         return "Hello " + x.name;
//     }
// }
// let myCar = new Car("Ford");
// console.log(Car.hello(myCar));
// ###################################
// class Car {
//     constructor(brand) {
//         this._carname = brand;
//     }
//     get carname() {
//         return this._carname;
//     }
//     set carname(x) {
//         this._carname = x;
//     }
// }

// let myCar = new Car("Ford");
// console.log(myCar._carname, myCar.carname);

// ##########################################

// class Car {
//     constructor(brand) {
//         this.carname = brand;
//     }
//     present() {
//         return "I have a " + this.carname;
//     }
// }

// class Model extends Car {
//     constructor(brand, mod) {
//         super(brand);
//         this.model = mod;
//     }
//     show() {
//         return (
//             this.present() +
//             ", I repeat, I have a " +
//             this.carname +
//             ", it is a " +
//             this.model +
//             this.show
//         );
//     }
// }

// let myCar = new Model("Ford", "Mustang");
// console.log(myCar.show());

function inventoryList() {
    let obj = {
        list: [],
        add: function (str) {
            this.list.push(str);
        },
        remove: function (str) {
            let index = this.list.indexOf(str)
            if (index != -1) {
                this.list.splice(index, 1)
            }
        },
        getList: function () {
            return String(this.list)
        }
    }
    return obj;
}

//? testing after here
let ans = inventoryList()

ans.add('satyam')
console.log(ans.getList())
ans.add('kundan')
console.log(ans.getList())
ans.add('chandan')
console.log(ans.getList())
ans.remove('chandan')
console.log(ans.getList())
ans.remove('abhilash')
console.log(ans.getList())


const http = require('http')
let k = http.createServer((req, res) => {
    let url = req.url
    req.method
    res.setHeader("Content-Type", "application/json");
    if (!url.startsWith('/project/')) {
        res.statusCode = 400
        let ret = {
            status: false,
            message: "BAD REQUEST"
        }
        res.end(JSON.stringify(ret))
    } else {
        let stringSplit = url.split("/project/")
        let dataArray = []
        if (dataArray.includes(stringSplit[1])) {

        } else {

        }
    }
})
k.listen(8000)
