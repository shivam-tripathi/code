/*
Consider head and tails as nodes too.
Don't forget "this" keyword with data members and member functions.
*/

function Node(element) {
	this.element = element;
	this.prev = null;
	this.next = null;
}

function DList() {
	this.head = new Node("head");
	this.tail = new Node("tail");
	this.head.next = this.tail;
	this.tail.prev = this.head;

	this.find = find;
	this.push_front = push_front;
	this.push_back = push_back;
	this.display_front = display_front;
	this.display_back = display_back;
	this.insert = insert;
	this.remove = remove;
}

function find(item) {
	var curNode = this.head;
	while(curNode != this.tail && curNode.element != item) {
		curNode = curNode.next;
	}
	if(curNode == this.tail) {
		console.log("Item not found");
		return null;
	}
	return curNode;
}

function display_front() {
	var curNode = this.head.next;
	while(curNode != this.tail) {
		console.log(curNode.element);
		curNode = curNode.next;
	}
}

function display_back() {
	var curNode = this.tail.prev;
	while(curNode != this.head) {
		console.log(curNode.element);
		curNode = curNode.prev;
	}
}

function push_back(item) {
	var temp = new Node(item);
	var curNode = this.tail.prev;
	curNode.next = temp;
	temp.prev = curNode;
	temp.next = this.tail;
	this.tail.prev = temp;
}

function push_front(item) {
	var temp = new Node(item);
	var curNode = this.head.next;
	this.head.next = temp;
	temp.prev = this.head;
	temp.next = curNode;
	curNode.prev = temp;
}

function insert(newElement, item) {
	var curNode = this.find(item);
	if (curNode == null) return;
	var temp = new Node(newElement);
	curNode.next.prev = temp;
	temp.prev = curNode;
	temp.next = curNode.next;
	curNode.next = temp;
}

function remove(item) {
	var curNode = this.find(item);
	if(curNode == null) {
		console.log(item, "cannot remove");
		console.log();
		return;
	}
	var temp = curNode.prev;
	temp.next = curNode.next;
	curNode.next.prev = temp;
}

function main() {
	var cities = new DList();
	cities.insert("Conway", "head");
	cities.insert("Russellville", "Conway");
	cities.insert("Carlisle", "Russellville");
	cities.insert("Alma", "Carlisle");

	cities.display_front();
	console.log();
	cities.display_back();
	console.log();

	cities.remove("Carlisle");
	cities.remove("Alma");
	cities.push_back("Lucknow");
	cities.push_front("Hamirpur");
	cities.display_front();
	console.log();
	cities.display_back();
}

main();