/*
Program to implement queue using array
S4-R-030
01-01-2015
*/

#include<stdio.h>
#define MAX 4

struct queue{
	int arr[MAX];
	int front;
	int rear;
}s;

void push(int);
int pop();
void display();
int overflow();
int underflow();
void search(int);

int main(){
	int choice,val;
	s.front = 0;
	s.rear = -1;
	printf("\n-----MENU-----\n1.ENQUEUE\n2.DEQUEUE\n3.Print all values\n4.Search for item\n5.Exit");
	do{
		printf("\nSelect your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(overflow()){
					printf("\nQueue overflow\n");
					break;
				}
				printf("\nEnter a value : ");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				if(underflow()){
					printf("\nQueue is empty\n");
					break;
				}
				val = pop();
				printf("\nValue = %d\n",val);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nEnter key to search\n");
				scanf("%d",&val);
				search(val);
			case 5:
				break;
			default:
				printf("\nInvalid choice, try again\n");
		}
	}while(choice!=5);
	return 0;
}

void push(int val){
	s.arr[++s.rear] = val;
}

int pop(){
	return s.arr[s.front++];
}

void display(){
	int i;
	printf("\nContents of the Queue is\n");
	for(i=s.front;i<=s.rear;i++)
		printf("%d\t",s.arr[i]);
}

int overflow(){
	if(s.rear==MAX-1)
		return 1;
	return 0;
}

int underflow(){
	if(s.rear==s.front-1)
		return 1;
	return 0;
}

void search(int key){
	int i;
	for(i=s.front;i<=s.rear;i++)
		if(s.arr[i]==key){
			printf("\nElement found at %d\n",i+1-s.front);
			return;
		}
	printf("\nElement not found in queue\n");
}
