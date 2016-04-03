#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;Node* link;
};

void disp(Node* head){
	while(head!=NULL){
		printf("\n%d",head->data);
		head=head->link;
	}
}
void enq(Node** hd,int val){
	Node* temp;
	Node* q=(Node*)malloc(sizeof(Node));
	Node* cp;
//	q=(*hd);
	if((*hd)==NULL){
		temp=(Node*)malloc(sizeof(Node));
		temp->data=val;
		temp->link=NULL;
	}
	else{
		while((*hd)!=NULL){
			
			q->data=val;
			q->link=0;
			if((*hd)->link!=NULL)
				{
				cp=(*hd);
				(*hd)->link=q;
				(*hd)=cp->link;
				}

			}

	}
	(*hd)=temp;
	
}
main(){
	Node* head=NULL;
	enq(&head,1);
	enq(&head,2);
//	enq(&head,6);
	
	disp(head);
}
