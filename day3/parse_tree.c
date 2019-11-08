#include "stack.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Authors : Divyanshu, Abhinav, Tejas
 * Group : A14
 */

node *parseTree(char post_exp[])
{

    int max = strlen(post_exp);
    node **stack = malloc(max * sizeof(node *));
    int stackPointer = -1;
    for (int i = 0; i < max; i++)
    {
        node *n1 = malloc(sizeof(node));
        n1->ch = post_exp[i];
        if (post_exp[i] == '~')
        {
            if (isEmpty(stack, max, stackPointer))
            {
                printf("Malformed Expression\n");
                return NULL;
            }
            else
            {
                node *temp = top(stack, max, stackPointer);
                if (isEmpty(stack, max, stackPointer))
                {
                    printf("Malformed Expression\n");
                    return NULL;
                }
                else
                {

                    n1->right = temp;
                    n1->left = NULL;
                }
                pop(stack, max, &stackPointer);
            }
        }
        else if (post_exp[i] == 'V' || post_exp[i] == '^' || post_exp[i] == '>')
        {
            if (isEmpty(stack, max, stackPointer))
            {
                printf("Malformed Expression\n");
                return NULL;
            }
            else
            {
                node *temp = top(stack, max, stackPointer);
                n1->right = temp;
                pop(stack, max, &stackPointer);

                temp = top(stack, max, stackPointer);
                if (isEmpty(stack, max, stackPointer))
                {
                    printf("Malformed Expression\n");
                    return NULL;
                }
                else
                {
                    n1->left = temp;
                }
                pop(stack, max, &stackPointer);
            }
        }
        push(stack, max, &stackPointer, n1);
    }
    return stack[0];
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        printf("%c", root->ch);
        return;
    }
        printf("(");
        if (root->left != NULL)
            inorder(root->left);
        printf("%c", root->ch);
        if (root->right != NULL)
            inorder(root->right);
        printf(")");
}