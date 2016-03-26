#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node* next;
};
void insert(Node** head,int val){
	Node* q=(Node*)malloc(sizeof(Node*));
	q->data=val;
	q->next=*head;
	*head=q;
}
void disp(Node* h){
	while(h!=NULL){
		printf("\n%d",h->data);
		h=h->next;
	}
}
int count(Node* np){
	int c=0;
	while(np!=NULL){
		c++;
		np=np->next;
	}
	return c;
}
main(){
	Node* head=NULL;
	
	insert(&head,3);
	insert(&head,4);
	puts("List is:");
	disp(head);
	printf("\nTotal items:%d",count(head));

	
	
}
