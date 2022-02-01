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
int kth_smallest(Node* root,int k)
{
	if(root==NULL)
		return -1;
	stack<Node*> st;
	Node* node=root;
	int cnt=1,ans;
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
			if(cnt==k)
			{
				ans=node->data;
				break;
			}
			cnt++;
			node=node->right; 
		}
	}
	return ans;
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
	cout<<kth_smallest(root,3);
	return 0;
}