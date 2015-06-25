/*
Exp no.25
Program to implement non-recursive quick sort
S4-R-030
30-03-2015
*/

#include<stdio.h>
#define MAX 100
void quickSort(int[],int);
void swap(int*,int*);
int main(){
	int i,n,a[MAX];
	printf("\nEnter no. of values : ");
	scanf("%d",&n);
	printf("\nEnter values : ");
	for(i=0;i<n;i++) scanf("%d",a+i);
	quickSort(a,n-1);
	printf("\nSorted List : ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void quickSort(int a[],int n){

	int i,j,s,e,p,t;
	int stack[MAX];
	int rear=-1;
	int front=0;
	stack[++rear]=0;
	stack[++rear]=n;

	while(rear>=front){

	s=stack[front++];
	e=stack[front++];
	i=s;j=e;
	p=s;
	while(i<j){
		while(a[i]<a[p]&&i<=e) i++;
		while(j>=0&&a[j]>a[p]) j--;
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}

	t=a[j];
	a[j]=a[s];
	a[s]=t;
	if(s<j-1){
	stack[++rear]=s;
	stack[++rear]=j-1;}
	if(e>j+1){
	stack[++rear]=j+1;
	stack[++rear]=e;}
	}

}
