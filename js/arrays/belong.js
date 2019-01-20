function getIndexToIns(arr, num) {
  arr.sort();
  for(let i in arr) {
    if (num < arr[i]) return i;
  }
  return arr.length;
}

let arr = [10, 20, 30, 40, 50];
let num = 30;
console.log(getIndexToIns(arr, num));