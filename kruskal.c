#include <stdio.h>
#include <stdlib.h>
#define INF 9999;

typedef struct point {
	struct point *left;
	struct point *right;
	int val;
} point, *POINT;

POINT *par;
int ar[10][10], over[100][2], n;

POINT create_point(int val) {
	POINT ret;
	ret=(POINT)malloc(sizeof(point));
	ret->left=ret->right=NULL;
	ret->val=val;
	return ret;
}

int is_in_set_rec(POINT x, int val) {
	int a, b;
	if(x==NULL) {
		return 0;
	}
	if(x->val==val) {
		return 1;
	}
	a=is_in_set_rec(x->left, val);
	b=is_in_set_rec(x->right, val);
	return a>b?a:b;
}

int is_in_set(int a, int b) {
	return is_in_set_rec(par[a], b);
}

void find_min(int *min, int *si, int *sj) {
	int i, j, newmin=INF;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(ar[i][j]>=*min) {
				if(!is_in_set(i, j)) {
					if(ar[i][j]<=newmin) {
						*si=i;
						*sj=j;
						
					}
				}
			}
		}
	}
	*min=newmin;
}

void add_to_point(POINT x, int j) {
	if(x->left==NULL) {
		x->left=par[j];
	}
	else {
		if(x->right==NULL) {
			x->right=par[j];
		}
	}
}

void add_rec(POINT x, int i, int j) {
	if(x==NULL) {
		return;
	}
	if(x->val==i) {
		add_to_point(x, j);
	}
	else {
		if(x->val==j) {
			add_to_point(x, i);
		}
		else {
			add_rec(x->left, i, j);
			add_rec(x->right, i, j);
		}
	}
}

void add_to_set(int k, int j) {
	//~ if(par[i]->left==NULL) {
		//~ par[i]->left=par[j];
	//~ }
	//~ else {
		//~ if(par[i]->right==NULL) {
			//~ par[i]->right=par[j];
		//~ }
		//~ else {
			//~ add_to_set(j, i);
		//~ }
	//~ }
	int i;
	for(i=0;i<n;i++) {
		add_rec(par[i], k, j);
	}
}

void print_rec(POINT x) {
	if(x==NULL) {
		return;
	}
	print_rec(x->left);
	printf("%d ", x->val);
	print_rec(x->right);
}

void print_points() {
	int i;
	for(i=0;i<n;i++) {
		print_rec(par[i]);
		printf("\n");
	}
}

int main() {
	int i, j, k, min=0, sum=0;
	printf("Enter number of vertex\n");
	scanf("%d", &n);
	par=(POINT*)malloc(sizeof(POINT)*n);
	
	for(i=0;i<n;i++) {
		par[i]=create_point(i);
	}
	printf("Enter matrix\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &ar[i][j]);
		}
	}

	for(k=0;k<n-1;k++) {
		print_points();
		find_min(&min, &i, &j);
		add_to_set(i, j);
		sum+=ar[i][j];
		printf("%d ----- %d\n", i, j);
	}
	print_points();
	printf("Shortest path is %d\n", sum);
	return 0;
}
	
