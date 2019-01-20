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

void reverse_inorder(node *root){
	if(root == NULL)
		return;
	reverse_inorder(root->right);
	cout << root->value << " ";
	reverse_inorder(root->left);
}

node* find_left_leaf(node *root){
	if(root->left == NULL)
		return root;
	else find_left_leaf(root->left);
}

node* delete_node(node *root, int value){
	if(root == NULL){
		cout << "Not found" << endl;
		return root;
	}
	if(root->value == value){
		if(root->right == NULL)
			root = root->left;
		else{
			node *leaf = find_left_leaf(root->right);
			leaf->left = root->left;
			root = root->right;
		}
	}
	else if(root->value < value)
		root->right = delete_node(root->right, value);
	else
		root->left = delete_node(root->left, value);
	return root;
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

	reverse_inorder(root);
	cout << endl;

	root = delete_node(root, 32);
	inorder(root);
	cout << endl;

	return 0;
}
