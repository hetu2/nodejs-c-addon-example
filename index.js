const fibonacciCc = require("./build/Release/fibonacciCc");
const hello = require("./build/Release/hello");

console.log(hello.world())

console.log("\n \n");
console.time();
const lastValueCc = fibonacciCc.execute();
console.log(lastValueCc)
console.timeEnd();
console.log("C++ time");
console.log("\n \n");

console.time()
const lastValueJs = fibonacciJS()
console.log(lastValueJs)
console.timeEnd()
console.log('NodeJS time')
console.log("\n \n");


function fibonacciJS() {
  let i;

  let t1 = 0
  let t2 = 1
  let nextTerm = 0

  for (i = 1; i <= 1000000; i++) {
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }

  return nextTerm

}
