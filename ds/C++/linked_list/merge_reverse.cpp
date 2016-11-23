// www.geeksforgeeks.org/merge-two-sorted-linked-lists-such-that-merged-list-is-in-reverse-order
#include <bits/stdc++.h>
using namespace std;

#define NUM ((int)((rand()/(float)RAND_MAX) * 10))

class Node {
public:
	int val;
	Node *next;
	Node(int val) {
		this->val = val;
	}
};

class List {
public:
	Node *head;
	Node *tail;
	Node *temp;
	List () {
		head = tail = NULL;
	}
	void push_back (int i) {
		temp = new Node(i);
		if(head == NULL) 
			head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void push_front(int i) {
		temp = new Node(i);
		if(head == NULL)
			head = tail = temp;
		else {
			temp->next = head;
			head = temp;
		} 
	}
	void print() {
		temp = head;
		while(temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

List* merge(const List &a, const List &b) {
	List *temp = new List;
	Node *nodeA = a.head, *nodeB = b.head;
	bool flag = false;
	while(true) {
		if(nodeA == NULL && nodeB == NULL) break;
		if(nodeA == NULL && nodeB != NULL) {
			flag = true;
			break;	
		} 
		if(nodeA != NULL && nodeB == NULL) {
			swap(nodeA, nodeB);
			flag = true;
			break;	
		} 
		int dig;
		if (nodeA->val < nodeB->val) {
			dig = nodeA->val;
			nodeA = nodeA->next;
		}
		else {
			dig = nodeB->val;
			nodeB = nodeB->next;
		}
		temp->push_front(dig);
	}

	if(flag) {
		while(nodeB != NULL) {
			temp->push_front(nodeB->val);
			nodeB = nodeB->next;
		}
	}
	return temp;
}

int main(int argc, char const *argv[]){
	List a, b;

	// Generating random data, which has to be sorted
	srand(time(NULL));
	vector<int> vectA;
	vector<int> vectB;
	for(int i=0; i<10; i++) {
		vectA.push_back (NUM);
		vectB.push_back (NUM);
	}
	vectA.push_back(11); vectA.push_back(-11); vectB.push_back(13);
	sort(vectA.begin(), vectA.end());
	sort(vectB.begin(), vectB.end());
	for(int i=0; i<vectA.size(); i++) {
		// cout << vectA[i] << " ";
		a.push_back(vectA[i]);
	}
	cout << endl;
	for(int i=0; i<vectB.size(); i++) {
		// cout << vectB[i] << " ";
		b.push_back(vectB[i]);
	}
	cout << endl;

	// Final generated lists 
	cout << "Print A "; a.print();
	cout << "Print B "; b.print();

	// Reverse Merged list
	List *temp = merge(a, b);
	temp->print();

	return 0;
}