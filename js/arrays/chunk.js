function chunkArrayInGroups(arr, size) {
    let retarr = [];
    let index = 0;
    while(index < arr.length) {
        console.log('idx =', index, ' slicedarr = ', arr.slice(index, size));
        retarr.push(arr.slice(index, index+size));
        index = index+size;
    }
    return retarr;
}

let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8];
console.log(chunkArrayInGroups(arr, 2));