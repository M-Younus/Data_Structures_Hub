#include<iostream>
#include<stdio.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
void swap(int *a,int* b){
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
void link_sort(int s,Node** head){
	int i;Node* t=*head;
	for(i=0;i<s;i++){
		while((*head)->next!=NULL){
				if((*head)->data>(*head)->next->data){
				swap(&(*head)->data,&(*head)->next->data);
			}
			*head=(*head)->next;
		}
	*head=t;
	}
}
void sort(int* A,int s){
	int i,j;
	for(i=0;i<s;i++){
		for(j=0;j<s-1;j++){
				if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
			}
		}
	}
}
void insert(Node** head,int val){
	Node* temp;
	if(*head==NULL){
		temp=new Node;
		temp->data=val;
		temp->next=NULL;
		*head=temp;
	}
	else{
		temp=*head;Node* t=new Node;
		while((*head)->next!=NULL){
			*head=(*head)->next;	
		}
		t->data=val;
		t->next=NULL;
		(*head)->next=t;
		*head=temp;
	}
}
void display(Node* temp){
	while(temp!=NULL){
		cout<<"\n"<<temp->data;
		temp=temp->next;
	}
}
int main(){
	int t,i,j,k,n;
	cout<<"test cases:";cin>>t;
	Node* head[t];
	for(i=0;i<t;i++){
		head[i]=NULL;
		cout<<"number of elements:";cin>>n;
		int A[n];
		cout<<"eneter elements\n";
		for(j=0;j<n;j++){
			cin>>A[j];
			insert(&head[i],A[j]);
		}
//		sort(A,n);
		link_sort(n,&head[i]);
//		for(j=0;j<n;j++){
////			cout<<"\n"<<A[j];
//			insert(&head[i],A[j]);
//		}
		cout<<"array of test:"<<i;
//		for(j=0;j<n;j++){
//			cout<<"\n"<<A[i][j];
//		}
		cout<<"linked display called";
		display(head[i]);
	}

	getchar();
	return 0;
}
