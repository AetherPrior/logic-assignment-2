#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Authors : Divyanshu, Abhinav, Tejas
 * Group : A14
 */

node *impl_free(node *root)
{
    if(root == NULL)
    {
        return root;
    }
    else if((root->ch) == '>')
    {
        node *temp = malloc(sizeof(node));
        temp->ch = '~';
        temp->right = root->left;
        temp->left = NULL;
        root->left = temp;
        root->ch = 'V';
    }
    impl_free(root->left);
    impl_free(root->right);
    return root;
}