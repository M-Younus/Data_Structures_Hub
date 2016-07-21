#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

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

int size(Node* head){
	int c=0;
	while(head!=NULL){
		c++;head=head->next;
	}
	return c;
}

//void breaking(Node* org,Node** cop,int index){
//	int k=1;*cop=new Node;
//	while(k!=index){
//		(*cop)->data=org->data;
//		k++;
//	}
//}

void stak(Node** node,int val){
	Node* temp=new Node;
	temp->data=val;
	temp->next=*node;
	*node=temp;
}

int main(){
	int t,i,j,k,n,x,y,z;
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
		
		cout<<"type number where breaking(greater than 1):";cin>>k;
		int groups=size(head[i])/k;
		if(size(head[i])%k!=0){
			groups++;
		}
		Node* temp=head[i];
		Node* gr[groups];
		for(j=0;j<groups;j++){
			for(x=0;x<k;x++){
				stak(&gr[j],temp->data);
				temp=temp->next;
			}
			cout<<"\nprint stack at:"<<j;
			display(gr[j]);
		}
		
//	cout<<"display\n";
//	display(head[i]);
	}
	
	
	getchar();
	return 0;
}
