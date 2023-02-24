// Name: Srinandan A
// SRN: PES1UG20CS596
#include "heap.h"
#include <stdlib.h>

// Initialise heap
// Set heap size to 0
// Set heap max_size to parameter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) 
{
    heap->size=0;
	heap->max_size=100;
	heap->arr[max_size];
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) 
{
    int c;int p;
	if(heap->size==heap->max_size-1)
	{
		(*count_ptr)++;
		return;
	}
	else
	{
		c=heap->size;
		p=(c-1)/2;
		(*count_ptr)++;
		while(c>0 && heap->arr[p]<key)
		{
			heap->arr[c]=heap->arr[p];
			c=p;
			p=(c-1)/2;
		}
		heap->arr[c]=key;
		heap->size++;
	}	
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr) 
{
	if(heap->size==0)
	{
		return -1;
	}
	else
	{
		int i;
		int max=heap->arr[0];
		for(i=0; i<heap->size; i++)
		{
			(*count_ptr)++;
			if(heap->arr[i]>max)
			{
				max=heap->arr[i];
			}
		}
		for(int j=i+1; j<heap->size; j--)
		{
			heap->arr[j-1]=heap->arr[j];
		}
		heap->size--;
		return max;
	}
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) 
{
	if(heap->size==0)
	{
		return -1;
	}
	else
	{
		for(int i=0; i<heap->size; i++)
		{
			(*count_ptr)++;
			if(heap->arr[i]==key)
			{
				return key;
			}
		}
		return -1;
	}
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr) 
{
	if(heap->size==0)
	{
		return -1;
	}
	else
	{
		int max=heap->arr[0];
		for(int i=0; i<heap->size; i++)
		{
			(*count_ptr)++;
			if(heap->arr[i]>max)
			{
				max=heap->arr[i];
			}
		}
		return max;
	}
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) 
{
	if(heap->size==0)
	{
		return -1;
	}
	else
	{
		int min=heap->arr[0];
		for(int i=0; i<heap->size; i++)
		{
			(*count_ptr)++;
			if(heap->arr[i]<min)
			{
				min=heap->arr[i];
			}
		}
		return min;
	}
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) 
{
	if(heap->size==0)
	{
		return;
	}
	else
	{
		for(int i=0; i<heap->size; i++)
		{
			heap->arr[i]=0;
		}
		heap->size=0;
	}
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) 
{
	heap->size=0;
	heap->max_size=0;
	heap->arr=NULL;
	free(heap);
}
