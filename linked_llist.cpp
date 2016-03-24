//#include<stdio.h>
//#include<stdlib.h>
//struct Node{
//	int data;
//	Node *link;
//};
//
//void append(Node **head,int num){
//	Node *temp;
//	
//	temp=(Node*)malloc(sizeof(Node));
//	temp->data=num;
//	temp->link=NULL;
//	if(head==NULL){
//		*head=temp;
//	}
//	else{
//		Node *th;
//		th=*head;
//		while(th->link!=NULL){
//			th=th->link;
//			th->link=temp;
//			printf("pehla=%d next %u",th->data,th->link);
//		}
//	}
//}
//main(){
//	struct Node *list1=NULL;
//	append(&list1,1);
//	//printf("pehla=%d next %u",list1->data,list1->link);
//	append(&list1,3);
//	//printf("\npehla=%d next %u",list1->data,list1->link);
//}

//without functions
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node{
	int x;
	struct node *next;
};
main(){
	struct node *root=NULL;
	struct node *conductor=NULL;
	
	char choice;int num;
	printf("want to enter value:");
//	scanf("%c",&choice);
	choice=getche();puts("");
	if(choice=='y')
{
	root=(struct node*)malloc(sizeof(struct node));
	printf("Enter num:");
	scanf("%d",&num);
	root->x=num;
	root->next=0;
	conductor=root;	
	
	while(1==1){
		printf("more:");
		choice=getche();puts("");
//		scanf("%c",&choice);
		if(choice!='y')
		break;
		else{
		conductor->next=(struct node*)malloc(sizeof(struct node));
		conductor=conductor->next;
		printf("Enter num:");
		scanf("%d",&num);
		conductor->x=num;
		conductor->next=0;
		}
	}
}
	conductor=root;
	if(conductor!=NULL){
		while(conductor!=NULL){
		printf("%d\n",conductor->x);
		conductor=conductor->next;
		}	
	}
	else{
		puts("Linked list in empty");	
	}
}


