#pragma once

typedef struct node
{
    void *data;
    struct node *prev, *next;
} NODE;

void insert_before(NODE **phead, NODE **ptail, NODE *current, void *data);
void insert_after(NODE **phead, NODE **ptail, NODE *current, void *data);
void delete_node(NODE **phead, NODE **ptail, NODE *node);

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
NODE *search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *));
void write(NODE *head, void (*write_one)(const void *));
void delete_list(NODE **phead, NODE **ptail);