/*
Program to implement circular queue using array
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

void enqueue(int);
int dequeue();
void display();
int overflow();
int unverflow();

int main(){
	int choice,val;
	s.front = 0;
	s.rear = -1;
	printf("\n-----MENU-----\n1.ENQUEUE\n2.DEQUEUE\n3.Print all values\n4.Exit\n");
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
				enqueue(val);
				display();
				break;
			case 2:
				if(underflow()){
					printf("\nQueue is empty\n");
					break;
				}
				val = dequeue();
				printf("\nValue = %d\n",val);
				display();
				break;
			case 3:
				if(underflow())
					printf("\nqueue is empty\n");
				else
					display();
			case 4:
				break;
			default:
				printf("\nInvalid choice, try again\n");
		}
	}while(choice!=4);
	return 0;
}

void enqueue(int val){
	s.arr[(++s.rear)%MAX] = val;
}

int dequeue(){
	return s.arr[(s.front++)%MAX];
}

void display(){
	int i;
	printf("Contents of Queue is :\n");
	for(i=s.front;i<=s.rear;i++)
		printf("%d\t",s.arr[i%MAX]);
}

int overflow(){
	if((s.rear-s.front)==MAX-1)
		return 1;
	return 0;
}

int underflow(){
	if(s.rear<s.front)
		return 1;
	return 0;
}
