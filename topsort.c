#include <stdio.h>

int over[10], oindex, ar[10][10];


int isOver(int num) {
	int i;
	for(i=0;i<=oindex;i++) {
		if(num==over[i]) { return 1; }
	}
	return 0;
}

//~ void printover() {
	//~ int i;
	//~ printf("\nOver\n");
	//~ for(i=0;i<=oindex;i++) {
		//~ printf("%d ", over[i]);
	//~ }
//~ }
//~ 
//~ void printmat(int n) {
	//~ int i, j;
	//~ printf("\nMat\n");
	//~ for(i=0;i<n;i++) {
		//~ for(j=0;j<n;j++) {
			//~ printf("%d ", ar[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
//~ }

void topsort(int n, int count) {
	int i, j, flag, zcol;
	if(count==n) { return; }
	for(i=0;i<n;i++) {
		if(isOver(i)) { continue; }
		flag=0;
		for(j=0;j<n;j++) {
			if(ar[j][i]!=0) {
				flag=1;
				break;
			}
		}
		if(!flag) { break; }
	}
	zcol=i;
	printf("%d ", zcol);
	over[++oindex]=zcol;
	
	for(i=0;i<n;i++) {
		if(ar[zcol][i]>0) {
			ar[zcol][i]=0;
		}
	}
	topsort(n, count+1);
}
			


int main() {
	int i, j, n;
	oindex=-1;
	printf("Enter number of edges\n");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &ar[i][j]);
		}
	}
	
	topsort(n, 0);
	
	return 0;
}
	
	
