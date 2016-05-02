#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
struct Node{
	int data; Node* link;
};

void disp(Node* front){
	while (front != NULL){
		printf("\n%d", front->data);
		front = front->link;
	}
}
void enq(Node** front,Node** rear, int val){
	Node* temp = (Node*)malloc(sizeof(Node));
	if (*front == NULL&&*rear == NULL){
		temp->data = val;
		temp->link = NULL;
		*front = *rear = temp;
		(*front)->link = *rear;
	}
	else{
		temp->data = val;
		temp->link = NULL;
		(*rear)->link = temp;
		*rear = temp;
	}
}
void deque(Node** front){
	Node* temp = (*front)->link;
	free(*front);
	*front = temp;
}
int main(){
	Node* front=NULL,*rear = NULL;
	enq(&front, &rear, 1);
	enq(&front, &rear, 3);
	enq(&front, &rear, 6);
	enq(&front, &rear, 4);
	disp(front);
	puts("");
	deque(&front);
	deque(&front);
	disp(front);
	getchar();
	return 0;
}
