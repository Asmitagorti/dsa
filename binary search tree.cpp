#include <stdio.h>
#include <stdlib.h>

struct BinaryTree{
	int data;
	struct BinaryTree* left,*right;
};

typedef struct BinaryTree Node; //

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
Node* Findmin(Node* root){
	//you have to find the smallest value here
	while(root!=NULL && root->left!=NULL){
		root=root->left; // traversing
	}
	return root;
}
Node* Delete(Node* root, int val){
	if(root==NULL){
		return NULL; // nthg to delete
	}
	if(root->data>val){
		root->left=Delete(root->left,val); // recursion call!!
	}
	else if(root->data<val){
		root->right=Delete(root->right,val);
	}
	else{ // root->data==val
		// you've three cases
		// 1) you delete the leaf node
		// 2) you've one child
		// 3) you've two children
		
		// 1) you delete the leaf node
		if(root->left==NULL && root->right==NULL){ 
			free(root);
			return NULL; // u've deleted the leaf node, there's no change in the Binary search tree
		}
		// 2) you've one child
		else if(root->left==NULL || root->right==NULL){
			Node* temp=NULL;
			if(root->left==NULL){
				temp=root->right;
			}
			else{
				temp=root->left;
			}
			free(root);
			return temp;
		}
		// 3) you've two children
		else{
			// you have to find the smallest value in the right subtree of the root
			// the successor of the node  is the smallest value in the right subtree
			// once you find the smallest, you have to store the smallest value in the node
			// and then u delete the temp node, this happens in the recursive call itself
			Node *temp=Findmin(root->right); // searching the right subtree of root
			root->data=temp->data; // assigning the value
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;
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
	scanf("%d",&val);
	root=Delete(root,val);
	Inorder(root);
}
