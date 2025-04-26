#include <stdio.h>
#include <stdlib.h>

struct BinaryTree{
	int data;
	struct BinaryTree* left,*right;
};

typedef struct BinaryTree Node;

Node* CreateNode(int val){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=val;
	temp->right=NULL,temp->left=NULL;
	return temp;
}
Node* Insert(int val,Node* root){
	// base case: this is reached the first time, to create the root node
	// and is reached for root->right, root->left
	if(root==NULL){
		return CreateNode(val);
	}
	if(root->data>val){
		root->left=Insert(val,root->left);
	// the root, after coming from root==NULL call, reaches this call if the condition is met
	// the returned value reaches the Insert call, and the value is stored in root->left
	}
	else if(root->data<val){
		root->right=Insert(val,root->right);
	// the root, after coming from root==NULL call, reaches this call if the condition is met
	// the returned value reaches the Insert call, and the value is stored in root->right
	}
	return root;
}
void Inorder(Node *root){
	// we are printing the binary tree, in the form of inorder 
	if(root==NULL) return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}
int main(){
	int n;
	scanf("%d",&n);
	Node* root=NULL;
	int val;
	scanf("%d",&val);
	// we are storing root with the first value that we pass
	root=Insert(val,root);
	for(int i=1;i<n;++i){
		// starting from the 2nd node ( 1st index ) we are passing the other values
		// ready to be inserted as a binary tree
		scanf("%d",&val);
		// we insert the values here
		Insert(val,root);
	}
	// here we call, inorder function so we can print the formed binary search tree
	Inorder(root);
}