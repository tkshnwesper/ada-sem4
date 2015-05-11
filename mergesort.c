#include <stdio.h>

void printarray(int ar[], int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d ", ar[i]);
	}
}

void merge(int ar[], int low, int mid, int high) {
	int i, j, k, temp[10];
	j=low;
	k=mid+1;
	for(i=low;i<=high;i++) {
		if(j<=mid && k<=high) {
			if(ar[j] < ar[k]) {
				temp[i-low]=ar[j];
				j++;
			}
			else {
				temp[i-low]=ar[k];
				k++;
			}
		}
		else if(j>mid) {
			temp[i-low]=ar[k++];
		}
		else {
			temp[i-low]=ar[j++];
		}
	}
	for(i=low;i<=high;i++) {
		ar[i]=temp[i-low];
	}
}

void mergesort(int ar[], int low, int high) {
	int mid;
	if(low < high) {
		mid = (low + high) / 2;
		mergesort(ar, low, mid);
		mergesort(ar, mid + 1, high);
		merge(ar, low, mid, high);
	}
}

int main() {
	int n, i, ar[20];
	printf("Enter number of elements\n");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &ar[i]);
	}
	mergesort(ar, 0, n-1);
	printarray(ar, n);
	return 0;
}
