/*
Exp no.26
Program to implement heap sort
S4-R-030
30-03-2015
*/

#include<stdio.h>
#define MAX 100
void heapSort(int[],int);
void heapify(int[],int,int);
int main(){
	int i,n,a[MAX];
	printf("\nEnter no. of values : ");
	scanf("%d",&n);
	printf("\nEnter values : ");
	for(i=0;i<n;i++) scanf("%d",a+i);
	heapSort(a,n);
	printf("\nSorted List : ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

void heapSort(int a[],int n){
	int m,i,t;
	for(i=n/2;i>=0;i--)
		heapify(a,i,n);
	for(i=n-1;i>0;i--){
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		heapify(a,0,i);
	}
}

void heapify(int a[],int i, int n){
	int l,r,lar=i,t;
	l=2*i;
	r=l+1;
	if(l<n&&a[l]>a[i]) lar=l;
	if(r<n&&a[r]>a[lar]) lar=r;
	if(lar!=i){
		t=a[lar];
		a[lar]=a[i];
		a[i]=t;
		heapify(a,lar,n);
	}
}
