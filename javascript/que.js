var URL = require('url').URL;
const myURL = new URL('https://example.org:8888');
console.log(myURL.port);
myURL.port = '443';
console.log(myURL.port);
myURL.port = 1234; console.log(myURL.port);
console.log(myURL.href);
myURL.port = 'abcd';
console.log(myURL.port);
myURL.port = '5678abcd';
console.log(myURL.port);
myURL.port = 1234.5678; console.log(myURL.port);
console.log(myURL.href);