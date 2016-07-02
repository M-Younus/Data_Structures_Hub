#include<iostream>
using namespace std;
int key(int val,int h){
	return val%h;
}
int getPrime(int h){
	int i,j;int *ar=new int();int count=0;
	int k;
	for(k=0,i=2;i<=h;i++){
		count=0;
		for(j=2;j<=i;j++){
			if(i%j==0){
				++count;
			}
		}
			if(count<=1){
				ar[k]=i;
				++k;
			}
	}
	
	for(i=0;i<k;i++)
	cout<<"primes are\n"<<ar[i]<<"\n";
	
	return ar[k-1];
	
}

int main(){
	int has=0;
	cout<<"Enter hash size:";
	cin>>has;
	int i,j,k;int prime=getPrime(has);
	cout<<"\nhere "<<prime<<"\n";
//	cout<<"\nenter hash size\n";
//	cin>>hs;
	int arr[has];int count=0;
	for(i=0;i<has;i++)
	arr[i]=0;
//	int data[]={89,18,49,58,69,55,3,98};
	int *data=new int();
	int I;int q=prime;int temp=0;int t=0;int choice;
	cout<<"\nInput Data\n";i=0;
	do{
		cin>>data[i];
		i++;
		temp++;
		cout<<"\nwant more:1/0\n";
		cin>>choice;
	}while(choice);

	for(i=0;i<temp;i++){
		q=prime;
		I=key(data[i],has);
		if(arr[I]==0)
		arr[I]=data[i];
		else{
			while(arr[I]!=0){
				q=q-(data[i]%q);
				I=((I+q)%has)%has;
			}
			arr[I]=data[i];
		}
	}
		
	
	for(i=0;i<has;i++)
	cout<<"\n"<<arr[i]<<"\n";	
	
	getchar();
	return 0;
}
