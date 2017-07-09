#include <bits/stdc++.h>
using namespace std;

int n;

short inorder[8000+10];
short postorder[8000+10];
short preorder[8000+10];
short tpostorder[8000+10];

struct node {
	node *left;
	node *right;
	int val;
	node(int val) {
		this->val = val;
		left = right = NULL;
	}
};


int _search(int l, int r, int val) {
	for(int i=l; i<=r; i++) {
		if(inorder[i] == val) {
			return i;
		}
	}
	return -1;
}

node *construct(int l=0, int r=n-1) {
	static int index = 0;

	if (index >= n) return NULL;

	node *root = new node(preorder[index++]);

	if (l == r) {
		return root;
	}

	int inindex = _search(l, r, preorder[index-1]);
	if (inindex == -1) {
		cout << "no" << endl;
		exit(0);
	}

	if (inindex != l)
		root->left = construct(l, inindex-1);
	if (inindex != r)
		root->right = construct(inindex+1, r);

	return root;
}



void postorder_traversal(node *root) {
	static int index = 0;
	if (root == NULL) return;

	// cout << "root = " << root->val;
	// if (root->left != NULL)
		// cout << " left = " << root->left->val;
	// if (root->right != NULL)
		// cout << " right = "  << root->right->val << endl;
	// cout << endl;

	postorder_traversal(root->left);
	postorder_traversal(root->right);
	tpostorder[index++] = root->val;
}

int main(int argc, char const *argv[])
{
	cin >> n;


	for(int i=0; i<n; i++) {
		cin >> preorder[i];
	}
	for(int i=0; i<n; ++i) {
		cin >> postorder[i];
	}
	for(int i=0; i<n; i++) {
		cin >> inorder[i];
	}

	node *root = construct();
	if (root == NULL) {
		cout << "no" << endl;
		return 0;
	}

	// cout << "postorder " << endl;
	postorder_traversal(root);
	// cout << endl;

	for(int i=0; i<n; i++) {
		// cout << tpostorder[i] << " " << postorder[i] << endl;
		if (tpostorder[i] != postorder[i]) {
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;

	return 0;
}