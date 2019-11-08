#include<stddef.h>
#include<stdio.h>
#include "stack.h"
/**
 * Authors : Divyanshu, Abhinav, Tejas
 * Group : A14
 */

int isFull(node* stack[], int max, int stackPointer)
{
    if(stackPointer == (max-1))
    {
        return 1;
    }
    return 0;
}
int isEmpty(node* stack[], int max, int stackPointer)
{
    if(stackPointer == -1)
    {
        return 1;
    }
    return 0;
}
void push(node* stack[], int max, int *stackPointer, node* value)
{
   if(isFull(stack, max, *stackPointer))
   {
       printf("Stack Overflow\n");
   }
   else
   {
       stack[++*stackPointer] = value;
   } 
}
void pop(node* stack[], int max, int *stackPointer)
{
    if(isEmpty(stack ,max,*stackPointer))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        --*stackPointer;
    }
    
}
node* top(node* stack[], int max, int stackPointer)
{
    if(isEmpty(stack,max, stackPointer))
    {
        printf("Stack empty, returning top = NULLCHAR\n");
        return NULL;
    }
    else
    {
        return stack[stackPointer];
    }
    
}
