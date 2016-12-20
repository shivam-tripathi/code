/*
Arrays in javascript are not fixed length, and can is it easy to remove elements or add then in the
middle of the arrays, but the implementation is not as efficient as of those in traditional languages
like C++ as the arrays in javascript are internally objects.
Operations on an array may be very slow, so we may need linked lists.
*/

function Node (element) {
	this.element = element;
	this.next = null;
}

function LList() {
	this.head = new Node("head");
	this.find = find;
	this.insert = insert;
	this.push_back = push_back;
	this.remove = remove;
	this.display = display;
}

function find(item) {
	var curNode = this.head;
	while(curNode != null && curNode.element != item) {
		curNode = curNode.next;
	}
	if (curNode == null) console.log("Item not found");
	else return curNode;
}

function insert(newElement, item) {
	var newNode = new Node(newElement);
	var current = this.find(item);
	if(current == null) return;
	newNode.next = current.next;
	current.next = newNode;
}

function push_back(item) {
	var curNode = this.head;
	while(curNode.next != null) {
		curNode = curNode.next;
	}
	curNode.next = new Node(item);
}

function display() {
	var curNode = this.head.next;
	while(curNode != null) {
		console.log(curNode.element);
		curNode = curNode.next;
	}
}

function remove(item) {
	var curNode = this.head;
	while(curNode != null) {
		if(curNode.next.element == item)
			break;
		curNode = curNode.next;
	}
	if(curNode == null) console.log("Element not found");
	else {
		curNode.next = curNode.next.next;
	}
}


function main() {
	var cities = new LList();
	cities.insert("Conway", "head");
	cities.insert("Russellville", "Conway");
	cities.insert("Alma", "Russellville");
	cities.push_back("Lucknow");
	cities.display()
	cities.remove("Alma");
	console.log("-----------");
	cities.display();
}

main();

/*
Javascript has a garbage collector, so there is no need to explicitly declare object undefined to
free them.
*/