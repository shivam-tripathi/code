#include <bits/stdc++.h>
using namespace std;


struct node{
	int value;
	node *left, *right;
};

struct bst{
	node *root;
	int num;
};

node* new_node(int val){
	node *_node = new node;
	_node->value = val;
	_node->left = _node->right = NULL;
}

node* insert(node *root, int value){
	if(root == NULL){
		cout << "allocating" << value << endl;
		root = new_node(value);
		return root;
	}

	if(value < root->value){
		// cout << "left -> ";
		root->left = insert(root->left, value);
	}
	else if(value >= root->value){
		// cout << "right ->";
		root->right = insert(root->right, value);
	}
	return root;
}

void inorder(node *root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->value << " ";
	inorder(root->right);
}

node* kth_smallest(node *root, int k){
	static int count = 0;
	static int flag = 0;
	static int found = 0;

	if(root == NULL){
		flag = 1;
		return root;
	}

	node *found_node = kth_smallest(root->left, k);

	if(found == 1)
		return found_node;

	if(flag == 1){
		count++;
		if(count == k){
			found = 1;
			return root;
		}
	}

	found_node = kth_smallest(root->right, k);
	if(found == 1)
		return found_node;

	return NULL;
}

int main(int argc, char const *argv[])
{
	node* root = NULL;

	root = insert(root, 12);

	root = insert(root, 32);

	root = insert(root, 11);

	root = insert(root, 45);

	inorder(root);
	cout << endl;

	node *found = kth_smallest(root, 3);

	if(found == NULL)
		cout << "size less than k " << endl;
	else cout << found->value << endl;

	return 0;
}
