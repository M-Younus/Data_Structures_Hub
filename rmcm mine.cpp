#include<iostream>
using namespace std;
int main(){
	cout<<"\nenter dim\n";int n=1;
	int d;cin>>d;
	cout<<"\nenter num of elements\n";
	int *s=new int();int i;
	for(int i=0;i<d;i++){
	cin>>s[i];
	n*=s[i];	
	}
	int *data=new int();
	cout<<"\nenter elements\n";
	for(i=0;i<n;i++){
		cin>>data[i];
	}
	cout<<"\nenter index of required element\n";
	int  *I=new int();
	for(i=0;i<d;i++){
		cin>>I[i];
		if(I[i]>=s[i]){
			cout<<"\nout of required range\n";	
			exit(0);	
		}
	}
	int j=0;int sop=0;int req=0;
	cout<<"\nrow major\n";
	for(i=0;i<d;i++){
		sop=I[i];
		for(j=i+1;j<d;j++){
			sop*=s[j];
		}
	req+=sop;
	}
	
	cout<<"\nrequried element is\n"<<data[req];
	req=0;
	cout<<"\ncolumn major\n";
	for(i=0;i<d;i++){
		sop=I[i];
		for(j=0;j<i;j++){
			sop*=s[j];
		}
	req+=sop;
	}
	cout<<"\nrequried element is\n"<<data[req];
	getchar();
	return 0;
}
