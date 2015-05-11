#include <stdio.h>

#define INF 9999

int input[10][10], finished[10], findex, n, output[10][10], oindex;

void push(int *ar, int *index, int val) {
	(*index)++;
	ar[*index]=val;
}

int exists_in_array(int *ar, int index, int val) {
	int i;
	for(i=0;i<=index;i++) {
		if(ar[i]==val) {
			return 1;
		}
	}
	return 0;
}

int find_closest(int vert) {
	int i, closest=INF, cindex;
	for(i=0;i<n;i++) {
		if(!exists_in_array(finished, findex, i)) {
			if(closest>input[vert][i]) {
				closest=input[vert][i];
				cindex=i;
			}
		}
	}
	return cindex;
}

int distance(int a, int b) {
	return input[a][b];
}

int distance_from_source(int b) {
	return output[oindex-1][b];
}

void write_output(int row, int col, int val) {
	output[row][col]=val;
}

void reset_all() {
	findex=-1;
	oindex=-1;
}

int main() {
	int i, j, s, cur, x, y;
	findex=-1;
	oindex=-1;
	printf("Enter number of vertices\n");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &input[i][j]);
		}
	}
	printf("\nOutput\n");
	for(s=0;s<n;s++) {
		push(finished, &findex, s);
		oindex++;
		for(i=0;i<n;i++) {
			write_output(oindex, i, input[s][i]);
		}
		cur=find_closest(s);
		
		while(findex<n-1) {
			oindex++;
			push(finished, &findex, cur);
			for(i=0;i<n;i++) {
				if(!exists_in_array(finished, findex, i)) {
					x=distance_from_source(i);
					y=distance(cur, i)+distance_from_source(cur);
					write_output(oindex, i, x>y?y:x);
				}
				else {
					write_output(oindex, i, output[oindex-1][i]);
				}
			}		
			cur=find_closest(cur);
		}
		for(i=0;i<n;i++) {
			printf("%d ", output[oindex-1][i]);
		}
		printf("\n");
		reset_all();
	}
	return 0;
}
	
