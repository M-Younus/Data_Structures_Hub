#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int min(int a,int b){
	if(a<b)
	return a;
	else
	return b;
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Delete(int ar[],int size){
	puts("\nDelete");
	int i=1;int max=size;int left,right;

	while(i<=max&&max!=0){
		printf("%d\n",ar[i]);
		ar[i]=ar[max];
		left=ar[2*i];
		right=ar[2*i+1];
		if(ar[i]>left){
			int temp;
			temp=ar[i];
			ar[i]=left;
			ar[i*2]=temp;
		}
		else if(ar[i]>right){
			int temp;
			temp=ar[i];
			ar[i]=right;
			ar[i*2+1]=temp;
		}
		max--;
	}

}

main(){
	
//	int a=3;
//	int b=5;
//	swap(&a,&b);
//	printf("a=%d,,b=%d",a,b);
//	
//	exit(0);
	
	int arr[]={0,5,10,17,-5,13,10,11};int i,j,k,x,y,z;
	int bhp[8];
	for(j=1;j<=7;j++){
		i=j;
		if(i==1){
			bhp[i]=arr[i];
		}
		else if(i>1){
			
			bhp[i]=arr[i];
			x=bhp[i];
			y=bhp[i/2];
			
			while(x<y&&i!=1){
				
				bhp[i/2]=x;
				bhp[i]=y;
				
				i/=2;
				
				x=bhp[i];
				y=bhp[i/2];
				
			}
				
		}
	}
	printf("\n\n");
	for(i=1;i<=7;i++)
	printf("\n%d",bhp[i]);
	
	Delete(bhp,7);
}
