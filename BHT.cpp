#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int** min(int *a,int *b){
	if(*a==0)
	return &b;
	else if(*b==0)
	return &a;
	else
	return (*a<*b)?&a:&b;
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Delete(int ar[],int size){
	puts("\nDelete");
	int i=1;int max=size;int left,right,x,y;

	while(i<=max&&max!=0){
		printf("%d\n",ar[i]);
		ar[i]=ar[max];
		
		while(ar[i]<ar[2*i]){
		x=2*i;y=x+1;
		if(ar[i]>**min(&ar[x],&ar[y])){
		swap(&ar[i],*min(&ar[x],&ar[y]));
		i*=2;
		}
			else
			break;
		}
		i=1;
		max--;
	}

}

main(){
	
//	int a=3,b=4,c=5;
//	swap(&c,*min(&a,&b));
//	printf("a=%d,b=%d,c=%d",a,b,c);
//	
//	exit(0);
	
	int arr[]={0,5,10,17,-5,13,10,11};int i,j,k,x,y,z;
	
//	printf("%d",arr[15]);
//	exit(49);
	
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
			
				swap(&bhp[i],&bhp[i/2]);
				
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
