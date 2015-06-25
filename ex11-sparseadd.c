/*
Exp no:11
Program to add two sparse matrices using array
S3-R-030 Jayadeep
08/01/2015
*/

#include<stdio.h>

int sparseIn(int [][3],int,int);
int sparseAdd(int [][3],int [][3],int [][3],int,int);
void sparseDisp(int [][3],int,int,int);

int main(){
	int sp1[20][3],sp2[20][3],sp3[20][3],m,n,p,q,r;
	printf("\nEnter no. of rows and coulmns of Matrix 1 and 2 :");
	scanf("%d%d",&m,&n);
	printf("\nEnter sparse matrix 1 \n");
	p = sparseIn(sp1,m,n);
	printf("\nEnter sparse matrix 2 \n");
	q = sparseIn(sp2,m,n);
	r = sparseAdd(sp1,sp2,sp3,p,q);
	printf("\nResult of addition is \n");
	sparseDisp(sp3,m,n,r);
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

int sparseAdd(int sp1[][3], int sp2[][3],int sp3[][3], int m, int n){
	int i,j,r=0;
	for(i=0,j=0;i<m&&j<n;){
		if(sp1[i][0]==sp2[j][0]&&sp1[i][1]==sp2[j][1]){
			sp3[r][0] = sp1[i][0];
			sp3[r][1] = sp1[i][1];
			sp3[r++][2] = sp1[i++][2]+sp2[j++][2];
		}else if((sp1[i][0]<sp2[j][0])||((sp1[i][0]==sp2[j][0])&&(sp1[i][1]<sp2[j][1]))){
			sp3[r][0] = sp1[i][0];
			sp3[r][1] = sp1[i][1];
			sp3[r++][2] = sp1[i++][2];
		}else{
			sp3[r][0] = sp2[j][0];
			sp3[r][1] = sp2[j][1];
			sp3[r++][2] = sp2[j++][2];
		}
	}

	while(i<m){
		sp3[r][0] = sp1[i][0];
		sp3[r][1] = sp1[i][1];
		sp3[r++][2] = sp1[i++][2];
	}
	while(j<m){
		sp3[r][0] = sp2[j][0];
		sp3[r][1] = sp2[j][1];
		sp3[r++][2] = sp2[j++][2];
	}
	return r;
}

void sparseDisp(int sp[][3], int m, int n, int r){
	int i,j,k=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(k<=r&&sp[k][0]==i&&sp[k][1]==j)
				printf("%d\t",sp[k++][2]);
			else
				printf("0\t");
		}
		printf("\n");
	}
}
