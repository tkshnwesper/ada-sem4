#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
	return a>b?b:a;
}

int main() {
	int ar[10][10], n, i, j, k;
	printf("Enter number of vertices\n");
	scanf("%d", &n);
	
// Scan array

	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &ar[i][j]);
		}
	}

// Floyd's algotithm

	for(k=0;k<n;k++) {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				ar[i][j]=min(ar[i][j], ar[i][k]+ar[k][j]);
			}
		}
	}
	
// Print array

	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
