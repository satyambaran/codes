const count = Math.random() > 0.5;

let countValue = new Promise(function (resolve, reject) {
    if (count) {
        resolve("greater than 0.5");
        resolve("will not get triggered "); //? can't resolve twice
    } else {
        reject("less than 0.5");
    }
});

countValue
    .then((message) => {
        console.log(message);
    })
    .then(function (mes) {
        console.log(mes);
    })
    .catch((err) => {
        console.log(err);
    })
    .finally(function (msg) {
        console.log(msg);
    });

//? order  and existence of then, catch and  finally doesnt matter (as long as at least one of them is there)


function myDisplayer(anything) {
    console.log(anything);
}
function myCalculator(num1, num2, myCallback) {
    let sum = num1 + num2;
    myCallback(sum);
}
myCalculator(5, 5, myDisplayer);


setTimeout(callbackFun, 300);

function callbackFun() {
    console.log("ToBeExecAfterTimeout");
}

// setInterval(myFunction, 1000);
// function myFunction(){
//     console.log("to be executed after every second")
// }


//? Promise object supports two properties: state and result
// myPromise.state	    myPromise.result
// "pending"	        undefined
// "fulfilled" 	        a result value
// "rejected"	        an error object

let myPromise = new Promise(function (resolve, reject) {
    if (Math.floor(Math.random() * 2)) {
        resolve("greater than 1")
    } else {
        reject("less than 1")
    }
})

myPromise.then(function (val) { console.log(val) }).catch(function (val) { console.log(val) })

myPromise.then(function (val) { console.log(val) }, function (val) { console.log("rej", val) }).catch(function (val) { console.log(val) })  //todo     .catch wont get executed because second parameter of then will be act as catch


async function asyncFunction() {
    throw "Hello"
    return "Hello";
}
asyncFunction().then(
    function (value) { console.log(value) },
    function (error) { console.log(error, "error"); }
);

async function useAwait() {
    return await asyncFunction();
}
useAwait().then(function () {
    console.log("sss");
}).catch(function () {
    console.log("fff");
})

async function asyncReturningPromise(id) {
    return new Promise(function (resolve, reject) {
        let success = false;
        let error = "yy";
        if (success) {
            return resolve(success);
        } else {
            return reject(error);
        }
    });
}
let k = asyncReturningPromise().then((val) => {
    console.log(val);
    return val;
}).catch((val) => {
    console.log(val);
    return val;
})


// async makes a function return a Promise

// await makes a function wait for a Promise
// await keyword can only be used inside an async function.
// await keyword makes the function pause the execution and wait for a resolved promise before it continues