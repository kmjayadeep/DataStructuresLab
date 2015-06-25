/*
Exp no. 14
Program to convert infix to postfix and evaluate it
S4-R-030
17-02-2015
*/
#include<stdio.h>
#define MAX 50
struct stack{
	int arr[MAX];
	int top;
};


typedef struct stack stack;

void push(stack*,int);
int pop(stack*);
int priority(char);
int get(stack*);
int evaluate(stack*);
int isExp(int);
int calc(int, int ,char );

int main(){
	int choice,val,res,i;
	char c,x;
	stack s,ex;
	s.top = -1;
	ex.top=-1;
	printf("Enter your Expression\n");
	while((c=getchar())!='\n'){
		if(c>='0'&&c<='9'){
			push(&ex,c);
		}
		else if(c==')'){
			while((x = pop(&s))!='('){
				push(&ex,x);
		}
		}else{
			if(c=='(')
				push(&s,c);
			else if(priority(c)>=priority(get(&s))){
				push(&s,c);
			}else{
				while(priority(get(&s))>=priority(c)){
					x = pop(&s);
					push(&ex,x);
				}
				push(&s,c);
			}
		}

	}

	while(!empty(&s)){
		x = pop(&s);
		push(&ex,x);
	}
	printf("\nPostFix expression is :\n");
	for(i=0;i<=ex.top;i++){
		printf("%c",ex.arr[i]);
	}
	printf("\nResult = %d\n",evaluate(&ex));

	return 0;
}


void push(stack* s,int val){
	s->top++;
	s->arr[s->top] = val;
}


int pop(stack* s){
	s->top--;
	return s->arr[s->top+1];
}


int priority(char c){
	if(c==0)
		return -1;
	if(c=='(')
		return 0;
	else if(c=='+'||c=='-')
		return 1;
	else
		return 2;
}
int empty(stack *s){
	return (s->top==-1);
}
int get(stack* s){
	if(!empty(s))
		return s->arr[s->top];
	else
		return 0;
}
int evaluate(stack *s){
	stack temp;
	temp.top=-1;
	int a,b,i;
	for(i=0;i<=s->top;i++){
		if(!isExp(s->arr[i]))
			push(&temp,s->arr[i]-'0');
		else{
			b = pop(&temp);
			a = pop(&temp);
			push(&temp,calc(a,b,s->arr[i]));
		}
	}
	return temp.arr[0];

}
int calc(int a,int b, char e){
	if(e=='+')
		return a+b;
	else if(e=='-')
		return a-b;
	else if(e=='*')
		return a*b;
	else
		return a/b;
}

int isExp(int c){
	return (c=='+'||c=='-'||c=='/'||c=='*');
}

/*****************SAMPLE OUTPUT****************************

Enter your Expression
1-3-4/2*3

PostFix expression is :
13423*/--
Result = -2


Enter your Expression
6/2+5*(7-2*(1+2))

PostFix expression is :
62/57212+*-*+
Result = 8

Enter your Expression
4*3-2/1*6/(3-2)

PostFix expression is :
43*21632-/*/-
Result = 12


***********************************************************/
