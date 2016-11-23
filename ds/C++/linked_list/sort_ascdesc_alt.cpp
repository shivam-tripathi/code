// www.geeksforgeeks.org/how-to-sort-a-linked-list-that-is-sorted-alternating-ascending-and-descending-orders/

#include <bits/stdc++.h>
using namespace std;

// *************************************************************************************************
// Boiler plate code

class Node {
public:
	int val;
	Node *next;
	Node(int v) {
		val = v;
		next = NULL;
	}
};

class List {
public:
	Node *head;
	Node *tail;
	Node *temp;
	List() {
		head = tail = NULL;
	}
	void push_back(int val) {
		temp = new Node(val);
		if(head == NULL)
			head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
			tail->next = NULL;
		}
	}
	void push_front(int val) {
		temp = new Node(val);
		if(head == NULL) 
			head = tail = NULL; 
		else {
			temp->next = head;
			head = temp;
		}
	}
	// ********************************************************************************************
	// * Reverse code can slow you down, so be a little cautious; plus you make terrible mistakes *
	// ********************************************************************************************
	void reverse() { 
		if (head == NULL || head == tail) return;
		temp = head->next;
		Node *prev = head;
		Node *buf;
		while(prev != tail) { // (!temp) {
			buf = temp->next;
			temp->next = prev;
			prev = temp;
			temp = buf;
		}
		head->next = NULL;
		swap(head, tail);
	}

	void print() {
		if(head == NULL) return;
		temp = head;
		while(temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

// *************************************************************************************************
// Initialization code
void initialize (List &llist, int size) {
	srand(time(NULL));
	vector<int> one;
	vector<int> two;
	for(int i=0; i<size; i++) {
		one.push_back(rand()%100);
		two.push_back(rand()%100);
	}	

	sort(one.begin(), one.end());
	// sort(two.rbegin(), two.rend());
	sort(two.begin(), two.end(), std::greater<int>()); // Better to use this

	for(int i=0; i<size; i++) {
		llist.push_back(one[i]);
		llist.push_back(two[i]);
	}
}


// Merge code 
List* merge(const List &a, const List &b) {
	List *temp = new List;
	Node *nodea = a.head, *nodeb = b.head; // Common mistake of not making them Node *
	bool flag = false;
	while(true) {
		if(nodea == NULL && nodeb == NULL) break;
		else if(nodea != NULL && nodeb == NULL) {
			flag = true;
			break;
		} 
		else if(nodea == NULL && nodeb != NULL) {
			swap(nodea, nodeb);
			flag = true;
			break;
		}

		if(nodea->val < nodeb->val){
			// cout << "Pushed(a) " << nodea->val << endl;
			temp->push_back(nodea->val);
			nodea = nodea->next;
		} else {
			// cout << "Pushed(b) " << nodeb->val << endl;
			temp->push_back(nodeb->val);
			nodeb = nodeb->next;
		}
	}
	if(flag) {
		while(nodea != NULL) {
			temp->push_back(nodea->val);
			nodea = nodea->next;
		}
	}
	return temp;
}

int main(int argc, char const *argv[]){
	List llist;
	int size;
	cin >> size;
	initialize(llist, size);

	
	List first, second;

	int count = 0;
	Node *temp = llist.head;
	while(temp != NULL) {
		if(count % 2 == 0) {
			first.push_back(temp->val);
			cout << count << " first" << endl;
		}
		else {
			cout << count << " second" << endl;
			second.push_back(temp->val);
			cout << "\t"; second.print();
		}
		temp = temp->next;
		count++;
	}
	cout << "Done" << endl;
	second.reverse();

	first.print();
	second.print();

	List *final = merge(first, second);
	llist.print();
	cout << "---" <<  endl;
	final->print();

	return 0;
}