#pragma once

#include <stdbool.h>

#define BUFFER_SIZE (5 + 1)

typedef struct buffer
{
    int front, rear;
    int elements[BUFFER_SIZE];
} BUFFER;

BUFFER create_buffer(void);

bool is_empty(BUFFER *buffer);
bool is_full(BUFFER *buffer);
bool put(BUFFER *buffer, int element);
bool get(BUFFER *buffer, int *element);