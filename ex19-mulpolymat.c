/*
Exp no:19
Programt to implement multiplication of two polynomials using linked list
S4 CSE 30
26-03-2015
*/

#include<stdio.h>
#define MAX 10


int read(int[][2]);
void display(int[][2],int);
int mult(int[][2],int[][2],int[][2],int,int);

int main(){
	int p1[MAX][2],p2[MAX][2],p3[MAX][2],m,n,o;
	printf("Addition of Polynomial Numbers\nEnter two polynomials");
	m=read(p1);
	n=read(p2);
	o = mult(p1,p2,p3,m,n);
	printf("\nResult : ");
	display(p3,o);
	printf("\n");
	return 0;
}

int read(int p[][2]){
	int i=0,n,c,e;
	printf("\nEnter no. of terms in polynomial : ");
	scanf("%d",&n);
	printf("Enter Polynomial as series of coefficiend and exponent\n");
	while(i<n){
		scanf("%d%d",&c,&e);
		p[i][0]=c;
		p[i++][1]=e;
	}
	return n;
}


void display(int p[][2],int n){
	int i=0;
	while(i<n){
		printf(" %dX^%d ",p[i][0],p[i][1]);
		i++;
	}
}

int mult(int p1[][2],int p2[][2], int p3[][2], int m, int n){
	int i,j,c=0,l,t;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			p3[c][0]=p1[i][0]*p2[j][0];
			p3[c++][1]=p1[i][1]+p2[j][1];
		}
	}
	for(i=0;i<c;i++){
		l = i;
		for(j=i;j<c;j++){
			if(p3[j][1]>p3[j][1])
				l=j;
		}
		t=p3[i][0];
		p3[i][0]=p3[l][0];
		p3[l][0]=t;
                t=p3[i][1];
                p3[i][1]=p3[l][1];
                p3[l][1]=t;
	}
	for(i=0;i<c-1;i++){
		if(p3[i][1]==p3[i+1][1]){
			p3[i][0]+=p3[i+1][0];
			c--;
			for(j=i+1;j<c;j++){
				p3[j][0]=p3[j+1][0];
				p3[j][1]=p3[j+1][1];
			}

		}
	}
	return c;

}

/***********************SAMPLE OUTPUT***************************

Addition of Polynomial Numbers
Enter two polynomials
Enter no. of terms in polynomial : 3
Enter Polynomial as series of coefficiend and exponent
5 3 10 2 10 0

Enter no. of terms in polynomial : 2
Enter Polynomial as series of coefficiend and exponent
12 2 3 1

Result :  60X^5  135X^4  30X^3  120X^2  30X^1 


Addition of Polynomial Numbers
Enter two polynomials
Enter no. of terms in polynomial : 2
Enter Polynomial as series of coefficiend and exponent
-23 4 43 2

Enter no. of terms in polynomial : 2
Enter Polynomial as series of coefficiend and exponent
3 2 34 -4

Result :  -69X^6  -782X^0  129X^4  1462X^-2 

****************************************************************/
