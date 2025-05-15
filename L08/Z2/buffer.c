#include "buffer.h"

BUFFER create_buffer(void)
{
    return (BUFFER){.front = 0, .rear = 0, .elements = {0}};
}

bool is_empty(BUFFER *buffer)
{
    return buffer->front == buffer->rear;
}

bool is_full(BUFFER *buffer)
{
    return (buffer->rear + 1) % BUFFER_SIZE == buffer->front;
}

bool put(BUFFER *buffer, int element)
{
    if (is_full(buffer))
        return false;

    buffer->elements[buffer->rear] = element;
    buffer->rear = (buffer->rear + 1) % BUFFER_SIZE;

    return true;
}

bool get(BUFFER *buffer, int *element)
{
    if (is_empty(buffer))
        return false;

    *element = buffer->elements[buffer->front];
    buffer->front = (buffer->front + 1) % BUFFER_SIZE;

    return true;
}