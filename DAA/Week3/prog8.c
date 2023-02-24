//program to find the average of a list of numbers excluding the smallest and the largest element
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct node
{
    int info;
    struct node* link;
}node_t;

typedef struct list
{
    node_t* head;
}list_t;

void init(list_t *p)
{
    p->head=NULL;
}

node_t* create_node(int key)
{
    node_t *temp=(node_t*)malloc(sizeof(node_t));
    temp->info=key;
    temp->link=NULL;
    return temp;
}

void insert(list_t *p,int key)
{
	node_t *temp=create_node(key);
	node_t *pres=p->head;
	node_t *prev=NULL;
	while(pres!=NULL && pres->info<=key)
	{
		prev=pres;
		pres=pres->link;	
	}
	if(prev==NULL)
	{
		temp->link=pres;
		p->head=temp;
	}
	else
	{
		temp->link=pres;
		prev->link=temp;	
	}	
}

void display(list_t *p)
{
    node_t *pres=p->head;
    while(pres!=NULL)
    {
        printf("%d ", pres->info);
        pres=pres->link;
    }
    printf("\n");
}

int add(list_t *p)
{
    int sum=0;
    node_t *pres=p->head->link;
    while(pres->link!=NULL)
    {
        sum=sum+pres->info;
        pres=pres->link;
    }
    return sum;
}

int main()
{
    int key, avg, n, sum, ch;
    list_t *p;
    init(p);
    printf("Enter number of elements : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&key);
        insert(p, key);
    }   
    display(p);
    sum=add(p);
    avg=sum/(n-2);
    printf("Average : %d",avg);
    printf("\n");
    return 0;
}