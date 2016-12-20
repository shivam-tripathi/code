function quicksort(arr) {
	if(arr.length <= 1)
		return arr;
	var pivot = arr[0];
	var left = [];
	var right = [];
	for(var i=1; i<arr.length; i++)
		if(arr[i] <= pivot)
			left.push(arr[i]);
		else
			right.push(arr[i]);
	left = quicksort(left);
	right = quicksort(right);
	return left.concat(pivot, right);
}

function main() {
	var numbers = [];
	for(var i = 0; i<10; i++){
		numbers[i] = Math.floor(Math.random()*100+1)
	}
	console.log(numbers);
	numbers = quicksort(numbers);
	var hello = [];
	hello.push(12);
	hello.push(45);
	hello.push(55);
	hello.push(5);
	console.log(numbers);
}

main();


// Don't forget to use var before variable declarations