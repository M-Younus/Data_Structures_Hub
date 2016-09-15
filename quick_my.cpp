#include<iostream>
using namespace std;

void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int part(int* ar, int s, int p){
	int pivot = ar[p];
	int pin = s;
	for (int i = s; i < p; i++){
		if (ar[i] <= pivot){
			swap(ar[i], ar[pin]);
			pin++;
		}
	}
	swap(ar[pin], ar[p]);
	return pin;
}
void quick(int* a, int start, int end){
	if (start < end){
		int pi = part(a, start, end);
		quick(a, start, pi - 1);
		quick(a, pi + 1, end);
	}

}
int main(){
	int A[] = {5,2,7,8,1};
	quick(A, 0, 4);
	for (int i = 0; i <5 ; i++){
		cout << A[i] << "\n";
	}
	getchar();
	return 0;
}
