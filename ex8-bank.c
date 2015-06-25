/*
Exp No: 8
Program to implement token processing at bank
S4-R-030-Jayadeep
01-01-2015
*/

#include<stdio.h>
#define MAX 3

typedef struct {
	int tno;
	char name[10];
}cust;


struct queue{
	cust c[MAX];
	int front;
	int rear;
	int counter;
}q;

void enqueue(cust);
cust dequeue();
void display();
int overflow();
int underflow();
void count();

int main(){
	int choice,val;
	cust cus;
	q.front = 0;
	q.rear = -1;
	q.counter=0;
	printf("\n-----MENU-----\n1.Add New Customer\n2.Delete a Customer\n3.Display details of customer in front\n4.Exit");
	do{
		printf("\nSelect your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(overflow()){
					printf("\nQueue is full\n");
					break;
				}
				printf("\nEnter Customer Name : ");
				scanf("%s",cus.name);
				cus.tno = ++q.counter;
				enqueue(cus);
				break;
			case 2:
				if(underflow()){
					printf("\nQueue is empty\n");
					break;
				}
				cus = dequeue();
				printf("\nToken No: %d\tCustomer Name: %s\n",cus.tno,cus.name);
				count();
				break;
			case 3:
				if(underflow())
					printf("\nQueue is empty\n");
				else
					display();
				break;
			case 4:
				break;
			default:
				printf("\nInvalid choice, try again\n");
		}
	}while(choice!=4);
	return 0;
}

void enqueue(cust cus){
	q.c[++q.rear] = cus;
	count();
}

cust dequeue(){
	return q.c[q.front++];
}

void display(){
	printf("\nToken Id: %d, Name: %s\n",q.c[q.front].tno,q.c[q.front].name);
}

int overflow(){
	if(q.rear==MAX-1)
		return 1;
	return 0;
}

int underflow(){
	if(q.rear==q.front-1)
		return 1;
	return 0;
}

void count(){
	int count;
	count = q.rear-q.front+1;
	printf("\nNo of customers in Queue is %d\n",count);
}
