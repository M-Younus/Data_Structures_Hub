#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//min BHP
main(){
	int arr[]={0,5,10,17,-5,0,13,10,22,55,79,-10,15};int i,j,k,x,y,z;
	int bhp[12];
	for(j=1;j<=12;j++){
		i=j;
		if(i==1){
			bhp[i]=arr[i];
		}
		else if(i>1){
			
			bhp[i]=arr[i];
			x=bhp[i];
			y=bhp[i/2];
			
			while(x>y&&i!=1){
				
				bhp[i/2]=x;
				bhp[i]=y;
				
				i/=2;
				
				x=bhp[i];
				y=bhp[i/2];
				
			}
				
		}
	}
	printf("\n\n");
	for(i=0;i<=12;i++)
	printf("\n%d",bhp[i]);
}
