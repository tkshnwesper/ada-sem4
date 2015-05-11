#include <stdio.h>
#include <stdlib.h>

void swap(int *ar, int i, int j) {
	int temp;
	temp=ar[i];
	ar[i]=ar[j];
	ar[j]=temp;
}

void bubblesort(int *ar, int n) {
	int i, j;
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-1;j++) {
			if(ar[j]>ar[j+1]) {
				swap(ar, j, j+1);
			}
		}
	}
}

void print_array(int *ar, int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

int main() {
	int *ar, n, i;
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	ar = (int *)malloc(sizeof(int) * n);
	printf("Enter elements\n");
	for(i=0;i<n;i++) {
		scanf("%d", &ar[i]);
	}
	bubblesort(ar, n);
	print_array(ar, n);
	return 0;
}
