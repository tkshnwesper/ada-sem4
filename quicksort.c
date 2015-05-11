#include <stdio.h>

void printarray(int ar[], int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d ", ar[i]);
	}
}

void swap(int ar[], int a, int b) {
	int temp=ar[a];
	ar[a]=ar[b];
	ar[b]=temp;
}

int partition(int ar[], int low, int high) {
	int i=low, j=high+1, p=ar[low];
	while(1) {
		while(p>ar[++i]) {
			if(i>=high) { break; }
		}
		while(p<ar[--j]) {
			if(j<=low) { break; }
		}
		if(i>=j) { break; }
		else { swap(ar, i, j); }
	}
	if(j==low) { return low; }
	else swap(ar, low, j);
	return j;
}

void quicksort(int ar[], int low, int high) {
	int q;
	if(high > low) {
		q=partition(ar, low, high);
		quicksort(ar, low, q-1);
		quicksort(ar, q+1, high);
	}
}

int main() {
	int n, i, ar[20];
	printf("Enter number of elements\n");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &ar[i]);
	}
	quicksort(ar, 0, n-1);
	printarray(ar, n);
	return 0;
}
	
