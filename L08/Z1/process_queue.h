#pragma once

#include "process.h"

#include <stdbool.h>

typedef struct node
{
    PROCESS *process;
    struct node *next;
} NODE;

typedef struct queue
{
    int size;
    NODE *front, *rear;
} QUEUE;

QUEUE create_queue(void);

void put(QUEUE *queue);
bool get(QUEUE *queue, PROCESS **process);