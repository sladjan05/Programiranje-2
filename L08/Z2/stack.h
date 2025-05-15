#pragma once

#include <stdbool.h>

typedef struct stack_node
{
    int data;
    struct stack_node *prev;
} STACK_NODE;

void push(STACK_NODE **top, int data);
bool pop(STACK_NODE **top, int *data);
