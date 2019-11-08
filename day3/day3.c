#include "stack.h"
#include "day3.h"
#include <stddef.h>
#include <stdlib.h>

node *distr(node *n1, node *n2)
{
    if(n1->ch == '^')
    {
        node* temp = malloc(sizeof(node));
        temp->ch = '^';
        temp->left = distr(n1->left,n2);
        temp->right = distr(n1->right,n2);
        return temp;
    }
    else if(n2->ch == '^')
    {
        node* temp = malloc(sizeof(node));
        temp->ch = '^';
        temp->left = distr(n1,n2->left);
        temp->right = distr(n1,n2->right);
        return temp;
    }
    else
    {
        
        node *temp = malloc(sizeof(node));
        temp->ch = 'V';
        temp->left = n1;
        temp->right = n2;
        return temp;
        

    }
    
}

node *cnf(node *root)
{
    if(
       root->ch != '^' &&
       root->ch != 'V' )
       {
           return root;
       }
    else if(root->ch == '^')
    {
        node *temp = malloc(sizeof(node));
        temp->ch = '^';
        temp->left = cnf(root->left);
        temp->right = cnf(root->right);
        return temp;
    }
    else if(root->ch == 'V')
    {
        node* temp1 = root->left;
        node* temp2 = root->right;
        free(root);
        return distr(cnf(temp1),cnf(temp2));
    }
    
    
}
