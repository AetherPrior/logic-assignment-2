#include "stack.h"
#include "parse_tree.h"
#include <stdlib.h> // for NULL definition

/**
 * Converts a given parse tree to a NNF form ( without any negations except on atoms)
 * @param node : pointer to a node in the parse tree
 * @return pointer to the given node, sub parse tree of which is in NNF
 */
node *nnf(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    if (root->ch == '~' && root->left == NULL && root->right->ch == '~' && root->right->left == NULL && root->right->right != NULL)
    {
        root=nnf(root->right->right);
    }
    else if (root->ch == '^' || root->ch == 'V')
    {
        root->left = nnf(root->left);
        root->right = nnf(root->right);
    }
    else if (root->ch == '~' && root->right->ch == '^')
    {
        root->ch = 'V';
        node *temp1 = malloc(sizeof(node));
        node *temp2 = malloc(sizeof(node));
        temp1->ch = '~';
        temp2->ch = '~';
        temp1->left = NULL;
        temp2->left = NULL;
        temp1->right = root->right->left;
        temp2->right = root->right->right;
        root->left = nnf(temp1);
        root->right = nnf(temp2);
    }
    else if (root->ch == '~' && root->right->ch == 'V')
    {
        root->ch = '^';
        node *temp1 = malloc(sizeof(node));
        node *temp2 = malloc(sizeof(node));
        temp1->ch = '~';
        temp2->ch = '~';
        temp1->left = NULL;
        temp2->left = NULL;
        temp1->right = root->right->left;
        temp2->right = root->right->right;
        root->left = nnf(temp1);
        root->right = nnf(temp2);
    }
    return root;
}