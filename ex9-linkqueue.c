/*
Experiment No: 9
Program to implement queue using linked list
S4-R-030
07-01-2015
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};
typedef struct node node;

void enqueue(node**, int);
int dequeue(node*,node**);
void display(node);


int main(){
	node header,*rear;
	int choice,val;
	rear = &header;
	printf("\n-------MENU-------\n1. ENQUEUE\n2. DEQUEUE\n3. Display values\n4. Exit");
	do{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter a value\n");
				scanf("%d",&val);
				enqueue(&rear,val);
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
					printf("\nQueue is empty\n");
				else
					display(header);
			case 4: break;
			default:
				printf("\nInvalid choice, try again\n");
		}
	}while(choice!=4);

	return 0;
}


void enqueue(node** rear,int val){
	(*rear)->next = (node*) malloc(sizeof(node));
	*rear = (*rear)->next;
	(*rear)->val = val;
	(*rear)->next = NULL;

}

int dequeue(node* header,node** rear){
	int val = header->next->val;
	node* t = header->next;
	header->next = t->next;
	free(t);
	if(header->next==NULL)
		*rear = header;
	return val;
}

void display(node header){
	printf("\nContents of queue is : ");
	node* p = header.next;
	while(p!=NULL){
		printf("%d\t",p->val);
		p = p->next;
	}
}
