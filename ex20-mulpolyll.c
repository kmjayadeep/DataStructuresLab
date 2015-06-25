/*
Exp no:20
Programt to implement Multiplication of polynomials using linked list
S4 CSE 30
26-03-2015
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
poly* mul(poly*,poly*);
poly* create(int,int);
void sort(poly*);
void swap(int*,int*);

int main(){
	poly poly1,poly2,*poly3;
	printf("Addition of Polynomail Numbers\nEnter two polynomials");
	read(&poly1);
	read(&poly2);
	poly3 = mul(&poly1,&poly2);
	printf("\nResult : ");
	display(poly3);
	printf("\n");
	return 0;
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
		if(t->coeff<0)
			printf(" - %dX^%d",-1*t->coeff,t->power);
		else
			printf(" + %dX^%d",t->coeff,t->power);
		t = t->next;
	}
}

poly* mul(poly *x, poly*y){
	poly *c = (poly*) malloc(sizeof(poly));
	poly *k = c;
	poly *i,*j;
	c->next = NULL;
	for(i=x->next;i!=NULL;i=i->next){
		for(j=y->next;j!=NULL;j=j->next){
			if(i->coeff+j->coeff){
				c->next = create(i->coeff*j->coeff,i->power+j->power);
				c = c->next;
			}
		}
	}
	sort(k);
	return k;

}

poly* create(int a, int b){
	poly *c = (poly*) malloc(sizeof(poly));
	c->coeff = a;
	c->power = b;
	c->next = NULL;
	return c;
}

void sort(poly* p){
	poly *i,*j,*l;
        for(i=p->next;i!=NULL;i=i->next){
		l=i;
                for(j=i;j!=NULL;j=j->next){
			if(j->power>l->power)
				l = j;
                }
		swap(&(l->power),&(i->power));
		swap(&(l->coeff),&(i->coeff));
        }
	for(i=p->next;i->next!=NULL;i=i->next){
		if(i->power==i->next->power){
			i->coeff+=i->next->coeff;
			j=i->next;
			i->next=j->next;
			free(j);
		}
	}
}
void swap(int *a, int*b){
	int t;
	t = *a;
	*a=*b;
	*b=t;
}
