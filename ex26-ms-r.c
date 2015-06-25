/*
Exp no.26
Program to implement merge sort
S4-R-030
30-03-2015
*/

#include<stdio.h>
#define MAX 100
void mergeSort(int[],int,int);
void merge(int[],int,int);
int main(){
	int i,n,a[MAX];
	printf("\nEnter no. of values : ");
	scanf("%d",&n);
	printf("\nEnter values : ");
	for(i=0;i<n;i++) scanf("%d",a+i);
	mergeSort(a,0,n-1);
	printf("\nSorted List : ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

void mergeSort(int a[],int s,int e){
	int m,i,j;
	if(s==e)
		return;
	m = (s+e)/2;
	mergeSort(a,s,m);
	mergeSort(a,m+1,e);
	merge(a,s,e);
}

void merge(int a[],int s, int e){
	int m,i,j,k=0,l=0;
	int T[MAX];
	m = (s+e)/2;
	for(i=s,j=m+1;i<=m&&j<=e;){
		if(a[i]<a[j]) T[k++]=a[i++];
		else T[k++]=a[j++];
	}
	while(i<=m) T[k++]=a[i++];
	while(j<=e) T[k++]=a[j++];
	i=s;
	while(l<k) a[i++]=T[l++];

}
