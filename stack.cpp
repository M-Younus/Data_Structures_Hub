#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node* next;
};
void push(Node** head,int val){
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
int pop(Node** hd){
	
//	Node* temp=(*hd);
	int ext=(*hd)->data;
//	free(*hd);
//	Node* t=temp;
//	printf("\nsds%d",temp->data);
//	exit(0);
//	free(*hd);
	(*hd)=(*hd)->next;
	return ext;
	
}
main(){
	Node* head=NULL;
	
	push(&head,3);
	push(&head,4);
	push(&head,56);
	push(&head,34);
	push(&head,89);
	puts("Before pop");
	puts("List is:");
	disp(head);
	printf("\nTotal items:%d",count(head));
	printf("pop item is %d",pop(&head));
	printf("pop item is %d",pop(&head));
	puts("After pop");
	puts("List is:");
	disp(head);
	printf("\nTotal items:%d",count(head));

	
	
}
