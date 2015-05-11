#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int val;
	int n_child;
	struct element **child;
	struct element *next;
} element, *ELE;

int **input, n, *finished, findex;
ELE *vertex, queue;

ELE create_element(int val) {
	ELE ptr;
	ptr=(ELE)malloc(sizeof(element));
	ptr->val=val;
	ptr->child=NULL;
	ptr->n_child=-1;
	ptr->next=NULL;
	return ptr;
}

void push_array(int *ar, int *index, int val);

ELE insert_queue(ELE front, ELE e) {
	ELE first=front;
	printf("%d ", e->val);
	push_array(finished, &findex, e->val);
	if(first==NULL) {
		return e;
	}
	while(first->next!=NULL) {
		first=first->next;
	}
	first->next=e;
	return front;
}

ELE delete_queue(ELE first) {
	if(first==NULL) {
		return NULL;
	}
	ELE ret=first->next;

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

void breadth_first() {
	int i;
	if(queue==NULL) {
		return;
	}
	for(i=0;i<=queue->n_child;i++) {
		if(!in_array(finished, findex, queue->child[i]->val)) {
			queue=insert_queue(queue, queue->child[i]);
		}
	}
	queue=delete_queue(queue);
	breadth_first();
}

int main() {
	int *store=NULL, *stor=NULL, i, j, n2, n_num, k, tmp, s;
	queue=NULL;
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
	
	queue=insert_queue(queue, vertex[s]);
	breadth_first();
	
	return 0;
}

