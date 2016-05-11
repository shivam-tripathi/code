//Implementation of a doubly linked list using templates
#include <bits/stdc++.h>
#define len(a) (a.size)
#define head(a) (a.front())
#define tail(a) (a.back())
using namespace std;


/*******************************************************************************
*																			   *
*   -----------------------------Doubly Linked List-------------------------   *
*																               *
*******************************************************************************/

template<class T>
class List{
public:
	//Structure to store Node of the linked list
	struct Node{
		T elem;
		Node* next;
		Node* prev;
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
	T* traverse_front(){
		T* arr = new T[size];
		int i=0;
		Node* temp = head;
		while(temp!=NULL){
			arr[i++] = temp->elem;
			cout << temp->elem << endl;
			temp = temp->next;
		}
		return arr;
	}

	// Reverse traverse and print the list
	void traverse_back(){
		Node* temp = tail;
		while(temp!=NULL){
			cout << temp->elem << endl;
			temp = temp->prev;
		}
	}
	void sort(void compare(void*, void*)){
		T arr[] = traverse_front();
		qsort(arr, size, sizeof(T), compare);
		Node* temp = head;
		int i=0;
		while(temp != NULL){
			temp->elem = arr[i++];
			temp = temp->next;
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

	// Get the end of the lsit
	Node* end(){
		return tail;
	}
};


/*******************************************************************************
*																			   *
*   -----------------------------Singly Linked List-------------------------   *
*																               *
*******************************************************************************/
// This is basically a wrapper over the doubly linked list - abstraction to use
// the doubly linked as singly linked list

template <class T>
class SList{
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
	cout << list.get_index(12) << endl;
	cout << len(list) << " " << head(list) << " "  << tail(list) << endl;
	for(List::Iterator<int> obj=list.begin(); List<int>::obj!=list.end(); List<int>::obj++){
		cout << List<int>::obj->elem;
	}
}
