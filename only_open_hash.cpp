#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node *hush[10];

int key(int num,int s){
	return num%s;
}

void hashing(int key,int val){
	Node* temp; Node* r;
	
	if (hush[key] == NULL){
		temp = new Node;
		temp->data = val;
		temp->next = NULL;
		hush[key] = temp;
	}
	else{
		r = hush[key];
		while (hush[key]->next != NULL){
			hush[key] = hush[key]->next;
		}
		temp = new Node; 
		temp->data = val;
		temp->next = NULL;
		hush[key]->next = temp;
		hush[key] = r;
	}
}

void searchHash(int val,int hs){
	int si = key(val, hs); int flag = 0; int count = 0;
	Node *r = hush[si];
	while (hush[si] != NULL){
		count++;
		if (hush[si]->data == val){
			flag = 1;
			hush[si] = r;
			cout << "found" << " at " << count << " iterations\n";
			break;
		}
		hush[si] = hush[si]->next;
	}
	if (!flag)
		cout << "\nnot found " << " after " << count << " iterations\n";

}

void display(int s){
	Node *temp[s];
	for(int i=0;i<s;i++)
		temp[i]=hush[i];
	for(int i=0;i<s;i++){
		cout<<"\nElements of Index "<<i<<"\n";
		while(temp[i]!=NULL){
			cout<<temp[i]->data<<"\n";
			temp[i]=temp[i]->next;	
		}	
	}
}

void deleteData(int val,int hs){
	int si = key(val, hs);
	Node *r = hush[si];Node* temp=NULL;Node* parent=hush[si];
		if(hush[si]->data==val){
			temp=hush[si]->next;
			delete hush[si];
			hush[si]=temp;
		}
		else{
			hush[si]=hush[si]->next;
			while(hush[si]!=NULL){
				if(hush[si]->data==val){
					temp=hush[si]->next;
					parent->next=temp;
					delete hush[si];
					break;
				}
				else{
					parent=hush[si];
					hush[si]=hush[si]->next;
				}
			}
			hush[si]=r;
		}
}

int main(){
	int hs;int *data=new int;int i=0,j,k;int choice=1;
	cout << "Enter the hash table size\n";
	cin>>hs;
	while(i<hs&&choice){
		cout << "Insert Data\n";
		cin>>data[i];
		hashing(key(data[i], hs), data[i]);
		cout << "Want more-->1 for yes..0 for no\n";
		cin>>choice;
		i++;
	}
	
	do{
		cout << "1.Display\n";
		cout << "2.Search\n";
		cout << "3.Delete\n";
		cout << "0 for nothing\n";
		cin>>choice;
		switch(choice){
			case 1:{
				display(hs);
				break;
			}
			case 2:{
				int search;
				cout<<"\nEnter element u want to search:";
				cin>>search;
				searchHash(search,hs);
				break;
			}
			case 3:{
				int deleteItem;
				cout<<"\nEnter element u want to delete:";
				cin>>deleteItem;
				deleteData(deleteItem,hs);
				cout<<"\ndeleted\n";
				break;
			}
		}
	}while(choice);
	
	getchar();
	return 0;
}
