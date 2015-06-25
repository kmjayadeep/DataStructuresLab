/*
Exp no:15
Program to implement addition and deletion operation on linked list
S4 CSE 30
19-03-2015
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};

typedef struct node node;

void insert(node*, int);
void display(node*);
node* findEnd(node*);
node* findIndex(node*, int);
node* findKey(node*, int);
void del(node*);

int main(){

	node h;
	h.next=NULL;
	int choice,c,val,i;
	do{
		printf("\n--------MENU-----------\n"
		"1. Insert\n2. Delete\n3. Exit\nSelect your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				printf("\nWhere to insert?\n1. Front\n2. End\n3. At an Index\n4. After Key\n5. Before Key\nChoice : ");
				scanf("%d",&c);
				switch(c){
					case 1:
						printf("\nEnter a value : ");
						scanf("%d",&val);
						insert(&h,val);
				                break;
					case 2:
						printf("\nEnter a value : ");
						scanf("%d",&val);
						if(h.next!=NULL)
							insert(findEnd(&h)->next,val);
						else
							insert(&h,val);
						break;
					case 3:
						printf("\nEnter a value : ");
						scanf("%d",&val);
						printf("\nEnter Index : ");
						scanf("%d",&i);
						insert(findIndex(&h,i),val);
						break;
				        case 4:
				                printf("\nEnter a value : ");
				                scanf("%d",&val);
				                printf("\nEnter key : ");
				                scanf("%d",&i);
				                insert(findKey(&h,i)->next,val);
						break;
				        case 5:
				                printf("\nEnter a value : ");
				                scanf("%d",&val);
				                printf("\nEnter key : ");
				                scanf("%d",&i);
				                insert(findKey(&h,i),val);
						break;
				}
				display(&h);
				break;
			case 2:
				printf("\nWhere to Delete?\n1. Front\n2. End\n3. A Key\n4. At an Index\nChoice : ");
				scanf("%d",&c);	

				switch(c){

					case 1:
						del(&h);
						break;
					case 2:
						del(findEnd(&h));
						break;
					case 3:
						printf("\nEnter key : ");
						scanf("%d",&i);
						del(findKey(&h,i));
						break;
					case 4:
						printf("\nEnter Index : ");
						scanf("%d",&i);
						del(findIndex(&h,i));
						break;



				}
				display(&h);
				break;	

				 
		}


	}while(choice!=3);
	return 0;
}

void insert(node *h,int val){
	if(h==NULL){
		printf("\nCannot be inserted\n");
		return;
	}
	node *p = h->next;
	h->next = (node*)malloc(sizeof(node));
	h->next->val = val;
	h->next->next = p;
}

void del(node *h){
	if(h==NULL||h->next==NULL){
		printf("\nCannot be deleted\n");
		return;
	}
	node *p = h->next->next;
	free(h->next);
	h->next = p;
}

node* findEnd(node* h){
	node *p = h;
	if(p==NULL)
		return 0;
	if(p->next==NULL)
		return 0;
	while(p->next->next!=NULL){
		p = p->next;
	}
	return p;
}

node* findIndex(node *h, int index){
	node *p = h;
	int i=1;
	while(p->next!=NULL&&i!=index){
		p = p->next;
		i++;
	}
	return p;
}

node* findKey(node *h, int key){
        node *p = h;
        while(p->next!=NULL&&p->next->val!=key){
                p = p->next;
        }
        return p;
}

void display(node* h){
	printf("\nValues = ");
	node *p = h->next;
	while(p!=NULL){
		printf("%d ",p->val);
		p = p->next;
	}
}
