#include "stack.h"

#include <stdlib.h>

void push(STACK_NODE **top, int data)
{
    STACK_NODE *new = malloc(sizeof(STACK_NODE));

    new->data = data;
    new->prev = *top;

    *top = new;
}

bool pop(STACK_NODE **top, int *data)
{
    if (*top == NULL)
        return false;

    STACK_NODE *temp = *top;
    *data = temp->data;
    *top = temp->prev;

    free(temp);

    return true;
}