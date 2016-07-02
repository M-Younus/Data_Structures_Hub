//bredth first->level order
//depth first->pre/in/post order
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct Root{
	int data; Root* right;Root *left;
};

struct que{
	Root* value;
	que* node;
};

que* qu=NULL;

void insert(Root** root,int val){
	
	Root* temp; Root* r; Root* t = NULL;
	if (*root == NULL){
		temp = new Root;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	}
	else{
		temp = *root; int l = 0, f = 1;
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

	int count=0;
Root* max(Root* temp){
	while (temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}
Root* min(Root* temp){
	while (temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

Root* search(Root* rot,int val){
	Root* temp = rot; int f = 0;
	while (temp != NULL){
		if (val == temp->data){
			f = 1;
			cout << "\nfound\n";
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

void deleteNode(Root* temp,int val){
	int f = 0;Root* found=NULL;Root* parent=temp;Root* t;
	while (temp != NULL){
		if (val == temp->data){
			f = 1;
			cout << "\nfound\n";
			found=temp;
			cout<<"\nneed "<<found->data<<" parent "<<parent->data<<"\n";
			break;
		}
		else if (val > temp->data){
			parent=temp;
			temp = temp->right;
		}
		else if (val < temp->data) {
			parent=temp;
			temp = temp->left;
		}
	}
	if (!f)     {
		cout << "not found";
		return;	
	}
	
	if (found->left == NULL && found->right == NULL){
		//if no child
		cout<<"\n no child rn\n";
		delete found;
		parent->left=parent->right=NULL;
	}
	else if (found->left != NULL && found->right != NULL){
		cout<<"\n2 child run\n";
		//code for if 2 childs
		t=found->right;
		while(t->left!=NULL){
			t=t->left;
		}
		found->data=t->data;
		deleteNode(found->right,t->data);
		
	}
	else{
		cout<<"\n1 child run\n";
		//code for if one child
		if (found->left == NULL){
			if(parent->data<found->data)
			parent->right=found->right;
			else
			parent->left=found->right;
		}
		else if (found->right == NULL){
			if(parent->data<found->data)
			parent->right=found->left;
			else
			parent->left=found->left;
		}
	}
}

void preorder(Root* temp){
	if (temp != NULL){
		cout << "\n" << temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(Root* temp){
	if (temp != NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout << "\n" << temp->data;
	}
}

void inorder(Root* temp){
	if (temp != NULL){
		inorder(temp->left);
		cout << "\n" << temp->data;
		inorder(temp->right);
	}
}

int l,r;

int hMax(int a,int b){
	return (a>b||a==b)?a:b;
}

int height(Root* temp){
	if(temp==NULL)
	return -1;
	return hMax(height(temp->left),height(temp->right))+1;
//	return ((l=height(temp->left))>(r=height(temp->right)))?c+1:v+1;	
}

int depth(Root* temp,int val){
	
		if(temp->data==val){
			return count;
		}
		else if(temp->data<val){
			temp=temp->right;
			count++;
			depth(temp,val);
		}
		else if(temp->data>val){
			temp=temp->left;
			count++;
			depth(temp,val);
		}
	return count;
}

void levelorderbuilt(Root* temp){
	if(temp==NULL) return;
	queue<Root*> Q;
	Q.push(temp);
	while(!Q.empty()){
		Root* current=Q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL) Q.push(current->left);
		if(current->right!=NULL) Q.push(current->right);
		Q.pop();
	}
}

void enque(Root* temp){
	que* t;
	if(qu==NULL){
		t=new que;
		t->value=temp;
		t->node=NULL;
		qu=t;
	}
	else{
		t=new que;que* r=qu;
		while(qu->node!=NULL){
			qu=qu->node;
		}
		t->value=temp;
		t->node=NULL;
		qu->node=t;
		qu=r;
	}
}

Root* dequ(){
	if(qu!=NULL){
	Root* temp=qu->value;
	qu=qu->node;
	return temp;	
	}
}

void levelOrder(Root* temp){
	if(temp==NULL) return;
	cout<<temp->data<<"\n";
	if(temp->left!=NULL){
	enque(temp->left);
	}
	if(temp->right!=NULL){
	enque(temp->right);	
	}
	levelOrder(dequ());
}

int main(){
	Root *root = NULL;
	insert(&root,4);
	insert(&root,6);
	insert(&root,2);
	insert(&root,5);
	insert(&root,11);
	insert(&root,8);
	insert(&root,7);
	insert(&root,9);
	insert(&root,1);
//	cout << "search\n";
//	cout<<"\ndepth "<<depth(root,9);
//	cout<<"\nheight "<<height(search(root,4));
	cout<<"\nLevelOrder\n";
//	levelorderbuilt(root);
	levelOrder(root);
//	Root* found = search(root,8);
//	Root* found = search(root,99);
	//cout << "max & min is \n";
//	Root* maximum = max(root);
//	Root* minimum = min(root);
//	cout << "max=>" << maximum->data << " mi=>" << minimum->data<<"\n";
//	cout<<"\npre order before delete\n";
//	preorder(root);
//	cout<<"\npre order after delete\n";
//	deleteNode(root,6);
//	preorder(root);
	//cout << "\npreorders\n";
//	if(root==0)
//	cout<<"null";
//	else{
//		cout <<"\n"<< (root->left)->left->data<<"\n";
//	}
	//else
//	preorder(root);
	//cout << "\ninorders\n";
//	inorder(root);
//	cout << "\npostorders\n";
//	postorder(root);
	getchar();
	return 0;
}
