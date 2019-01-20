// function test(arr) {
//     arr.push(1212);
//     arr.unshift(333);
// }

// let arr = ["claw", "tentacle"];
// test(arr);
// console.log(arr);


function frankenSplice(arr1, arr2, n) {
    let arr = arr2.slice(0, n);
    console.log(arr);
    let rem = arr2.slice(n);
    console.log('arr1  ', arr1, ' rem ', rem);
    arr = arr.concat(arr1);
    console.log(arr);
    arr = arr.concat(rem);
    console.log(arr);
    return arr;
}

console.log(frankenSplice([1, 2, 3], [4, 5, 6], 1));


function getParent(x) {
    return Math.floor(x-1)/2;
}

function getLeftChild(x) {
    return (2*(i+1));
}

function getRightChild(x) {
    return (2*(i+2));
}

let arr = []