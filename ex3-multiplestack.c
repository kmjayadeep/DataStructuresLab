/*
Program to implement multiple stack using array
S4 CSE 30
16-12-2014
*/
#include<stdio.h>
#define MAX 12

struct stack{
	int arr[MAX];
	int top[MAX];
	int stacks, stackmax;
}s;

void push(int,int);
int pop(int);
void display(int);
int underflow(int);
int overflow(int);

int main(){
	int choice,stack,val,stackmax,i;
	printf("\nEnter the no of stacks which you want to operate \n");
	scanf("%d",&(s.stacks));
	s.stackmax = MAX/s.stacks;
	for(i=0;i<s.stacks;i++){
		s.top[i] = s.stackmax*i-1;
	}
	while(1){
		printf("\n-------MENU-------\n1. PUSH\n2. POP\n3. Display all items\n4. Exit\nEnter your choice\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nEnter value\n");
			scanf("%d",&val);
			printf("\nEnter stack to operate: ");
			scanf("%d",&stack);
			if(overflow(stack-1))
				printf("\nStack Overflow");
			else
				push(stack-1,val);
		}
		else if(choice==2){
			printf("\nEnter stack : ");
			scanf("%d",&stack);
			if(underflow(stack-1)){
				printf("\nStack underflow\n");
			}
			else{
				val = pop(stack-1);
				printf("\nvalue = %d\n",val);
			}
		}
		else if(choice==3){
			printf("\nEnter stack: ");
			scanf("%d",&stack);
			display(stack-1);
		}
		else if(choice==4)
			break;
		else
			printf("\nInvalid choice\n");
	}
	return 0;
}

void push(int stack,int val){
	s.arr[++s.top[stack]] = val;
}

int pop(int stack){
	return (s.arr[s.top[stack]--]);
}

void display(int stack){
	if(underflow(stack)){
		printf("\nStack empty\n");
		return;
	}
	int i,top,start;
	start = s.stackmax*stack;
	top = s.top[stack];
	while(top>=start){
		printf("%d\t",s.arr[top]);
		top--;
	}
}

int overflow(stack){
	return (s.top[stack]==s.stackmax*(stack+1)-1);
}

int underflow(stack){
		if(s.top[stack]<s.stackmax*stack)
			return 1;
		return 0;
}
