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
	cout<<"     "<<root->data<<endl;
	cout<<"    /  \\"<<endl;
	cout<<"   "<<root->left->data;
	cout<<"   "<<root->right->data<<endl;
	cout<<"  / \\  / \\"<<endl;
	cout<<" "<<root->left->left->data;
	cout<<"   "<<root->left->right->data;
	cout<<" "<<root->right->left->data;
	cout<<"  "<<root->right->right->data<<endl;
	return 0;
}