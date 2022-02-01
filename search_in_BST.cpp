#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data=val;
		left=right=NULL;
	}
};
bool search_BST(Node* root,int val)
{
	if(root==NULL)
		return false;

	 while (root != NULL) {
        if (root->data == val)
            return true;
        if (root->data < val)
            root = root->right;
        else 
            root = root->left;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	Node* root=new Node(4);
	root->left=new Node(2);
	root->left->right=new Node(3);
	root->left->left=new Node(1);
	root->right=new Node(6);
	root->right->left=new Node(5);
	root->right->right=new Node(7);
	if(search_BST(root,7))
		cout<<"Number found";
	else
		cout<<"Not Found";
	return 0;
}