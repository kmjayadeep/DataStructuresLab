/*
Program to implement stack using linked list
S4-R-030
31-12-2014
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};
typedef struct node node;

void push(node*, int);
int pop(node*);
void display(node);


int main(){
	node header;
	header.next=NULL;
	int choice,val;

	printf("\n-------MENU-------\n1. PUSH\n2. POP\n3. Display values\n4. Exit\n");

	do{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter a value to push\n");
				scanf("%d",&val);
				push(&header,val);
				break;
			case 2:
				if(header.next==NULL){
					printf("\nStack empty\n");
					break;
				}
				val = pop(&header);
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


void push(node* header,int val){
	node* temp;
	temp = (node*) malloc(sizeof(node));
	temp->val = val;
	temp->next = header->next;
	header->next = temp;
	display(*header);
}

int pop(node* header){
	int val = header->next->val;
	node* t = header->next;
	header->next = t->next;
	free(t);
	return val;
}

void display(node header){
	printf("\nContents of stack is : ");
	node* p = header.next;
	while(p!=NULL){
		printf("%d\t",p->val);
		p = p->next;
	}

}
