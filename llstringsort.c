#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct strings{
	struct strings* next;
	struct strings* prev;
	char data[20];
};
typedef struct strings strings;

void insert(strings*,char*);
void sortData(strings*);

int main(){
	int n,i;
	strings head,*p;
	p = &head;
	char str[20];
	printf("\nEnter no. of Strings to insert : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter String : ");
		scanf("%s",str);
		insert(p,str);
		p = p->next;
	}
	sortData(&head);
	printf("\nAfter Sorting : \n");
	p=head.next;
	while(p){
		printf("%s\n",p->data);
		p = p->next;
	}
	return 0;
}

void insert(strings* s,char* str){
	s->next = (strings*) malloc(sizeof(strings));
	strcpy(s->next->data,str);
	s->next->next=0;
	s->next->prev=s;
}

void sortData(strings* s){
	strings *small,*i,*j,*t;

	for(i=s->next;i;i=i->next){
		small = i;
		for(j=i->next;j;j=j->next){
			if(strcmp(j->data,small->data)<0)
				small=j;
		}
		if(small!=i){
			t=small->next;
			small->next=i->next;
			i->next=t;
			t=small->prev;
			small->prev=i->prev;
			i->prev=t;
			small->prev->next=small;
			i->prev->next=i;
			if(small->next)
				small->next->prev=small;
			if(i->next)
				i->next->prev=i;
		}
	}


}