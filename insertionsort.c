#include <stdio.h>
#define size 5
struct queue
{
	int front, rear;
	int ar[size];
};

typedef struct queue * Q;

void insert(Q q, int e)
{
	int i, flag=0;
	if(q->rear==size-1)
	{
		printf("Queue overflow\n");
		return;
	}	
	for(i=q->rear; i>=q->front; i--)
	{
		if(q->ar[i]<e)
		{
			q->ar[i+1]=e;
			flag=1;
			break;
		}
		else
			q->ar[i+1]=q->ar[i];
	}
	if(!flag)
		q->ar[i+1]=e;
	(q->rear)++;
}

void display(Q q)
{
	int i;
	for(i=q->front;i<=q->rear;i++)
		printf("%d ", q->ar[i]);
}

int main()
{
	struct queue q={0, -1, {}};
	int ch, e;
	while(1)
	{
		printf("Menu\n1. Insert\n2.Display\nEnter choice:\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			scanf("%d", &e);
			insert(&q, e);
			break;
			
			case 2:
			display(&q);
			break;
		}
	}
}
