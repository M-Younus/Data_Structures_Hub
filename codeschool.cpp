#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;	
};
void Insert(Node** pointerHead,int x){
	Node* t;
	Node* temp=*pointerHead;
	if(*pointerHead==NULL){
	temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=0;
	*pointerHead=temp;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		t=(Node*)malloc(sizeof(struct Node));
		t->data=x;
		t->next=0;
		temp->next=t;
	}
		
}
void Print(Node* head){
	printf("List is: ");
	while(head!=NULL){
		printf(" %d",head->data);
		head=head->next ;
	}
	printf("\n");
}
int main(){
	Node* head=NULL;
	printf("How many numbers?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the num\n");
		scanf("%d",&x);
		Insert(&head,x);
	}
	Print(head);
}

