/*
Exp no. 22
Implementation of binary search tree operations
S4-R-030
30-03-2015
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *l,*r;
};

typedef struct node node;
void insert(int,node**);
void inOrder(node*);
node* findMin(node*);
node* findMax(node*);
int noNodes(node*);
int noLeaf(node*);
int noSingle(node*);

int main(){
	int c,b;
	node *root=NULL,*t;
	printf("--------------MENU------------------\n"
	"1. Insert\n2.Find Largest\n3.Find Smallest\n4.No.of nodes\n5.No of leafnodes\n6.No of nodes having one child"
	"\n7.Exit\n"
	);
	do{
		printf("\nEnter your choice : ");
		scanf("%d",&c);
		switch(c){
		case 1:
				printf("Enter the value to be added : ");
				scanf("%d",&b);
				insert(b,&root);
				inOrder(root);
				break;
		case 2:
			t=findMax(root);
			printf("\nLargest Element = %d\n",t->val);
			break;
		case 3:
			t=findMin(root);
			printf("\nSmallest Element = %d\n",t->val);
			break;
		case 4:
			printf("\nNo of Nodes = %d ",noNodes(root));
			break;
		case 5:
			printf("\nNo of Leaf Nodes = %d ",noLeaf(root));
			break;
		case 6:
			printf("\nNo of Nodes having single child = %d ",noSingle(root));
			break;
		}
	}while(c!=7);

}

void insert(int v,node **t){
	node *p=*t;
	if(!p){
		p = (node*)malloc(sizeof(node));
		*t=p;
		p->val=v;
		p->r=NULL;
		p->l=NULL;
	}else{
		if(v< p->val)
			insert(v,&((*t)->l));
		else
			insert(v,&((*t)->r));
	}
}

void inOrder(node *t){
	if(t){
		inOrder(t->l);
		printf("%d ",t->val);
		inOrder(t->r);
	}
}

node* findMin(node* r){
	if(!r) return 0;
	if(r->l)
		return findMin(r->l);
	return r;
}

node* findMax(node* r){
	if(!r) return 0;
	if(r->r)
		return findMax(r->r);
	return r;
}

int noNodes(node* r){
	if(!r)
		return 0;
	return noNodes(r->l)+noNodes(r->r)+1;
}

int noLeaf(node* r){
	if(!r)
		return 0;
	if(!r->r&&!r->l)
		return 1;
	return noLeaf(r->l)+noLeaf(r->r);
}


int noSingle(node* r){
	if(!r)
		return 0;
	if(r->l&&r->r)
		return noSingle(r->l)+noSingle(r->r);
	else if(!r->l&&!r->r)
		return 0;
	else if(!r->r)
		return noSingle(r->l)+1;
	else if(!r->l)
		return noSingle(r->r)+1;
	else
		return 0;
}

