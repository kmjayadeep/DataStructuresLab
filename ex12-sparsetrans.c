/*
Exp no:12
Program to find transpose of sparse matrix using array
S3-R-030 Jayadeep
08/01/2015
*/

#include<stdio.h>

int sparseIn(int [][3],int,int);
void sparseTrans(int [][3],int);
void sparseDisp(int [][3],int,int,int);
void swap(int*,int*);

int main(){
	int sp[20][3],m,n,p;
	printf("\nEnter no. of rows and coulmns of Matrix:");
	scanf("%d%d",&m,&n);
	printf("\nEnter Matrix\n");
	p = sparseIn(sp,m,n);
	sparseTrans(sp,p);
	printf("\nResult of Transpose is \n");
	sparseDisp(sp,n,m,p);
	return 0;
}

int sparseIn(int sp[][3],int m,int n){
	int i,j,r=0,t;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&t);
			if(t!=0){
				sp[r][0] = i;
				sp[r][1] = j;
				sp[r++][2] = t;
			}
		}
	}
	return r;
}

void sparseTrans(int sp[][3],int n){
	int i,j;

	for(i=0;i<n;i++){
		swap(sp[i],sp[i]+1);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if((sp[j][0]>sp[j+1][0])||(sp[j][0]==sp[j+1][0]&&sp[j][1]>sp[j+1][1])){
				swap(sp[j],sp[j+1]);
				swap(sp[j]+1,sp[j+1]+1);
				swap(sp[j]+2,sp[j+1]+2);
			}
		}
	}
}

void swap(int* a,int* b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void sparseDisp(int sp[][3], int m, int n, int r){
	int i,j,k=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(sp[k][0]==i&&sp[k][1]==j)
				printf("%d\t",sp[k++][2]);
			else
				printf("0\t");
		}
		printf("\n");
	}
}
