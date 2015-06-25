/*
Exp no:18
Programt to implement addition of polynomials using linked list
S4 CSE 30
19-03-2015
*/

#include<stdio.h>
#include<stdlib.h>


struct poly{
	int coeff;
	int power;
	struct poly* next;
}p;

typedef struct poly poly;

void read(poly*);
void display(poly*);
poly* add(poly*,poly*);

int main(){
	poly poly1,poly2,*poly3;
	printf("Addition of Polynomail Numbers\nEnter two polynomials");
	read(&poly1);
	read(&poly2);
	poly3 = add(&poly1,&poly2);
	printf("\nResult : ");
	display(poly3);
	printf("\n");

}

void read(poly* p){
	int i=0,n,c,e;
	poly *t = p;
	printf("\nEnter no. of terms in polynomial : ");
	scanf("%d",&n);
	printf("Enter Polynomial as series of coefficiend and exponent\n");
	while(i++<n){
		scanf("%d%d",&c,&e);
		t->next = (poly*) malloc(sizeof(poly));
		t->next->coeff = c;
		t->next->power = e;
		t->next->next = NULL;
		t = t->next;
	}
}


void display(poly *p){
	poly *t = p->next;
	while(t!=NULL){
		printf("%dX%d ",t->coeff,t->power);
		t = t->next;
	}
}

poly* add(poly *a, poly*b){
	poly *c = (poly*) malloc(sizeof(poly));
	poly *k = c;
	c->next = NULL;
	a = a->next;
	b = b->next;
	while(a!=NULL&&b!=NULL){
//		c->next = (poly*) malloc(poly);
//		c = c->next;
		if(a->power==b->power){
			c->next = a;
			a->coeff+=b->coeff;
			a = a->next;
			b = b->next;
		}else if(a->power>b->power){
			c->next = a;
			a = a->next;
		}else{
			c->next = b;
			b = b->next;
		}
		c = c->next;
	}

	if(a!=NULL)
		c->next = a;
	if(b!=NULL)
		c->next = b;
	return k;

}
