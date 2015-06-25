/*
Exp no.24
Program to implement quick sort
S4-R-030
30-03-2015
*/

#include<stdio.h>
#define MAX 100
void quickSort(int[],int,int);
int main(){

	int i,n,a[MAX];
	printf("\nEnter no. of values : ");
	scanf("%d",&n);
	printf("\nEnter values : ");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	quickSort(a,0,n-1);
	printf("\nSorted List : ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

void quickSort(int a[],int start,int end){

	int i=start,j=end,p=start,t;

	if(start>=end)
		return;

	while(i<j){
		while(a[i]<a[p]&&i<=end) i++;
		while(a[j]>a[p]&&j>=0) j--;
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}

	t=a[j];
	a[j]=a[p];
	a[p]=t;
	quickSort(a,start,j-1);
	quickSort(a,j+1,end);

}
