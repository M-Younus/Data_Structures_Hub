#include<iostream>
using namespace std;
int main(){
	int *f=new int;
	f[0]=2;f[1]=4;f[2]=5;
	//delete (f+1);
	cout<<*(f+2);
	getchar();
	return 0;
}
