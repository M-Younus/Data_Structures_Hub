#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;	
};

int Count(Node* head){
	int c=0;
	while(head!=NULL){
		head=head->next;
		c++;
	}
	return c;
}

void reversePrint(Node* node){
	Node* temp=node;
	int size=Count(node);
	int ar[size];int i=0;
	while(node!=NULL){
		ar[i]=node->data;
		node=node->next;
		i++;
	}
	for(i=size-1;i>=0;i--)
	printf("\n%d",ar[i]);
}

void append(Node** put,int val,int index){
	Node* temp=*put;
	int i=0;
	while(i<=index){
		puts("\nwhile\n");
		if(i==index-1){
			puts("\nif\n");
			Node* t=(Node*)malloc(sizeof(Node));
			Node* f=(*put)->next;
			puts("\nlink");
			t->data=val;
			t->next=f;
			(*put)->next=t;
			i++;
		}
		else{
			puts("\nelse\n");
			(*put)=(*put)->next;
			i++;
		}
	}
	*put=temp;
}

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

void Delete(Node* head,int val){
	Node* temp=head;int chk=0;
	Node* old,t;old=head;
	while(head!=NULL){
		chk++;
		if((head->data==val)&&chk==1){
			temp=head->next;
			free(head);
			head=temp;
			old=head;
		}
		if(head->data!=val){
			old=head;
			head=head->next;
		}
		else{
			old->next=head->next;
			free(head);
			head=old->next;
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
	
	//append
//	puts("\nappend 5 at inex 2");
//	append(&head,5,2);	
//	append(&head,7,1);
//	append(&head,9,5);
	//reverse
//	reversePrint(head);
	puts("\nBefore Delete");
	Print(head);
	printf("Total items in list:%d\n",Count(head));
	printf("Want to delete:");
	choice=getche();puts("");
	if(choice=='y'){
		printf("Enter value for deleting:");
		scanf("%d",&val);
		Delete(head,val);
	}
}

