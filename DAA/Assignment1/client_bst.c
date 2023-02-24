#include "bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, key;
    int count=0;
    bst_t *bst;
    init_bst(bst);
    insert(bst, 1, &count);
    insert(bst, 2, &count);
    insert(bst, 3, &count);
    insert(bst, 4, &count);
    insert(bst, 5, &count);
    printf("%d", bst->root->key);
    return 0;
}
