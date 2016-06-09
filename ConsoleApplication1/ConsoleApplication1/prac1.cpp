#include<iostream>
#include<math.h>
using namespace std;
int solution(int A[], int n){
	int sum = 0; int tail; int head = A[0];
	for (int i = 1; i < n; i++)
	{
		sum += A[i];
	}
	int min_dif;
	tail = sum;
	min_dif = abs(head - tail);
	for (int i = 0; i < n; i++)
	{
		head += A[i];
		tail -= A[i];
		if (abs(head - tail) < min_dif)
		{
			min_dif = abs(head - tail);
		}
	}
	return min_dif;
}
int main(){
	int A[] = { 3, 1, 2, 4, 3 };
	int a = solution(A, 5);
	cout << a << "\n";
	return 0;
}