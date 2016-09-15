//Open hashing
#include <iostream>
using namespace std;
void insert(int, int);
void display(int b[], int);
int wantmore();
struct node{

	int data;
	node* link;
};

node* head[100];

int main(){
	int i = 50;
	head[100] = NULL;
	int n, life, hash, value;
	int a[50] = {};

	cout << "Enter number of element : ";
	cin >> n;
	do{
		//    node* root = new node();
		cout << "\nEnter the hash value : ";
		cin >> value;
		hash = value % n;
		if (a[hash] == 0)
		{
			a[hash] = value;
			cout << "\na[" << hash << "]the value " << value << " is stored";

		}
		else if (a[hash] != 0)
		{
			if (head[hash] == NULL)
				head[hash] = (node*)a[hash];
			insert(value, hash);
			cout << "number :" << value << " enter in [" << hash << "] linked list \n";
			//		  i++;	
		}
		life = wantmore();

	} while (life == 1);
	display(a, i);
	getchar();
	return 0;
}
int wantmore(){
	int i;
	cout << "\nDo u want to add more ?\nif yes then type 0\nelse 1\n";
	cin >> i;
	return i;
}
void insert(int value, int hash){

	node* temp = new node();
	temp->data = value;
	temp->link = NULL;
	head[hash] = temp;
}
void display(int b[], int size){
	node* temp = new node();

	for (int i = 0; i<size; i++){

		if (b[i] != NULL){
			cout << "array index " << i << " value : " << b[i];
			if (head[i] != NULL)
			{
				temp = head[i];

				while (temp != NULL){

					cout << "," << temp->data;
					temp = temp->link;
				}
			}
			cout << "\n";
		}


	}
}