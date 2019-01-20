// http://www.spoj.com/problems/TREEORD/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	int val;
	Node(int val) :
	val(val), left(NULL), right(NULL)
	{}
};

int preorder[8010];
int postorder[8010];
int inorder[8010];
int dummy_post_order[8010];
int n;
bool invalid;

int find_inorder_index(int l, int r, int val) {
	for(int i=l; i<=r; i++) {
		if (inorder[i] == val)
			return i;
	}
	return -1;
}

Node *construct_tree(int l=0, int r=n-1) {
	static int index = -1;

	if (index+1 >= n || (l > r) || invalid)
		return NULL;

	int val = preorder[++index];

	Node *root = new Node(val);
	if (l == r) return root;

	int inorder_index = find_inorder_index(l, r, val);
	if (inorder_index == -1) {
		invalid = true;
		return NULL;
	}


	root->left = construct_tree(l, inorder_index-1);
	root->right = construct_tree(inorder_index+1, r);
	return root;
}

void construct_dummy_post_order(Node *root) {
	static int index = 0;
	if (root == NULL)
		return;

	construct_dummy_post_order(root->left);
	construct_dummy_post_order(root->right);
	dummy_post_order[index++] = root->val;
}

int main(int argc, char const *argv[]){
	cin >> n;
	invalid = false;

	vector<int *> arr{preorder, postorder, inorder};
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}

	Node *root = construct_tree();
	if(root == NULL) {
		cout << "no" << endl;
		return 0;
	}

	if (invalid) {
		cout << "no" << endl;
		return 0;
	}

	construct_dummy_post_order(root);

	for(int i=0; i<n; i++) {
		if (dummy_post_order[i] != postorder[i]) {
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;

	return 0;
}