#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};
const int hs = 10;
Node *hush[hs];
void insert(Node** point, int x){
	Node* temp; Node* r;
	if (*point == NULL){
		temp = new Node;
		temp->data = x;
		temp->next = NULL;
	}
	else{
		temp = *point;
		while ((*point)->next != NULL)
			*point = (*point)->next;
		r = new Node;
		r->data = x;
		r->next = NULL;
		(*point)->next = r;
	}
	*point = temp;
}

void display(Node* head){
	while (head!=NULL){
		cout << head->data << "\n";
		head = head->next;
	}
}
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
void searchHash(int val){
	int si = key(val, hs); int flag = 0; int count = 0;
	Node *r = hush[si];
	while (hush[si] != NULL){
		count++;
		if (hush[si]->data == val){
			flag = 1;
			hush[si] = r;
			cout << "found" << " after " << count << " iterations\n";
			break;
		}
		hush[si] = hush[si]->next;
	}
	if (!flag)
		cout << "\nnot found " << " after " << count << " iterations\n";

}
int main(){
	Node* head = NULL;
	insert(&head, 4);
	insert(&head, 6);
	insert(&head, 3);
	insert(&head, 7);
	display(head);
	cout << "Hashing start\n";
	int data[] = { 5,1, 8, 2, 3, 0, 10,21,11,28,35,13,6,99,101 };
	for (int i = 0; i < 15; i++){
		hashing(key(data[i], hs), data[i]);
	}
	//searchHash(data[1]);
	searchHash(31);
	//cout << hush[1]->data;
	return 0;
	getchar();
}