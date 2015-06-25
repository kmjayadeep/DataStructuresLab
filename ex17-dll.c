/*
Exp no: 17
Program to implement doubly linkedlist
S4-R-030
26-03-2015
*/

#include<stdio.h>
#include<stdlib.h>


struct node{
	int val;
	struct node* next;
	struct node* prev;
};

typedef struct node node;

void insert(node*,int);
void del(node*,int);
void display(node*);
int main(){
	int val,ch;
	node h;
	h.next=NULL;
	h.prev=NULL;

	printf("\n-------------MENU----------------\n"
	"1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	do{
		printf("\nSelect your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter a number : ");
				scanf("%d",&val);
				insert(&h,val);
				display(&h);break;
			case 2: printf("\nEnter key : ");
				scanf("%d",&val);
				del(&h,val);
			case 3:display(&h); break;

		}
	}while(ch!=4);
	return 0;
}


void insert(node* h,int val){
	node *p;
	p = h->next;
	h->next = (node*)malloc(sizeof(node));
	h->next->prev=h;
	h->next->next=p;
	if(p) p->prev = h->next;
	h->next->val = val;
}

void del(node* h,int key){
	node *p,*t;
	p = h->next;
	int f=0;
	while(p){
		if(p->val==key){
			f=1;
			t=p;
			p = p->next;
			if(p)
				p->prev=t->prev;
			t->prev->next=p;
			free(t);
		}else p = p->next;
	}
	if(!f) printf("\nNot found\n");
}

void display(node *h){
	node *p = h->next,*t;
	if(!p){
		printf("\nEmpty");
		return;
	}
	printf("Forward : ");
	while(p){
		printf("%d ",p->val);
		t=p;
		p = p->next;
	}
	printf("\nBackward : ");
	while(t->prev){
		printf("%d ",t->val);
		t = t->prev;
	}


}
