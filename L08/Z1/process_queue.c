#include "process_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

QUEUE create_queue(void)
{
    return (QUEUE){
        .size = 0,
        .front = NULL,
        .rear = NULL};
}

void put(QUEUE *queue)
{
    PROCESS *process = (PROCESS *)malloc(sizeof(PROCESS));
    sprintf(process->name, "proces%d", queue->size + 1);
    process->execution_time = rand() % 5 + 1;

    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->process = process;
    new->next = NULL;

    if (queue->size == 0)
    {
        queue->front = queue->rear = new;
    }
    else
    {
        queue->rear->next = new;
        queue->rear = new;
    }

    queue->size++;

    print_process(process);
    printf("\n");
}

bool get(QUEUE *queue, PROCESS **process)
{
    if (queue->size == 0)
        return false;

    *process = queue->front->process;

    NODE *next = queue->front->next;
    free(queue->front);

    queue->front = next;
    if (queue->size == 1)
        queue->rear = NULL;

    queue->size--;

    return 1;
}