// creating a linked list in an optimal way....
// user input : number of nodes
// two pointer technique..
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int value;
	struct Node *next;
}; // creating a structure for Node
struct Node *head=NULL; //head: Points to the first node (beginning of the list).
struct Node *tail=NULL; //tail: Points to the last node (end of the list).
// we initialised it to NULL, as the linked list is inially empty.

struct Node* create_a_node(int val){ // the return type here is struct Node*, as we are returning a node
	struct Node* newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->value=val;
	newnode->next=NULL;
	return newnode; 
}
void Insert_Node(int val){
	if(head==NULL) { // this case is just for the first node
		head=create_a_node(val);
		tail=head; // tail is the same as head
		// tail allows faster insertion at the end without traversing the list.
	}
	else{
		tail->next=create_a_node(val); //creates a new node and links it to the current tail
		tail=tail->next; // moves tail forward to point to the new last node
		// here we always know where the last node is
	}
}
int main(){
	int n;
	printf("Enter number of nodes:\n");
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		printf("Enter node %d\n",i);
		int val;
		scanf("%d",&val);
		Insert_Node(val);
	}
	while(head!=NULL){
		printf("%d ",head->value);
		head=head->next; // updates first to point to the next node in the chain
	}
	// hence inserting nodes and values, is always time complexity : O(1)
	// with the tail pointer, we already know the last node, so:
	// we directly add a new node in constant time.
	// updating the tail pointer also takes O(1).
	// no matter how large the list is, inserting a new node only requires fixed operations—hence, O(1) time complexity.
	return 0;
}