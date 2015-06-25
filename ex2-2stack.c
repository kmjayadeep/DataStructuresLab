/*
Program to implement 2 variable sized stack using a single array
S4 CSE 30
16-12-2014
*/
#include<stdio.h>
#define MAX 4

struct stack{
	int arr[MAX];
	int top1,top2;
}s;

void push(int,int);
int pop(int);
void display(int);
int underflow(int);
int overflow();

int main(){
	int choice,stack,val;
	s.top1=-1;
	s.top2=MAX;
	while(1){
		printf("\n-------MENU-------\n1. PUSH\n2. POP\n3. Display all items\n4. Exit\nEnter your choice\n");
		scanf("%d",&choice);
		if(choice==1){
			if(overflow())
				printf("\nStack Overflow\n");
			else{
				printf("\nEnter stack to operate: ");
				scanf("%d",&stack);
				printf("\nEnter a value\n");
				scanf("%d",&val);
				push(stack,val);
			}

		}
		else if(choice==2){
			printf("\nEnter stack : ");
			scanf("%d",&stack);
			if(underflow(stack))
				printf("\nStack is empty\n");
			else{
				val = pop(stack);
				printf("\nValue = %d\n",val);
			}
		}
		else if(choice==3){
			printf("\nEnter stack: ");
			scanf("%d",&stack);
			display(stack);
		}
		else if(choice==4)
			break;
		else
			printf("\nInvalid choice\n");
	}
	return 0;
}

void push(int stack,int val){
	if(stack==1){
		s.arr[++s.top1]=val;
		display(1);
	}
	else if(stack==2){
		s.arr[--s.top2]=val;
		display(2);
	}
}

int pop(int stack){
	if(stack==1)
		return (s.arr[s.top1--]);
	else if(stack==2)
		return (s.arr[s.top2++]);

}

void display(int stack){
	int i;
	printf("\nContents of Stack %d is : ",stack);
	if(stack==1)
		for(i=s.top1;i>=0;i--)
			printf("%d\t",s.arr[i]);
	else if(stack==2)
		for(i=s.top2;i<MAX;i++)
			printf("%d\t",s.arr[i]);
}

int underflow(int stack){
	if(stack==1){
		if(s.top1==-1)
			return 1;
		return 0;
	}else if(stack==2){
		if(s.top2==MAX)
			return 1;
		return 0;
	}
}

int overflow(){
	if(s.top1==s.top2-1)
		return 1;
	return 0;
}

