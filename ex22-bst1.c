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
void preOrder(node*);
void postOrder(node*);
void del(node**,int);
node** findMin(node**);

int main(){
	int c,b;
	node *root=NULL,*t;
	printf("BST OPERATIONS \n 1.INSERT \n 2.DELETE \n 3.INORDER \n 4.PREORDER \n 5.POSTORDER \n 6.EXIT\n");
	do{
		printf("\nEnter your choice : ");
		scanf("%d",&c);
		switch(c){
		case 1:
				printf("Enter the value to be added : ");
				scanf("%d",&b);
				insert(b,&root);
				break;
		case 2:
			if(root==NULL)
				printf(" BST EMPTY!!");
			else{
				printf("Enter the element to be deleted : ");
				scanf("%d",&b);
				del(&root,b);
				printf("Element deleted: %d\n",b);
			}
			break;
		case 3:
			if(root==NULL)
			printf("BST empty ");
			else{
				printf("Inorder : ");
				inOrder(root);
			}
			break;
		case 4:
			if(root==NULL)
			printf("BST empty ");
			else{
				printf("Preorder :  ");
				preOrder(root);
			}
			break;
		case 5:
			if(root==NULL)
			printf("BST empty ");
			else{
				printf("Postorder :  ");
				postOrder(root);
			}
			break;

		}
	}while(c!=6);
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

void preOrder(node *t){
	if(t){
		printf("%d ",t->val);
		preOrder(t->l);
		preOrder(t->r);
	}
}

void postOrder(node *t){
	if(t){
		postOrder(t->l);
		postOrder(t->r);
		printf("%d ",t->val);
	}
}

void del(node **r,int v){
	node *p=*r,**t;

	if(!p)
		return;
	if(v< p->val){
		del(&(p->l),v);
	}else if(v > p->val){
		del(&(p->r),v);
	}else{
		if(!(p->l||p->r))
			*r=NULL;
		else if(!p->r)
			*r=p->l;
		else if(!p->l)
			*r=p->r;
		else{
			t=findMin(&(p->r));
			p->val=(*t)->val;
			p=*t;
			*t=NULL;
		}
		free(p);
	}
}

node** findMin(node** r){
	node *p=*r;
	if(!p) return 0;
	if(p->l)
		return findMin(&(p->l));
	return r;
}

