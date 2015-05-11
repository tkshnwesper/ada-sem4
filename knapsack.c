#include <stdio.h>
#include <math.h>

int main() {
	int weights[10], profits[10], capacity, i, j, n;
	float pd[10], temp, mod;
	printf("Enter number of items\n");
	scanf("%d", &n);
	printf("Enter capacity\n");
	scanf("%d", &capacity);
	printf("Enter weights\n");
	for(i=0;i<n;i++) {
		scanf("%d", &weights[i]);
	}
	printf("Enter profits\n");
	for(i=0;i<n;i++) {
		scanf("%d", &profits[i]);
	}
	for(i=0;i<n;i++) {
		pd[i]=(float)profits[i]/weights[i];
	}
	
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-1;j++) {
			if(pd[j]<pd[j+1]) {
				temp=pd[j+1];
				pd[j+1]=pd[j];
				pd[j]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++) {
		if((mod=fmod(weights[i], capacity))==weights[i]) {
			printf("W: %d\nP: %d", weights[i], profits[i]);
			capacity-=weights[i];
		}
		else {
			printf("W: %f\nP: %d", weights[i]-mod, profits[i]);
		}
	}
	
	return 0;
}
