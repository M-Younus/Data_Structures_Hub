#include<iostream>
using namespace std;
void swap(int *a,int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
int main(){
	int A[] = { 8, 1, 0, 66, 3 }; int f = 0;
	for (int i = 0; i < 5; i++)
	{
		f = 0;
		for (int j = 0, k = 1; k < 5-i; j++, k++)
		{
			if (A[j] > A[k]){
				swap(&A[j], &A[k]);
				f = 1;
			}
		}
		if (f == 0)break;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << A[i] << "\n";
	}
	return 0;
	getchar();
}