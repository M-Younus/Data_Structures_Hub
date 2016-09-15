#include<iostream>
using namespace std;
int main(){
	int x = 10, y = 85, d = 30;
	int distance = y - x;
	int a = (distance%d == 0) ? distance / d : distance / d + 1;
	cout << a;
	return 0;
}