#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{ // defining what a node is, and what it contains
	int value;
	struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;

struct Node* create_a_node(int val){
	struct Node* newnode; // defined the new node
	newnode=(struct Node*)malloc(sizeof(struct Node)); 
	// dynamically allocating space of the struct node to a single node
	newnode->value=val; // assigning the value val to newnode
	newnode->next=NULL; 
	// assigning null to the address storage of newnode, as we havent linked it yet
	return newnode;
}

void insert_to_linked_list(int val){
	if(head==NULL){ // this is only for the 1st iteratiom, when the linked list is empty
		head=create_a_node(val);
		tail=head; // tial and head are at the same position, index 0
	}
	else{
		tail->next=create_a_node(val); // we only shift tail throughout the linked list
		// while leaving head at the 1st node
		tail=tail->next; //shifting tail to the (newly formed) last node
	}
}
void insertion_at_head(int val){
	struct Node* newnode=create_a_node(val); // creating a newnode
	newnode->next=head; // creating a link from newnode to the head of the linked list
	// after linking, the head is now NOT the first node
	head=newnode; // therefore, the first node is newnode, which we assign as head
}
void insert_middle(int pos,int val){
	struct Node *p1 = NULL; // creating two nodes, one p1 before temp
	struct Node *p2 =NULL; // p2 after temp
	// 10 20     30   40 50
	//    temp
	//    p1     p2
	//     |     |
	//     --25--
	struct Node *temp=head;
	int count=0;
	struct Node *newnode = create_a_node(val);
	while(1){
		count++;
		temp=temp->next;
		if(count==pos-1) break; // we iterate till we reach just before the index
	}
//	printf("%d\n",temp->value);
	p1=temp;
//	printf("%d\n",p1->value);
	p2=temp->next;
//	printf("%d\n",p2->value);
	p1->next=newnode; // we establish links from p1 to newnode
	newnode->next=p2; // we establish links from newnode to p2
}
void delete_node(int val){
	struct Node *temp=head;
	struct Node *prev=NULL;
	while(temp!=NULL && temp->value!=val){ 
	// while the value of the temp is not value, we iterate to assign
	// the values of prev and temp
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL) { 
	// if we iterate throughout the entire list, and cant find the value of the node to delete
		printf("Node with %d value does not exist",val);
		return;
	}
	if(prev==NULL){ // when we're removing the first node
		head=temp->next;  // Move the head forward
        // Update tail if the deleted node was the only node
        if(tail==temp){ // if we delete the first node
            tail=head; //the head becomes the 2nd node
        }
    } 
	else{
        prev->next=temp->next;  // skip the node to delete
        // Update tail if the deleted node was the last node
        if(tail==temp){
            tail=prev; // now tail holds the previous node, after we delete the last node,
            // the previous node is the now last node
        }
    }
}
int main(){
	int n;
	int val;
	scanf("%d",&n);// number of nodes
	for(int i=0;i<n;++i){
		scanf("%d",&val);// entering the values of the nodes
		insert_to_linked_list(val); 
		// creating nodes with the value,and then forming the links between them
	}
//	insertion_at_head(5); adding the value 5 as the first node
	insert_middle(2,25); //adding the value 25 at the 2nd index
//	delete_node(20);
	while(head!=NULL){
		printf("%d ",head->value); // printing each value of the nodes in the linked list
		head=head->next;
	}
	return 0;
}