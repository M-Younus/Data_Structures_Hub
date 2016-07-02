#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

int** min(int *a, int *b){
	if (*a == 0)
		return &b;
	else if (*b == 0)
		return &a;
	else if (*a == *b)
		return &a;
	else
		return (*a < *b) ? &a : &b;
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//wrong
void Delete(int ar[], int size){
	puts("\nDelete");
	int i = 1; int max = size; int left, right, x, y;

	while (i <= max&&max != 0){
		printf("%d\n", ar[i]);
		ar[i] = ar[max];

		while (i * 2 < max){
			x = 2 * i; y = x + 1;
			int** minVal = min(&ar[x], &ar[y]);
			if (ar[i] > **minVal){
				swap(&ar[i], *minVal);
				i *= 2;
			}
			else
				break;
		}
		i = 1;
		max--;
	}

}

int main(){


	int arr[] = { 0, 3, 9, 1, 5, 2, 7, 11 }; int i, j, k, x, y, z;

	//	printf("%d",arr[15]);
	//	exit(49);

	int bhp[8];
	for (j = 1; j <= 7; j++){
		i = j;
		if (i == 1){
			bhp[i] = arr[i];
		}
		else if (i > 1){

			bhp[i] = arr[i];
			x = bhp[i];
			y = bhp[i / 2];
			//if > then print max heap if < then print min heap tree
			while (x > y&&i != 1){

				swap(&bhp[i], &bhp[i / 2]);

				i /= 2;

				x = bhp[i];
				y = bhp[i / 2];

			}

		}
	}
	printf("\n\n");
	for (i = 1; i <= 7; i++)
		printf("\n%d", bhp[i]);

//	Delete(bhp, 7);
	getchar();
	return 0;
}
