'use strict';

function replace(str) {
    for(let c in str) {
        // pass
    }
}

function reverseString(str) {
    let l = 0, r = str.length - 1;
    console.log(l, ' -- ', r);
    let revStr = '';
    while(r >= l) {
        revStr += str[r];
        console.log(str.length-r, "  ", revStr);
        r--;
    }
    console.log(str);
    return revStr;
}

function reverseString2(str) {
    return str.split('').reverse().join('');
}

let str = "abcdefghijk";
console.log(reverseString(str));

const reverse = (str) => {
    if (str == "") {
        return str;
    }

    return reverse(str.slice(1,)) + str[0];
}

console.log(reverse(str));

// let x = new func();
// console.log(this.checkList);
// console.log('List checklist :: ', list.checkList);
// console.log(this.track);
// try {
//     console.log(track);
// } catch(err) { console.log('Node defined ===> track');}