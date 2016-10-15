#include <bits/stdc++.h>
#define SIZE 10
#define to_num(a) ((a) - '0')
using namespace std;

struct Node{
	int end;
	Node* arr[10];
};

class Trie{
public:
	Node* root;
	Trie(){
		root = this->create_node();
	}
	Node* create_node(){
		Node* node = new Node;
		for(int i=0; i<SIZE; i++)
			node->arr[i] = NULL;
		node->end = 0;
		return node;
	}
	bool insert_num(string num){
		Node* node = root;
		int len = num.length();
		for(int i=0; i<len; i++){
			int digit = to_num(num[i]);
			if(node->arr[digit] != NULL){
				if(node->arr[digit]->end == 1){
					return true;
				}
			}
			else{
				node->arr[digit] = create_node();
			}
			node = node->arr[digit];
		}
		node->end = 1;
		return 0;
	}
	bool look_up(string num){
		Node* node = root;
		for(int i=0; i<num.length(); i++){
			int digit = to_num(num[i]);
			if(node->arr[digit] == NULL){
				cout << "Not found " << digit << " in " << num << endl;
				return false;
			}
			node = node->arr[digit];
		}
		if(node->end == 0)
			return false;
		return true;
	}
};

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, flag = 0;
		cin >> n;
		string num;
		Trie trie;
		for(int i=0; i<n; i++){
			cin >> num;
			if(trie.insert_num(num)){
				flag = 1;
			}
		}
		if(flag == 0)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}