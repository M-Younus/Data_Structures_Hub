#include<iostream>
using namespace std;
struct Root{
	int data; Root* right, *left;
};
Root *root = NULL;
void insert(int val){
	Root* temp; Root* r; Root* t=NULL;
	if (root == NULL){
		temp = new Root;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
	}
	else{
		temp = root; int l = 0, f = 1;
		r = new Root;
		r->data = val;
		r->left = NULL;
		r->right = NULL;
		while (temp != NULL){
			if (val > temp->data){
				f = 1; l = 0;
				t = temp;
				temp = temp->right;
			}
			else{
				l = 1; f = 0;
				t = temp;
				temp = temp->left;
			}
		}
		temp = t;
		if (f){
			temp->right = r;
		}
		else if (l){
			temp->left = r;
		}
	}
}
Root* search(int val){
	Root* temp = root; int f=0;
	while (temp!=NULL){
		if (val==temp->data){
			f = 1;
			cout << "found";
			return temp;
		}
		else if (val > temp->data){
			temp = temp->right;
		}
		else if (val < temp->data) {
			temp = temp->left;
		}
	}
	if (!f)
		cout << "not found";
	return NULL;
}
Root* max(){
	Root* temp = root;
	while (temp->right!=NULL){
		temp = temp->right;
	}
	return temp;
}
Root* min(){
	Root* temp = root;
	while (temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

int main(){
	insert(4);
	insert(6);
	insert(2);
	insert(5);
	insert(11);
	insert(8);
	insert(9);
	insert(0);
	cout << "search\n";
	//Root* found = search(8);
	Root* found = search(99);
	cout << "max & min is \n";
	Root* maximum = max();
	Root* minimum = min();
	cout << "max=>" << maximum->data << " mi=>" << minimum->data<<"\n";
	getchar();
	return 0;
}