/*
Experiment No: 10
Program to priority queue using linked list
S4-R-030
07-01-2015
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int val,priority;
	struct node* next;
};
typedef struct node node;

void enqueue(node**, int,int);
int dequeue(node*,node**);
void display(node);


int main(){
	node header,*rear;
	int choice,val,p;
	rear = &header;
	printf("\n-------MENU-------\n1. ENQUEUE\n2. DEQUEUE\n3. Display values\n4. Exit");

	do{
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter a value\n");
				scanf("%d",&val);
				printf("\nEnter the proprity : ");
				scanf("%d",&p);
				enqueue(&rear,val,p);
				display(header);
				break;
			case 2:
				if(header.next==NULL){
					printf("\nQueue is empty\n");
					break;
				}
				val = dequeue(&header,&rear);
				printf("\nValue = %d\n",val);
				break;
			case 3:
				if(header.next==NULL)
					printf("\nStack is empty\n");
				else
					display(header);
			case 4: break;
			default:
				printf("\nInvalid choice, try again\n");
		}
	}while(choice!=4);

	return 0;
}


void enqueue(node** rear,int val,int pr){
	(*rear)->next = (node*) malloc(sizeof(node));
	*rear = (*rear)->next;
	(*rear)->val = val;
	(*rear)->priority = pr;
	(*rear)->next = NULL;

}

int dequeue(node* header,node** rear){
	int val;
	node *t = header,*l = header;

	while(t->next!=NULL){
		if(t->next->priority>l->next->priority)
			l = t;
		t = t->next;
	}
	t = l->next;
	val = t->val;
	l->next = t->next;

	free(t);

	if(header->next==NULL)
		*rear = header;
	return val;
}

void display(node header){
	printf("\nContents of queue is : ");
	node* p = header.next;
	while(p!=NULL){
		printf("%d (%d)\t",p->val,p->priority);
		p = p->next;
	}
}
