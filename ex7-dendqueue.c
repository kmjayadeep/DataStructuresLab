/*
Exp No:7
Program to implement double ended queue using array
S4-R-030
01-01-2015
*/

#include<stdio.h>
#define MAX 3

struct queue{
	int arr[MAX];
	int front;
	int rear;
}s;

void enqueue(int,int);
int dequeue(int);
void display();
int overflow(int);
int unverflow();

int main(){
	int choice,val,side,io,ch;
	s.front = 0;
	s.rear = -1;
	while(1){
		printf("\nSelect type of Double Ended Queue\n1. Input Restricted\n2. Output Restricted\n\nSelect your option (Enter 0 for exit)\n");
		scanf("%d",&io);
		if(!io)
			break;
		printf("\n-----MENU-----\n1.ENQUEUE\n2.DEQUEUE\n3.Print all values\n4.Go Back\n");

		do{
			printf("\nSelect your choice : ");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					if(io==2){
						printf("\nWhere do you want to ENQUEUE? (1. FRONT, 2. REAR) \n");
						scanf("%d",&side);
					}
					else
						side = 2;
					if(overflow(side)){
						printf("\nQueue overflow\n");
						break;
					}
					printf("\nEnter a value : ");
					scanf("%d",&val);
					enqueue(side,val);
					display();
					break;
				case 2:
					if(underflow()){
						printf("\nQueue is empty\n");
						break;
					}
					if(io==1){
						printf("\nFrom where do you want to DEQUEUE? (1. FRONT, 2. REAR)\n");
						scanf("%d",&side);
					}
					else
						side = 1;
					val = dequeue(side);
					printf("\nValue = %d\n",val);
					display();
					break;
				case 3:
					if(underflow())
						printf("\nQUEUE is Empty\n");
					else
						display();
				case 4:
					break;
				default:
					printf("\nInvalid choice, try again\n");
			}
		}while(choice!=4);
	}
	return 0;
}

void enqueue(int side,int val){
	if(side==1)
		s.arr[--s.front] = val;
	else if(side==2)
		s.arr[++s.rear] = val;
}

int dequeue(int side){
	if(side==1)
		return s.arr[s.front++];
	else if(side==2)
		return s.arr[s.rear--];
}

void display(){
	int i;
	printf("Contents of Queue is :\n");
	for(i=s.front;i<=s.rear;i++)
		printf("%d\t",s.arr[i]);
}

int overflow(int side){
	if(side==2)
		if(s.rear==MAX-1)
			return 1;
		else return 0;
	else
		if(s.front==0)
			return 1;
		else
			return 0;
}

int underflow(){
	if(s.rear==s.front-1)
		return 1;
	return 0;
}
