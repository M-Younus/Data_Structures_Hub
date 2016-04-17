#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
	
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   if(root == NULL) {
      root = tempNode;
   }else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         if(data < parent->data) {
            current = current->leftChild;                
            
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }
         else {
            current = current->rightChild;

            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}

struct node* search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
         printf("%d ",current->data); 

      if(current->data > data) {
         current = current->leftChild;
      }
      
      else {                
         current = current->rightChild;
      }

      if(current == NULL) {
         return NULL;
      }
   }
   
   return current;
}
void max(){
	node* temp=root;
	while(temp!=NULL){
		if(temp->rightChild==NULL){
			printf("Max is %d",temp->data);
			temp=temp->rightChild;
		}
		else{
			temp=temp->rightChild;
		}
	}
}

void min(){
	node* temp=root;
	while(temp!=NULL){
		if(temp->leftChild==NULL){
			printf("Min is %d",temp->data);
			temp=temp->leftChild;
		}
		else{
			temp=temp->leftChild;
		}
	}
}
void inorder(){
	
}
main(){
	insert(5);
	insert(2);
	insert(1);
	insert(-56);
	node* temp=search(12);
	if(temp!=NULL)
	printf("\n%d",temp->data);
	else{
		puts("not found");
	}
	puts("max");
	max();
	puts("min");
	min();
}
