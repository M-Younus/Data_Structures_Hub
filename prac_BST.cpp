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
void preorder(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      preorder(root->leftChild);
      preorder(root->rightChild);
   }
}

void inorder(struct node* root) {
   if(root != NULL) {
      inorder(root->leftChild);
      printf("%d ",root->data);          
      inorder(root->rightChild);
   }
}

void postorder(struct node* root) {
   if(root != NULL) {
      postorder(root->leftChild);
      postorder(root->rightChild);
      printf("%d ", root->data);
   }
}

node* Delete(node* link,int data){
	if(link==NULL)
	return link;
	else if(data<link->data)
	link->leftChild=Delete(link->leftChild,data);
	else if(data>link->data)
	link->data=Delete(link->rightChild,data);
	else{
		if(link->leftChild==NULL&&link->rightChild==NULL){
			delete link;
			link=NULL;
		}
		else if(link->leftChild==NULL){
			node* temp=link;
			link=link->rightChild;
			delete temp;
		}
		else if(link->rightChild==NULL){
			node* temp=link;
			link=link->leftChild;
			delete temp;
		}
		else{
			node* temp=min(link->rightChild);
			link->data=temp->data;
			link->data=Delete(link->rightChild,temp->data);
		}
	}
	return link;
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
