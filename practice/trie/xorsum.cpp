/* https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2683 

Problem statement : 
Given an array of N numbers, we wish to choose a contiguous sub-sequence of the array, so that the 
bitwise XOR of all chosen numbers is maximum.

Comment: Use of Trie
*/
#include <stdio.h>
#include <climits>
#define INT_SIZE sizeof(int)*8
using namespace std;

// Approach one : Generate all contiguous subsets 
// Pattern like : 1 12 123 1234 2 23 234 3 34 4 in [1, 2, 3, 4]
int osquare(int a[], int size){
	int result = INT_MAX;
	for(int i=0; i<size; i++){
		int cur_xor = 0;
		for(int j=i; j<size; j++){
			cur_xor ^= a[j];
			result = max(result, cur_xor);
		}
	}
	return result;
}

// Approach two : Use Trie
// Properties | x ^ x = 0 and x ^ 0 = x |
struct TrieNode{
	int value; 
	TrieNode *arr[2];
};

TrieNode* newNode{
	TrieNode *node = new TrieNode;
	node->value = 0;
	node->arr[0] = node->arr[1] = NULL;
	return node;
}

void insert(TrieNode* root, int pre_xor){
	TrieNode *node = root;
	for(int i=INT_SIZE-1; i>=0; i--){
		bool value = pre_xor & (1<<i);
		if(node->arr[value] == NULL){
			node->arr[value] = newNode();
		}
		node = node->arr[value];
	}
	node->value = pre_xor;
}

int query(TrieNode *root, int pre_xor){
	TrieNode *node = root;
	for(int i=INT_SIZE-1; i>=0; i--){
		bool value = pre_xor & (1<<i);
		if(node->arr[!value] != NULL)
			node = node->arr[!value];
		else if(node->arr[value] != NULL)
			node = node->arr[value];
	}
	return pre_xor ^ node->value;
}
