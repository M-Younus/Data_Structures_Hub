/*
A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
Your goal is to find that missing element.
Write a function:
int solution(int A[], int N);
that, given a zero-indexed array A, returns the value of the missing element.
For example, given array A such that:
A[0] = 2
A[1] = 3
A[2] = 1
A[3] = 5
the function should return 4, as it is the missing element.
Assume that:
N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:
expected worst-case time complexity is O(N);
*/

#include <iostream>

using namespace std;
int missing(int a[], int n){
	int sum1 = (n - 1)*(2 * 2 + (n - 2)) / 2, sum2 = 0;
	//int sum1 = (n*(n +1)) / 2, sum2 = 0;
	for (int i = 0; i < n; i++){
		if (a[i]>1 && a[i] < n+1){
			sum2 = sum2 + a[i];
		}
	}
	return (sum1 - sum2);
}

int main()
{
	int n=4; 
	/*cout << "Enter the number of elements, then insert the elements..." << endl;
	cin >> n;*/
	int a[4];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << missing(a, n) << " is missing" << endl;
	return 0;
}