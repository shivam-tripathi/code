// www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char ch;
	Node *next;
	Node(char ch){
		this->ch = ch;
		next = NULL;
	}
};

class Linked_list {
public:
	Node *head;
	Node *tail;
	Node *temp;
	Linked_list() {
		head = NULL;
		tail = NULL;
	}

	void push_back(char ch) {
		temp = new Node(ch);
		if(head == NULL)
			head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
		}
	}
};


int cmpstr(const Linked_list &a, const Linked_list &b) {
	Node *nodeA, *nodeB;
	nodeA = a.head;
	nodeB = b.head;

	while(true) {
		if(nodeA == NULL && nodeB != NULL)
			return -1;
		else if (nodeB == NULL && nodeA != NULL)
			return 1;
		else if (nodeA == NULL && nodeB == NULL)
			return 0;

		if(nodeA->ch > nodeB->ch)
			return 1;
		else if (nodeA->ch < nodeB->ch)
			return -1;

		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}
}

int main(int argc, char const *argv[]){
	cout << "Input two strings" << endl;
	string a, b;
	cin >> a >> b;

	Linked_list la;
	Linked_list lb;
	for(int i=0; i<a.size(); i++) la.push_back(a[i]);
	for(int i=0; i<b.size(); i++) lb.push_back(b[i]);

	cout << cmpstr(la, lb) << endl;
	return 0;
}