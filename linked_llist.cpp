#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node *link;
};

void append(Node *&head,int num){
	Node *temp;
	
	temp=(Node*)malloc(sizeof(Node));
	temp->data=num;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		Node *th;
		th=head;
		while(th->link!=NULL){
			th=th->link;
			th->link=temp;
			printf("pehla=%d next %u",th->data,th->link);
		}
	}
}
main(){
	struct Node *list1=NULL;
	append(list1,1);
	//printf("pehla=%d next %u",list1->data,list1->link);
	append(list1,3);
	//printf("\npehla=%d next %u",list1->data,list1->link);
}


