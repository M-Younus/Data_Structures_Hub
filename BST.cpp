#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
struct Node{
	int data;
	Node * leftChild;
	Node* rightChild;
};
Node* root = NULL;
void insert(int data){
	Node* tempNode = (Node*)malloc(sizeof(Node));
	Node* current;
	Node* parent;

	tempNode->data = data;
	tempNode->leftChild = NULL;
	tempNode->rightChild = NULL;

	if (root == NULL){
		root = tempNode;
	}
	else{
		current = root;
		parent = NULL;
		while (1){
			parent = current;

			if (data < parent->data){
				current = current->leftChild;

				if (current == NULL){
					parent->leftChild = tempNode;
					return;
				}
			}
			else{
				current = current->rightChild;

				if (current == NULL){
					parent->rightChild = tempNode;
					return;
				}
			}
		}
	}
}
Node* search(int data) {
	Node *current = root;
	printf("Visiting elements: ");

	if (current->data == data)
		printf("found");
	else{
		while (current->data != data) {
			//   	puts("andt");
			if (current != NULL)
				printf("this %d ", current->data);

			if (current->data > data) {
				current = current->leftChild;
			}
			else {
				current = current->rightChild;
			}

			if (current == NULL) {
				return NULL;
			}

			return current;
		}
	}
	return current;
}
int main(){
	insert(1);
	insert(2);
	Node* hg = search(2);
	printf("\n %d", hg->data);
	getchar();
	return 0;
}
