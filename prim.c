#include <stdio.h>
#include <stdlib.h>

#define INF 9999

int input[10][10], n, finished[10], findex, vertex[10], vindex;

typedef struct undirected {
	int s;
	int d;
	struct undirected *next;
} undirected, *UNDIRECTED;

UNDIRECTED new_connection(int s, int d) {
	UNDIRECTED ptr;
	ptr=(UNDIRECTED)malloc(sizeof(undirected));
	ptr->s=s;
	ptr->d=d;
	ptr->next=NULL;
	return ptr;
}

UNDIRECTED insert_ll(UNDIRECTED first, UNDIRECTED node) {
	if(first==NULL) {
		return node;
	}
	node->next=first;
	return node;
}

UNDIRECTED destroy_ll(UNDIRECTED first) {
	UNDIRECTED cur=first;
	while(cur!=NULL) {
		cur=first->next;
		free(first);
		first=cur;
	}
	return NULL;
}

void push_array(int *ar, int *index, int val) {
	(*index)++;
	ar[(*index)]=val;
}

int remove_element_array(int *ar, int *index, int val) {
	int i, j;
	for(i=0;i<=(*index);i++) {
		if(val==ar[i]) {
			for(j=i;j<=(*index);j++) {
				ar[j]=ar[j+1];
			}
			break;
		}
	}
	(*index)--;
}

void reset_all() {
	int i;
	vindex=-1;
	for(i=0;i<n;i++) {
		push_array(vertex, &vindex, i);
	}
	findex=-1;
}

int distance(int s, int d) {
	return input[s][d];
}

UNDIRECTED find_minimum(UNDIRECTED first) {
	UNDIRECTED cur=first, ret;
	int min=INF;
	ret=new_connection(0, 0);
	while(cur!=NULL) {
		if(distance(cur->s, cur->d)<min) {
			ret->s=cur->s;
			ret->d=cur->d;
		}
		cur=cur->next;
	}
	return ret;
}

void print_array(int *ar, int index) {
	int i;
	for(i=0;i<=index;i++) {
		printf("%d ", ar[i]);
	}
}

int main() {
	int i, j, s, sum=0;
	UNDIRECTED first=NULL, min;
	printf("Enter number of vertices\n");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &input[i][j]);
		}
	}
	printf("Enter source\n");
	scanf("%d", &s);
	reset_all();
	remove_element_array(vertex, &vindex, s);
	push_array(finished, &findex, s);
	while(findex<n-1) {
		for(i=0;i<=findex;i++) {
			for(j=0;j<=vindex;j++) {
				first=insert_ll(first, new_connection(finished[i], vertex[j]));
			
			}
		}
		min=find_minimum(first);
		push_array(finished, &findex, min->d);
		remove_element_array(vertex, &vindex, min->d);
		first=destroy_ll(first);
		sum+=distance(min->s, min->d);
		printf("%d->%d = %d\n", min->s, min->d, distance(min->s, min->d));
	}
	printf("Total distance = %d\n", sum);
	return 0;
}

