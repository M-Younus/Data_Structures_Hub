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
Node* search(int data) {
   Node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
      printf("%d ",current->data); 
      
      //go to left tree

      if(current->data > data) {
         current = current->leftChild;
      }
      //else go to right tree
      else {                
         current = current->rightChild;
      }

      //not found
      if(current == NULL) {
         return NULL;
      }

      return current;
   }  
}
main(){
	insert(1);
	insert(2);
//	display();
	Node* hg=search(1);
//	puts("wa");
//	if(hg==NULL){
//		puts("null");
//	}
//	else
//	puts("not");
	printf("dfd %d",hg->data);
}
