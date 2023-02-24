/*Write a C Program to simulate Segmentation
Take as input
1.Segment Number
2.Base Address
3.Segment limit
*/

#include<stdio.h>
#include<stdlib.h>

struct list
{
	int seg_no;
	int base_address;
	int seg_limit;
	struct list *next;
};
struct list *p;

void insert(struct list *q,int base,int limit,int seg)
{
	if(p == NULL)
	{
		p = malloc(sizeof(struct list));
		p->seg_limit = limit;
		p->base_address = base;
		p->seg_no = seg;
		p->next = NULL;
	}
	else
	{
		while(q->next!=NULL)
		{
			q = q->next;
			printf("\nYes\n");
		}
		q->next = malloc(sizeof(struct list));
		q->next->seg_limit = limit;
		q->next->base_address = base;
		q->next->seg_no = seg;
		q->next->next = NULL;
	}
}

int find(struct list *q,int seg)
{
	while(q->seg_no != seg)
	{
		q=q->next;
	}
	return q->seg_limit;
}

int search(struct list *q,int seg)
{
	while(q->seg_no != seg)
	{
		q=q->next;
	}
	return q->base_address;
}

void main()
{
	int n = 0;
	p=NULL;
	int seg,offset,limit,base,c,s,physical;
	printf("Enter segment table\n");
	printf("Enter -1 as segment value for termination\n");
	do
	{
		printf("Enter segment number:\n");
		scanf("%d",&seg);
		if(seg != -1)
		{
			printf("Enter base address:\n");
			scanf("%d",&base);
			printf("Enter value for limit:\n");
			scanf("%d",&limit);
			insert(p,base,limit,seg);
			n++;
		}
	}
	while(seg != -1);
	while(n > 0 )
	{
		printf("Enter offset:\n");
		scanf("%d",&offset);
		printf("Enter the segmentation number:\n");
		scanf("%d",&seg);
		c = find(p,seg);
		s = search(p,seg);
		if(offset<c)
		{
			physical = s+offset;
			printf("Address in physical memory %d\n",physical);
		}
		else
		{
			printf("\nError!!");
		}
		n--;
	}
}