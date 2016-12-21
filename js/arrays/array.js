/*
Arrays in Javascript are very different from other languages. It is a specialized object, where
indices are keys with associated values.
*/

var numbers = [1,2,3,4,5];
var digits = new Array(10);
console.log(numbers.length);
console.log(digits.length);
console.log(digits);

digits = new Array(1,2,3,4,5);
console.log(digits);

// The arrays can have different datatypes stored
// It is better to use [] operator as it gives the best results
var num = 10;
console.log(Array.isArray(num));
console.log(Array.isArray(numbers));
console.log(Array.isArray(digits));

var sentence = "the quick brown fox jumped over the lazy dog";
var words = sentence.split(" ");
for (var i = 0; i < words.length; ++i) {
console.log("word",i,":",words[i]);
}

// Assignment to another array is based on reference - shallow copying.
// Deep copying means we will have to copy all the elements one by one

var index = words.indexOf("fox");
console.log("",index, ":", words[index]);

/*
indexOf()
lastIndexOf()
*/

// String representation : join() and toString() - toString() will always give comma delimited values
var names = ["David", "Cynthia", "Raymond", "Clayton", "Mike", "Jennifer"];
var namestr = names.join(" ");
console.log(namestr);
namestr = names.toString();
console.log(namestr);

/*
concat() joins two arrays
splice() cuts the array and returns the part of the array cut, while array is reduced to it's remaining part
*/
console.log(numbers.concat("inserting", names, names)); // Can add as many stuff as we want

var copy = numbers.splice(2,3);
console.log(copy, numbers);

/*
push(item) and arr.[arr.length] = item
unshift(n1, n2, n3) : add items to the beginning of the array
*/
numbers.push(3,4,5);
numbers.unshift(-1,0);
console.log(numbers);


/*
pop()
shift()
*/
numbers.pop();
numbers.shift()
console.log(numbers);
console.log();


// splice(index_where_to_add, no_of_elements_to_remove, items_to_be_added)
var nums = [1,2,3,7,8,9];
nums.splice(3,0,4,5,6); // same result by var addElem = [4,5,6] and nums.splice(3,0,addElem)
console.log(nums);

nums.splice(6, 2, 23, 45);
console.log(nums);

// Removing element(s) at an index
nums.splice(6, 1);
console.log(nums);

console.log(nums.reverse());
// Sort function sorts according to lexicographical ordering, so it can't be used directly with numbers
console.log(nums.sort());
// This drawback can be overcome by using compare function which is passed to the sort function
function cmp(x, y){
	return x - y;
}
console.log(nums.sort(cmp));
console.log();


/*
Iterator (similar to functional programming languages)
	arr.forEach(function)
	arr.every(function) => return true if function returns for each element of the array
	arr.some(function) => return true if function return true for some elements of the array
	arr.map(function) => returns a new array made up of the return from the function over the elements
	arr.reduce(function) => iterators over each value of the array and returns total operated value
	arr.filter(function)
*/
var sum = 0;
nums.forEach(function(x) {sum += x*x; console.log(x, x*x);});
console.log("Sum=", sum);

// Note the return value
console.log(nums.reduce(function(sum, x) {return sum + (x*x);}));

if(nums.every(function(x) {return (x%2 == 0);}))
	console.log("All elements are even");
else
	console.log("All elements are not even");

console.log(nums.map(function(x) {return x*x;}));

console.log(nums.filter(function(x){return (x%2!=0);}));

/*
Multi dimensional arrays
*/

Array.matrix = function(rows, cols, initial) {
	var arr = [];
	for(var i=0; i<rows; i++) {
		var columns = []
		for(var j=0; j<cols; j++) {
			columns[j] = initial;
		}
		arr[i] = columns;
	}
	return arr;
}



var two_arr = new Array.matrix(5, 3, null);
console.log(two_arr);