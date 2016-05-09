#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};
void Print(Node* head){
	printf("List is: ");
	while (head != NULL){
		printf(" %d", head->data);
		head = head->next;
	}
	printf("\n");
}
int Count(Node* head){
	Node* temp = head;
	int c = 0;
	while (temp != NULL){
		temp = temp->next;
		c++;
	}
	puts("\nprint cal in count");
	Print(head);
	return c;
}

//void reversePrint(Node* node){
//	Node* temp=node;
//	int size=Count(node);
//	int ar[size];int i=0;
//	while(node!=NULL){
//		ar[i]=node->data;
//		node=node->next;
//		i++;
//	}
//	for(i=size-1;i>=0;i--)
//	printf("\n%d",ar[i]);
//}

void reverse(Node* head){
	Node *temp = head; Node *temp2 = NULL; Node* t3;

	while (temp != NULL)
	{
		t3 = temp2;
		temp2 = temp;
		temp = temp->next;
		temp2->next = t3;
	}
	puts("\nRevers print");
	Print(temp2);
}



void append(Node** put, int val, int index){
	Node* temp = *put;
	int i = 0;
	while (i <= index){
		puts("\nwhile\n");
		if (i == index - 1){
			puts("\nif\n");
			Node* t = (Node*)malloc(sizeof(Node));
			Node* f = (*put)->next;
			puts("\nlink");
			t->data = val;
			t->next = f;
			(*put)->next = t;
			i++;
		}
		else{
			puts("\nelse\n");
			(*put) = (*put)->next;
			i++;
		}
	}
	*put = temp;
}

void Insert(Node** pointerHead, int x){
	Node* t;
	Node* temp = *pointerHead;
	if (*pointerHead == NULL){
		temp = (Node*)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = 0;
		*pointerHead = temp;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		t = (Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = 0;
		temp->next = t;
	}

}


void Delete(Node* head, int val){
	Node* temp = head; int chk = 0;
	Node* old, t; old = head;
	while (head != NULL){
		chk++;
		if ((head->data == val) && chk == 1){
			temp = head->next;
			free(head);
			head = temp;
			old = head;
		}
		if (head->data != val){
			old = head;
			head = head->next;
		}
		else{
			old->next = head->next;
			free(head);
			head = old->next;
		}
	}
	head = temp;

	puts("After Delete");
	Print(head);
	printf("Total items in list:%d\n", Count(head));
}

void rev_stack(Node** head,int val){
	Node* temp = new Node;
	temp->data =val;
	temp->next = (*head);
	*head = temp;
}

int main(){
	Node* head = NULL;
	printf("How many numbers?\n");
	int n, i, x, val; char choice;
	//scanf("%d",&n);
	cin >> n;
	for (i = 0; i < n; i++){
		printf("Enter the num\n");
		//scanf("%d",&x);
		cin >> x;
		Insert(&head, x);
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
	printf("Total items in list:%d\n", Count(head));
	printf("Want to delete:");
	//choice=getche();puts("");
	cin >> choice;
	if (choice == 'y'){
		printf("Enter value for deleting:");
		//scanf("%d",&val);
		cin >> val;
		Delete(head, val);
	}
	/*puts("\n reverse called");
	reverse(head);*/
	//reverse  stak called
	Node* temp = NULL;
	while (head!=NULL)
	{
		rev_stack(&temp,head->data);
		head = head->next;
	}
	puts("\nafter stack rev");
	Print(temp);
	getchar();
	return 0;
}

