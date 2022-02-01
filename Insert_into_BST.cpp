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

void print_inorder(Node* root)
{
	if(root==NULL)
		return;
	stack<Node*> st;
	Node* node=root;
	while(true)
	{
		if(node!=NULL)
				{
					st.push(node);
					node=node->left;
				}
		else{
			if(st.empty()==true) break;
			node=st.top();
			st.pop();
			cout<<node->data<<" ";
			node=node->right; 
		}
	}
}




Node* insert_BST(Node* root,int val)
{
	if(root==NULL)
	return new Node(val);
	if(root->data==val)
		return root;
	else if(root->data<val)
		root->right=insert_BST(root->right,val);
	else
		root->left=insert_BST(root->left,val);
	return root;
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
	Node* nd=insert_BST(root,8);
	print_inorder(nd);
	return 0;
}