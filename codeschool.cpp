#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;	
};
//struct Node* head;
Node* Insert(Node* head,int x){
	Node* temp=(Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	return head=temp;
	
}
void Print(Node* head){
//	Node* temp=head;
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
		head=Insert(head,x);
		Print(head);
	}
}

