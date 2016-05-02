#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
struct Node{
	int data; Node* link;
};

void disp(Node* head){
	while (head != NULL){
		printf("\n%d", head->data);
		head = head->link;
	}
}
void enq(Node** hd, int val){
	Node* temp;
	temp = (*hd);
	Node* q = (Node*)malloc(sizeof(Node));
	Node* cp = (*hd);
	if ((*hd) == NULL){
		puts("if");
		temp = (Node*)malloc(sizeof(Node));
		temp->data = val;
		temp->link = NULL;
		cp = temp;
	}
	else{
		q->data = val;
		q->link = 0;
		while (temp != NULL){
			puts("Ds");
			(*hd)->link = q;
			temp = temp->link;
			(*hd) = temp;
		}
	}
	(*hd) = cp;
}
int main(){
	Node* head = NULL;
	enq(&head, 1);
	//enq(&head, 2);
	//	enq(&head,5);
	//	enq(&head,6);

	disp(head);
	getchar();
	return 0;
}
