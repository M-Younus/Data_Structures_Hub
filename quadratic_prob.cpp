#include<iostream>
using namespace std;int hs=10;
int key(int val){
	return val%hs;
}
int main(){
	int i,j,k;
//	cout<<"\nenter hash size\n";
//	cin>>hs;
	int arr[hs];int count=0;
	for(i=0;i<hs;i++)
	arr[i]=0;
	int data[]={89,18,49,58,69};int I;int q=1;int temp=0;int t=0;
	for(i=0;i<5;i++){
		q=1;
		I=key(data[i]);
		if(arr[I]==0)
		arr[I]=data[i];
		else{
			temp=I;t=I;
			while(arr[temp]!=0){
				I=t;
				q*=q;
				I=((I+q)%hs)%hs;
				++q;
				temp=I;
			}
			arr[I]=data[i];
		}
	}
	
	for(i=0;i<hs;i++)
	cout<<"\n"<<arr[i]<<"\n";	
	
	getchar();
	return 0;
}
