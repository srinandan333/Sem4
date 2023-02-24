// Name: Srinandan A
// SRN: PES1UG20CS596
#include "bst.h"
#include <stdlib.h>

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root=NULL;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
static void insert_rec(node_t *p, int key, int *count_ptr)
{
    (*count_ptr)++;
    node_t *temp;  
	temp=(node_t*)malloc(sizeof(node_t));
    temp->left=temp->right=NULL;
    temp->key=key;
    if(p==NULL)
    {
        p=temp;
        return;
    }
    if(key<p->key)
    {
        insert_rec(p->left, key, count_ptr);
    }
    else
    {
        insert_rec(p->right, key, count_ptr);
    } 
}

//wrap function for the above recursive function
void insert(bst_t *tree, int key, int *count_ptr)
{
    insert_rec(tree->root, key, count_ptr);
}

// Delete key from the BST
// Replaces node with in-order successor
static node_t *delete_rec(node_t *r, int key, int *count_ptr)
{
    (*count_ptr)++;
    node_t *temp;node_t *p;
	if(r==NULL) 
    {
        return r;
    }
	else if(key<r->key)
    {
		r->left=delete_rec(r->left,key, count_ptr);	
    }
	else if(key>r->key)
    {
		r->right=delete_rec(r->right,key, count_ptr);
    }
	else
	{
		if(r->left==NULL)
		{
			temp=r->right;
			free(r);
			return temp;
			
		}
		else if(r->right==NULL)
		{
			temp=r->left;
			free(r);
			return temp;
		}
		else
		{
			p=r->right;
			while(p->left!=NULL) 
			{
				p=p->left;
			}
			r->key=p->key;
			r->right=delete_rec(r->right,p->key, count_ptr);
		}
	}
	return r;
}

//wrap function for the above recursive function
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root=delete_rec(tree->root,key, count_ptr);
}

// Searches for the element key in the bst
// Returns the element if found, else -1
static int search_rec(node_t *p, int key, int *count_ptr)
{
    (*count_ptr)++;
    if(p->key==key)
    {
        return key;
    }
    else
    {
        int l=search_rec(p->left, key, count_ptr);
        int r=search_rec(p->right, key, count_ptr);
    }
}

//wrap function for the above recursive function
int search(const bst_t *tree, int key, int *count_ptr)
{
    int res=search_rec(tree->root, key, count_ptr);
}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    node_t *p=tree->root;
    if(p==NULL)
    {
        return -1;
    }
    else
    {
        while(p->right!=NULL)
        {
            p=p->right;
            (*count_ptr)++;
        }
        return p->key;
    }
}

// Deletes all the elements of the bst
static void free_rec(node_t *p)
{
    if(p==NULL) 
    {
        return;
    }
    else
    {
        free_rec(p->left);
        free_rec(p->right);
        free(p);
    }
}

//wrap function for the above recursive function
void free_bst(bst_t *bst) 
{
    free_rec(bst->root);
}

// Deletes all the elements of the bst and ensures it can be used again
static node_t *clear_rec(node_t *p)
{
    if(p==NULL)
    {
        return;
    }
    else
    {
        clear_rec(p->left);
        clear_rec(p->right);
        p->key=0;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
}

//wrap function for the above recursive function
void clear_bst(bst_t *bst)
{
    bst->root=clear_rec(bst->root);
}
