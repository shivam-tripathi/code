#include <bits/stdc++.h>
#define len(a) (a.length())
#define head(a) (a.front())
#define tail(a) (a.back())
#define list_iterator Node*
using namespace std;


/*******************************************************************************
*																			   *
*   -----------------------------Doubly Linked List-------------------------   *
*																               *
*******************************************************************************/

//Implementation of a doubly linked list using templates
template<typename T>
class List{
public:
	//Structure to store Node of the linked list
	struct Node{
		T elem;
		Node* next;
		Node* prev;
		Node(){}
		Node(T item){
			elem = item;
			next = NULL;
			prev = NULL;
		}
	};
	// The corresponding head, tail and size of the linked list
	Node* head;
	Node* tail;
	int size;
	List(){
		head = NULL;
		tail = NULL;
		size = 0;

	}

	// Add an element to the end of the list
	void push_back(T item){
		Node* node = new Node(item);
		if(size == 0){
			head = node;
			tail = node;
		}
		else{
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		size++;
	}

	// Add element to the front
	void push_front(T item){
		Node* node = new Node(item);
		if(size == 0){
			head = node;
			tail = node;
		}
		else{
			head->prev = node;
			node->next = head;
			head = node;
		}
		size++;
	}

	// Function to remove the last element of the list
	void remove_back(){
		if(size == 0){
			fprintf(stderr, "Removing from empty list\n");
			exit(0);
		}
		if(size == 1){
			delete tail;
			head = NULL;
			tail = NULL;
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		size--;
	}

	// Function to remove the first element of the list
	void remove_front(){
		if(size == 0){
			fprintf(stderr, "Removing from empty list\n");
			exit(1);
		}
		if(size == 1){
			delete tail;
			head = NULL;
			tail = NULL;
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	// Returns the first element of the list
	T front(){
		return head->elem;
	}

	// Return the last element of the list
	T back(){
		return tail->elem;
	}

	// Front traverse and print the list
	void traverse_front(){
		Node* temp = head;
		while(temp!=NULL){
			cout << temp->elem << endl;
			temp = temp->next;
		}
	}

	// Reverse traverse and print the list
	void traverse_back(){
		Node* temp = tail;
		while(temp!=NULL){
			cout << temp->elem << endl;
			temp = temp->prev;
		}
	}
	// Function to delete element with the given value
	void delete_value(T item){
		Node* temp = head;
		while(temp != NULL){
			if(temp->elem == item){
				if(temp == head)
					remove_front();
				else if(temp == tail)
					remove_back();
				else{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
				}
				break;
			}
			temp = temp->next;
		}
		if(size != 0) size--;
	}

	// Function to remove the element at a given index
	void delete_index(int index){
		Node* temp = head;
		int i=0;
		while(temp != NULL){
			if(i == index){
				cout << "Deleting " << temp->elem << endl;
				if(i==0)
					remove_front();
				else if(i==size-1)
					remove_back();
				else{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
				}
				break;
			}
			temp = temp->next;
			i++;
		}
		if(size!=0) size--;
	}

	// function to add an element at a given index
	void add_index(int index, T item){
		if(index==0){
			push_front(item);
			return;
		}
		if(index == size-1){
			push_back(item);
			return;
		}
		Node* temp = head->next;
		int i=1;
		while(temp!=NULL){
			if(i == index){
				Node* node = new Node(item);
				temp->prev->next = node;
				node->prev = temp->prev;
				node->next = temp;
				temp->prev = node;
				break;
			}
			temp = temp->next;
			i++;
		}
		size++;
	}

	// Function to get the index of the argument in the list
	int get_index(T item){
		if(size == 0){
			fprintf(stderr, "Accessing an empty list\n");
			exit(0);
		}
		int i=0;
		Node* temp = head;
		while(temp!=NULL){
			if(temp->elem == item){
				return i;
			}
			i++;
			temp = temp->next;
		}
	}

	// return size of the list
	int length(){
		return size;
	}

	// Get the beginning of the list
	Node* begin(){
		return head;
	}

	// Get the end of the list
	Node* end(){
		return tail;
	}

	T value(Node* node){
		if(node!=NULL)
			return node->elem;
	}
	void next(Node* &node){
		if(node!=NULL)
			node = node->next;
		else
			return;
	}
	void prev(Node* &node){
		if(node!=NULL)
			node = node->prev;
		else
			return;
	}
	Node* merge(Node* first, Node* second){
		if(!first){
			return second;
		}
		if(!second){
			return first;
		}
		if(first->elem < second->elem){
			first->next = merge(first->next, second);
			first->next->prev = first;
			first->prev	= NULL;
			return first;
		}
		else{
			second->next = merge(first, second->next );
			second->next->prev = second;
			second->prev = NULL;
			return second;
		}
	}
	Node* split(Node* head){
		Node* fast = head, *slow = head;
		while(fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		Node* temp = slow->next;
		slow->next = NULL;
		return temp;
	}
	Node* mergeSort(Node* node){
		if(!node || !(node->next)){
			return node;
		}
		Node* temp = split(node);
		node = mergeSort(node);
		temp = mergeSort(temp);
		node = merge(node, temp);
		return node;
	}
	void sort(){
		head = mergeSort(head);
	}
};

/*******************************************************************************
*																			   *
*   -----------------------------Singly Linked List-------------------------   *
*																               *
*******************************************************************************/
// A basically a wrapper over the doubly linked list


template <typename T>
class SList{
public:
	List<T> list;
	void push_back(T item){
		list.push_back(item);
	}
	int get_index(T item){
		list.get_index(item);
	}
	void add_index(int index, T item){
		list.add_index(index, item);
	}
	void delete_index(int index){
		list.delete_index(index);
	}
	void delete_value(T item){
		list.delete_value(item);
	}
	void traverse(){
		list.traverse_front();
	}
	void remove_front(){
		list.remove_front();
	}
	void remove_back(){
		list.remove_back();
	}
	T front(){
		return list.front();
	}
	T back(){
		list.back();
	}
	int length(){
		return list.length();
	}
	typename List<T>::Node* begin(){
		return list.begin();
	}
	typename List<T>::Node* end(){
		return list.end();
	}
	T value(typename List<T>::Node* &node){
		list.value(node);
	}
	void next(typename List<T>::Node* &node){
		list.next(node);
	}
	void sort(){
		list.sort();
	}
};


int compare(void* a, void* b){
	return *(int*)a - *(int*) b;
}

void print(int arr[], int size){
	for(int i=0; i<size; i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main(){
	List<int> list;
	list.push_back(12);
	list.push_back(13);
	list.push_back(14);
	list.push_front(11);
	list.push_front(10);
	list.traverse_front();
	list.delete_index(2);
	list.traverse_front();
	list.add_index(2, 12);
	list.traverse_front();
	cout << "-----" << endl;
	cout << list.get_index(12) << endl;
	cout << len(list) << " " << head(list) << " "  << tail(list) << endl;
	List<int>::list_iterator node;
	cout << "Traversing using pointers" << endl;
	for(node=list.begin(); node!=list.end(); list.next(node)){
		cout << list.value(node) << endl;
	}
	cout << "----" << endl;
	SList<int> slist;
	slist.push_back(12);
	slist.push_back(13);
	slist.push_back(14);
	slist.traverse();
	List<int>::list_iterator snode;
	for(snode=slist.begin(); snode!=slist.end(); slist.next(snode)){
		cout << slist.value(snode) << endl;
	}
	cout << "Sorted" << endl;
	List<int> list2;
	list2.push_back(13);
	list2.push_back(12);
	list2.push_back(9);
	list2.sort();
	list2.traverse_front();
}
