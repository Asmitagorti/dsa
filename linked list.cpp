#include <stdio.h>
#include <stdlib.h>
struct Node{
	int value; // holds the values of the nodes: first->value=10
	struct Node *next; // a pointer to the next node, so we can store its address in the previous node
	// struct Node is the data type, like int
	// just how we write: int * a, here its : struct Node a;
};
typedef Node N;
int main(){
	N *first; // defining the 1st node as a pointer first
	//arr=(int*)malloc(sizeof(int)*3); here we are creating memory for 3 values..
	first=(N*)malloc(sizeof(N)); 
	// here we're dynamically allocating each node one at a time, hence we only need sizeof(int)..
	
	// since we dont know the number of node before hand, we need to dynamically allocate memory for each node
	// with DMA, you can add or remove nodes dynamically during program execution
	first->value=10; // assinging value to first node
	// we are using -> instead of . as we are using pointers
	// for normal values we use . for pointers we use ->
	first->next=NULL; //When you create a new node, 
	//its next pointer should initially point to nothing—this means it’s the end of the list.
	
	N *second;
	second=(N*)malloc(sizeof(N));
	second->value=20;
	second->next=NULL;
	first->next=second; // creating link between 1 - 2, link nodes and extend the list
	
	N *third;
	third=(N*)malloc(sizeof(N));
	third->value=30;
	third->next=NULL;
	second->next=third; // creating link between 2 -3;
	
	while(first!=NULL){
		printf("%d ",first->value);
		first=first->next; // updates first to point to the next node in the chain
	}
	// time complexity: O(n) as we:
	//Start at the head.
	//Traverse the entire list to find the last node.
	//Attach the new node.
	return 0;
}
