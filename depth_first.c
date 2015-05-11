#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int val;
	int n_child;
	struct element **child;
	struct element *next;
} element, *ELE;

int **input, n, *finished, findex;
ELE *vertex, stk;

ELE create_element(int val) {
	ELE ptr;
	ptr=(ELE)malloc(sizeof(element));
	ptr->val=val;
	ptr->child=NULL;
	ptr->n_child=-1;
	ptr->next=NULL;
	return ptr;
}

ELE push_stack(ELE tos, ELE e) {
	if(tos==NULL) {
		return e;
	}
	e->next=tos;
	return e;
}

ELE pop_stack(ELE tos) {
	ELE ret=tos->next;
	free(tos);
	return ret;
}

void push_array(int *ar, int *index, int val) {
	ar[++(*index)]=val;
}

int in_array(int *ar, int index, int val) {
	int i;
	for(i=0;i<=index;i++) {
		if(ar[i]==val) {
			return 1;
		}
	}
	return 0;
}

void depth_first(ELE tos) {
	int i;
	if(in_array(finished, findex, tos->val)) {
		return;
	}
	printf("%d ", tos->val);
	stk=push_stack(stk, tos);
	push_array(finished, &findex, tos->val);
	for(i=0;i<=tos->n_child;i++) {
		depth_first(tos->child[i]);
	}
	stk=pop_stack(stk);
}

int main() {
	int *store=NULL, *stor=NULL, i, j, n2, n_num, k, tmp, s;
	stk=NULL;
	findex=-1;
	printf("Enter number of vertices\n");
	scanf("%d", &n);
	n2=n*n;
	stor=(int*)malloc(sizeof(int)*n2);
	vertex=(ELE*)malloc(sizeof(ELE)*n);
	finished=(int*)malloc(sizeof(int)*n);
	input=(int**)malloc(sizeof(int)*n2);
	for(i=0;i<n2;i++) {
		scanf("%d", &stor[i]);
	}
	
	for(i=0;i<n;i++) {
		input[i]=stor+n*i;
	}
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(input[i][j]>0) {
				input[j][i]=1;
			}
		}
	}
	
	printf("Enter source\n");
	scanf("%d", &s);
	for(i=0;i<n;i++) {
		vertex[i]=create_element(i);
	}
	
	for(i=0;i<n;i++) {
		n_num=-1;
		store=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++) {
			if(input[i][j]>0) {
				store[++n_num]=j;
			}
		}
		if(n_num>-1) {
			vertex[i]->child=(ELE*)malloc(sizeof(ELE)*n_num);
			vertex[i]->n_child=n_num;
		}
		else {
			continue;
		}
		for(k=0;k<=n_num;k++) {
			tmp=store[k];
			(vertex[i]->child)[k]=vertex[tmp];
		}
		free(store);
	}
	
	depth_first(vertex[s]);
	
	return 0;
}
