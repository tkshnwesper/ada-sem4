#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, int key, int n) {
	int i;
	for(i=0;i<n;i++) {
		if(key==array[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
	int *ar, n, i, key, result;
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	ar = (int *)malloc(sizeof(int) * n);
	printf("Enter elements\n");
	for(i=0;i<n;i++) {
		scanf("%d", &ar[i]);
	}
	printf("Enter key\n");
	scanf("%d", &key);
	result=linear_search(ar, key, n);
	if(result != -1) {
		printf("Element found at index %d\n", result);
	}
	else {
		printf("Element not found\n");
	}
	return 0;
}
	
