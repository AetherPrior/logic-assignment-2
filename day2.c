
#include "stack.h"
#include<stddef.h>
#include<stdlib.h>

node *nnf(node *root)
{
    if(root == NULL)
    {
        return root;
    }
    else if(root->ch != '^' || root->ch != 'V' || root->ch != '~')
    {
        return root;
    }
    else if(root->ch == '~')
    {
        if(root->right->ch == '~')
        {
            node *temp = root;
            node *temp2 = root->right;
            root = root->right->right;
            free(temp);
            free(temp2);
        }
        else if(root->right->ch== '^')
        {
           node *temp = root->right;
            
        }
    }
    node *temp = root->left;
    if(temp->ch != '~')
    {
        nnf(root->left);
    }
    else if(temp->ch == '~' && temp->right->ch == '~')
    {
        root->left = temp->right->right;
        free(temp->right);
        free(temp);
    }
    else if(temp->ch == '~' && temp->right->ch == 'V')
    {
        node *t1 = malloc(sizeof(node));
        t1->ch = '~';
        node *t2 = malloc(sizeof(node));
        t2->ch = '~';
        root->left = temp->right;
        temp->right->ch = '^';
        t1->right = temp->right->left;
        t2->right = temp->right->right;
        temp->right->left = t1;
        temp->right->left = t2;
        free(temp);
        nnf(root->left);
    }
    else if(temp->ch == '~' && temp->right->ch == '^')
    {
        node *t1 = malloc(sizeof(node));
        t1->ch = '~';
        node *t2 = malloc(sizeof(node));
        t2->ch = '~';
        root->left = temp->right;
        temp->right->ch = 'V';
        t1->right = temp->right->left;
        t2->right = temp->right->right;
        temp->right->left = t1;
        temp->right->left = t2;
        free(temp);
        nnf(root->left);
    }

    temp = root->right;
    if(temp->ch != '~')
    {
        nnf(root->right);
    }
    else if(temp->ch == '~' && temp->right->ch == '~')
    {
        root->left = temp->right->right;
        free(temp->right);
        free(temp);
    }
    else if(temp->ch == '~' && temp->right->ch == 'V')
    {
        node *t1 = malloc(sizeof(node));
        t1->ch = '~';
        node *t2 = malloc(sizeof(node));
        t2->ch = '~';
        root->right = temp->right;
        temp->right->ch = '^';
        t1->right = temp->right->left;
        t2->right = temp->right->right;
        temp->right->left = t1;
        temp->right->left = t2;
        free(temp);
        nnf(root->right);
    }
    else if(temp->ch == '~' && temp->right->ch == '^')
    {
        node *t1 = malloc(sizeof(node));
        t1->ch = '~';
        node *t2 = malloc(sizeof(node));
        t2->ch = '~';
        root->right = temp->right;
        temp->right->ch = 'V';
        t1->right = temp->right->left;
        t2->right = temp->right->right;
        temp->right->left = t1;
        temp->right->left = t2;
        free(temp);
        nnf(root->right);
    }
    return root;
}