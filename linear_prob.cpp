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
	int data[]={89,18,49,58,69};int I;
	for(i=0;i<5;i++){
		I=key(data[i]);
		if(arr[I]==0)
		arr[I]=data[i];
		else{
			while(arr[I]!=0&&count<=hs){
				I=((++I)%hs)%hs;
				++count;
			}
			arr[I]=data[i];
		}
	}
	
	for(i=0;i<hs;i++)
	cout<<"\n"<<arr[i]<<"\n";	
	
	getchar();
	return 0;
}
