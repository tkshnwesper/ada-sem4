#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int key, int n, int b, int e) {
	int m;
	if(b>e) {
		return -1;
	}
	m=(b+e)/2;
	if(array[m]==key) {
		return m;
	}
	if(key<array[m]) {
		e=m-1;
	}
	else {
		b=m+1;
	}
	return binary_search(array, key, n, b, e);
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
	result=binary_search(ar, key, n, 0, n-1);
	if(result != -1) {
		printf("Element found at index %d\n", result);
	}
	else {
		printf("Element not found\n");
	}
	return 0;
}
	
