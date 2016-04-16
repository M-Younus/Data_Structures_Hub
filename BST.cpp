#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node * leftChild;
	Node* rightChild;
};
Node* root=NULL;
void insert(int data){
	Node* tempNode=(Node*)malloc(sizeof(Node));
	Node* current;
	Node* parent;
	
	tempNode->data=data;
	tempNode->leftChild=NULL;
	tempNode->rightChild=NULL;
	
	if(root==NULL){
		root=tempNode;
	}else{
		current=root;
		parent=NULL;
		while(1){
			parent=current;
			
			if(data<parent->data){
				current=current->leftChild;
				
				if(current==NULL){
					parent->leftChild=tempNode;
					return;
				}
			}
			else{
				current=current->rightChild;
				
				if(current==NULL){
					parent->rightChild=tempNode;
					return;
				}
			}
		}
	}
}
Node* search(int data){
	Node* current=root;
	while(current->data!=data){
		if(current==NULL){
		puts("value ot found");
	}
	else{
		puts("st");
		if(current->data==data){
			return current;
		}
		else if(current->data<data){
			current=current->rightChild;
		}
		else if(current->data>data){
			current=current->leftChild;
		}
	}
	}
	puts("end");
	
}
main(){
	insert(1);
//	insert(2);
//	display();
	Node* hg=search(1);
	puts("wa");
//	if()
	printf("%d",hg->data);
}
