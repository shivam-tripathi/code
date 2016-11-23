// www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place

#include <bits/stdc++.h>
using namespace std;

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
		head = tail = temp = NULL;
	}

	void push_back(int val){
		temp = new Node(val);
		if(head == NULL)
			head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
			tail->next = NULL;
		}
	}

	void print() {
		temp = head;
		while(temp != NULL){
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse() {
		if(head == NULL || head == tail) return;
		Node *buf, *prev;
		prev = head;
		temp = head->next;
		while(temp != NULL) {
			buf = temp->next;
			temp->next = prev;
			prev = temp;
			temp = buf;
		}
		head->next = NULL;
		swap(head, tail);
	}
};

// *****************************************************************************
List llist;
int size;

// *****************************************************************************
void initialize() {
	srand(time(NULL));
	for(int i=0; i<size; i++){
		llist.push_back(rand()%100);
	}
}

// *****************************************************************************
Node *tortoise_hare(){
	Node *rabbit = llist.head;
	Node *tortoise = rabbit;
	bool temp = false;
	while(rabbit != NULL) {
		if(temp) {
			// cout << "Updating tortoise" << endl;
			tortoise = tortoise->next;
		}
		rabbit = rabbit->next;
		temp = !temp;
	}
	return tortoise;
}

// *****************************************************************************
int main(int argc, char const *argv[]){
	cin >> size;
	initialize();

	llist.print();

	Node *mid = (tortoise_hare());

	List a, b;
	Node *temp = llist.head;
	while(temp != mid) {
		a.push_back(temp->val);
		temp = temp->next;
	}
	temp = mid;
	while(temp != NULL) {
		b.push_back(temp->val);
		temp = temp->next;
	}
	b.reverse();

	Node *tempa = a.head;
	Node *tempb = b.head;

	// Logic here is more C like, which will mostly be needed by some one asking you the answer
	// The entire process can be done in O(1) auxillary space. The new lists only needed to borrow 
	// the mid and mid-1 pointers from the original array, and then follow logic below.
	// The other useless method would be making a new list and passing the elements alternatively.
	while(tempb != NULL && tempa != NULL) {
		temp = tempa->next;
		tempa->next = tempb;
		tempa = tempb;
		tempb = temp;
		// Switching of active nodes is being done. Node A makes it's next Node B. Then Node B has 
		// to do the same thing, so A is made B and B becomes what was originally A's next.
	}
	a.tail = b.tail;

	a.print();

	return 0;
}