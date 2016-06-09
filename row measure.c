//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
int main(){
    int dim,N=1,PoS,ReqAdd=0,i,j;
    printf("enter no. of dimensions:\n");
    scanf("%d",&dim);
    printf("enter size of each dimension\n");
    int *S=malloc(sizeof(int));
    int *I=malloc(sizeof(int));
    for(i=0;i<dim;i++){
        scanf("%d",&S[i]);
        N=N*S[i];
    }
    printf("total no. of elements=%d\n",N);
    int *data=malloc(sizeof(int));
    printf("enter all elements\n");
    for(i=0;i<N;i++)
        scanf("%d",&data[i]);
    printf("enter index of required value\n");
    for(i=0;i<dim;i++){
        scanf("%d",&I[i]);
        if(I[i]>=S[i]){
        	printf("invalid index. enter index again\n");
        	i=-1;
		}
	}
    for(i=0;i<dim;i++){
        PoS=I[i];
        for(j=i+1;j<dim;j++){
            PoS=PoS*S[j];
        }
        ReqAdd=ReqAdd+PoS;
    }
    printf("value at given address=%d",data[ReqAdd]);
	getchar();
	return 0;
}
