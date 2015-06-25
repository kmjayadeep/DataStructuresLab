/*
Program to implement stack using array
S4 CSE 30
16-12-2014
*/
#include<stdio.h>
#define MAX 5

struct stack{
	int arr[MAX];
	int top;
}s;

void push(int);
int pop();
void display();
void search(int);

int main(){
	int choice,val;
	s.top = -1;
	printf("\n-------MENU-------\n1. PUSH\n2. POP\n3. Display all items\n4. Search for item\n5. Exit");
	while(1){
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		if(choice==1){
			if(s.top==MAX-1){
				printf("\nStack overflow");
				continue;
			}
			printf("\nEnter a value : ");
			scanf("%d",&val);
			push(val);
			display();
		}
		else if(choice==2){
			if(s.top==-1){
				printf("\nStack underflow");
				continue;
			}
			val = pop();
			printf("\nvalue = %d\n",val);
		}
		else if(choice==3){
			if(s.top==-1){
				printf("\nStack is empty\n");
				continue;
			}
			display();
		}
		else if(choice==4){
			printf("\nEnter a key to search\n");
			scanf("%d",&val);
			search(val);
		}
		else if(choice==5)
			break;
		else
			printf("\nInvalid choice\n");
	}
	return 0;
}

void push(int val){
	s.top++;
	s.arr[s.top] = val;
}

int pop(){
	s.top--;
	return s.arr[s.top+1];
}

void display(){
	printf("\nContents : ");
	int i=0;
	while(i<=s.top){
		printf("%d\t",s.arr[s.top-i]);
		i++;
	}
}

void search(int key){
	int i=0;
	while(i<=s.top){
		if(s.arr[i]==key){
			printf("\nElement found at %d\n",s.top-i+1);
			return;
		}
		i++;
	}
	printf("\nElement not found in stack\n");
}

