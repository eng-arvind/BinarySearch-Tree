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

Node* findlast(Node* root)
{
	if(root->right==NULL)
		return root;
	return findlast(root->right);
}

Node* helper(Node* root)
{
	if(root->left==NULL)
		return root->right;
	if(root->right==NULL)
		return root->left;
	Node* rightsubtree=root->right;
	Node* lastRight=findlast(root->left);
	lastRight->right=rightsubtree;
	return root->left;
}

Node* delete_node(Node* root,int val)
{
	if(root==NULL)
	return NULL;
	if(root->data==val)
	return helper(root);
	Node* dummy =root;
	while(root!=NULL)
	{
		if(root->data>val)
		{
			if(root->left!=NULL && root->left->data==val)
			{
				root->left=helper(root->left);
				break;
			}
			else
			{
				root=root->left;
			}
		}
		else
		{
			if(root->right!=NULL && root->right->data==val)
			{
				root->right=helper(root->right);
				break;
			}
			else
			{
				root=root->right;
			}
		}
	}	
	return dummy;
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
	Node* nd=delete_node(root,5);
	root=nd;
	cout<<"     "<<root->data<<endl;
	cout<<"    /  \\"<<endl;
	cout<<"   "<<root->left->data;
	cout<<"   "<<root->right->data<<endl;
	cout<<"  / \\  / \\"<<endl;
	cout<<" "<<root->left->left->data;
	cout<<"   "<<root->left->right->data;
	cout<<"  ";
	cout<<"  "<<root->right->right->data<<endl;
	return 0;
}