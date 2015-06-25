/*
Exp no :16
Program to implement circular queue using linked list
27/03/2015
S4-R-030 Jayadeep KM
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};

typedef struct node node;


void insert(node**,int);
void del(node**);
void display(node*,int);

int main(){
	node *h=NULL;
	int ch,val;

	printf("-------------MENU------------\n"
	"1. Insert\n2. Delete\n3. Display\n4. Exit");

	do{
		printf("\n Select your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter a value :");
				scanf("%d",&val);
				insert(&h,val);
				display(h,0);
				break;
			case 2:
				del(&h);
				display(h,0);
				break;
			case 3:
				printf("\nEnter starting position : ");
				scanf("%d",&val);
				display(h,val-1);

		}

	}while(ch!=4);

	return 0;
}


void insert(node **h,int val){
	node *t,*p,*t1;
	if(*h==NULL){
		*h = (node*) malloc(sizeof(node));
		p = *h;
		p->next = *h;
		p->val = val;
	}else{
		p = *h;
		*h = (node*)malloc(sizeof(node));
		t = *h;
		t->val = val;
		t->next = p;
		t1 = p;
		do{
			t1 = t1->next;
		}while(t1->next!=p);
		t1->next=t;
	}
}

void del(node **h){
	node *t,*t1;
	node *p = *h;
	if(p==NULL){
		printf("Unable to delete\n");
	}else if(p->next==p){
		printf("\nDeleted : %d\n",(**h).val);
		free(*h);
		*h = NULL;
	}else{
		t = p;
		t1=p;
		while(t1->next!=p)
			t1 = t1->next;
		t1->next = p->next;
		*h = p->next;
		printf("\nDeleted : %d\n",p->val);
		free(p);
	}

}

void display(node *h, int pos){

	node *p,*t;
	p = h;
	int i;
	if(p==NULL){
		printf("\nEmpty!");
		return;
	}
	for(i=0;i<pos;i++){
		p = p->next;
	}
	t=p;
	printf("\nvalues : "); 
	do{
		printf("%d ",p->val);
		p = p->next;
	}while(p!=t);

}
