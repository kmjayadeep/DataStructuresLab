/*
Exp no.13
Program to add two sparse matrices using linked list
S3-R-030
11-02-2015
*/

#include<stdio.h>
#include<stdlib.h>

struct sparse{
	int mat[3];
	struct sparse* next;
};
typedef struct sparse sparse;

void sparseIn(sparse*,int,int);
void sparseDisp(sparse,int,int);
void sparseAdd(sparse*,sparse,sparse,int,int);

sparse head;

int main(){
	sparse s1,s2,s3,*t;
	int m,n,p;
	s1.next = s2.next = NULL;
	printf("\nEnter no. of rows and columns of Matrices : ");
	scanf("%d %d",&m,&n);
	sparseIn(&s1,m,n);
	sparseIn(&s2,m,n);
	sparseAdd(&s3,s1,s2,m,n);
	printf("\nResult Matrix is :\n");
	sparseDisp(s3,m,n);
	return 0;
}

void sparseIn(sparse *s, int m,int n){
	int t,i,j;
	sparse *p = s;
	printf("\nEnter Matrix:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			scanf("%d",&t);
			if(t!=0){
				p->next = (sparse*) malloc(sizeof(sparse));
				p = p->next;
				p->mat[0]=i;
				p->mat[1]=j;
				p->mat[2]=t;
				p->next = NULL;
			}
		}
}

void sparseAdd(sparse* s3,sparse s1,sparse s2,int m, int n){
	int i,j;
	sparse *t1=s1.next,*t2=s2.next,*t,*p=s3;

	while(t1!=NULL&&t2!=NULL){
		t = (sparse*) malloc(sizeof(sparse));
		t->next = NULL;
		if(t1->mat[0]==t2->mat[0]&&t1->mat[1]==t2->mat[1]){
			t->mat[0] = t1->mat[0];
			t->mat[1] = t1->mat[1];
			t->mat[2] = t1->mat[2]+t2->mat[2];
			t1 = t1->next;
			t2 = t2->next;
		}else if((t1->mat[0] < t2->mat[0])||(t1->mat[0]==t2->mat[0]&&t1->mat[1]< t2->mat[1])){
			t->mat[0]=t1->mat[0];
			t->mat[1]=t1->mat[1];
			t->mat[2]=t1->mat[2];
			t1=t1->next;
		}
		else{
			t->mat[0]=t2->mat[0];
			t->mat[1]=t2->mat[1];
			t->mat[2]=t2->mat[2];
			t2 = t2->next;
		}
		p->next=t;
		p = p->next;
	}
	if(t1!=NULL)
		p->next=t1;
	else
		p->next=t2;

}


void sparseDisp(sparse s,int m,int n){
	int i,j,k=0;
	sparse *p = s.next;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(p!=NULL&&p->mat[0]==i&&p->mat[1]==j){
				printf("%d\t",p->mat[2]);
				p = p->next;
			}
			else
				printf("0\t");
		}
		printf("\n");
	}

}
