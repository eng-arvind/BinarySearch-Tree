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

int floor_Binary_ST(Node* root,int floor)
{
	int ans=-1;
	if(root==NULL)
		return -1;

	 while (root != NULL) {
        if (root->data == floor)
        {
            ans=root->data;
            return ans;
        }
        if (root->data < floor)
        {
        	ans=root->data;
            root = root->right;
        }
        else 
        {
            root = root->left;
        }
    }
    return ans;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	Node* root=new Node(10);
	root->left=new Node(5);
	root->left->right=new Node(6);
	root->left->left=new Node(1);
	root->right=new Node(15);
	root->right->left=new Node(11);
	root->right->right=new Node(18);
	cout<<floor_Binary_ST(root,11);
	return 0;
}