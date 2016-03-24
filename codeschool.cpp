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
int Count(Node* head){
	int c=0;
	while(head!=NULL){
		head=head->next;
		c++;
	}
	return c;
}
void Delete(Node* head,int val){
	Node* temp=head;
	while(head!=NULL){
		if(head->data!=val){
			head=head->next;
		}
		else{
			head=head->next;
			head=head->next;
		}
	}
	head=temp;
	
	puts("After Delete");
	Print(head);
	printf("Total items in list:%d\n",Count(head));
}
int main(){
	Node* head=NULL;
	printf("How many numbers?\n");
	int n,i,x,val;char choice;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the num\n");
		scanf("%d",&x);
		Insert(&head,x);
	}
	puts("Before Delete");
	Print(head);
	printf("Total items in list:%d\n",Count(head));
	printf("Want to delete:");
	choice=getche();
	if(choice=='y'){
		printf("Enter value for deleting:");
		scanf("%d",&val);
		Delete(head,val);
	}
}

