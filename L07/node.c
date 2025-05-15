#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_before(NODE **phead, NODE **ptail, NODE *current, void *data)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;

    if (*phead == NULL)
    {
        *phead = *ptail = new;

        new->prev = NULL;
        new->next = NULL;
    }
    else
    {
        NODE *prev = current->prev;

        if (prev == NULL)
            *phead = new;
        else
            prev->next = new;

        new->prev = prev;
        new->next = current;

        current->prev = new;
    }
}

void insert_after(NODE **phead, NODE **ptail, NODE *current, void *data)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;

    if (*phead == NULL)
    {
        *phead = *ptail = new;

        new->prev = NULL;
        new->next = NULL;
    }
    else
    {
        NODE *next = current->next;

        if (next == NULL)
            *ptail = new;
        else
            next->prev = new;

        new->prev = current;
        new->next = next;

        current->next = new;
    }
}

void delete_node(NODE **phead, NODE **ptail, NODE *node)
{
    if (*phead == NULL)
        return;

    if (*phead == *ptail)
    {
        *phead = *ptail = NULL;

        free(node->data);
        free(node);
    }
    else
    {
        NODE *prev = node->prev;
        NODE *next = node->next;

        if (prev == NULL)
        {
            *phead = next;
            next->prev = NULL;
        }
        else if (next == NULL)
        {
            *ptail = prev;
            prev->next = NULL;
        }
        else
        {
            prev->next = next;
            next->prev = prev;
        }

        free(node->data);
        free(node);
    }
}

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    if (*phead == NULL)
    {
        NODE *new = (NODE *)malloc(sizeof(NODE));
        new->data = data;
        new->prev = NULL;
        new->next = NULL;

        *phead = *ptail = new;
    }
    else
    {
        NODE *current = *phead;
        int cmp_result = cmp(data, current->data);

        while (current->next != NULL && cmp_result > 0)
        {
            current = current->next;
            cmp_result = cmp(data, current->data);
        }

        if (cmp_result > 0)
            insert_after(phead, ptail, current, data);

        if (cmp_result < 0)
            insert_before(phead, ptail, current, data);
    }
}

void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    delete_node(phead, ptail, search(*phead, *ptail, data, cmp));
}

NODE *search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *))
{
    for (NODE *current = head; current != NULL; current = current->next)
    {
        if (cmp(data, current->data) == 0)
            return current;
    }
}

void write(NODE *head, void (*write_one)(const void *))
{
    for (NODE *current = head; current != NULL; current = current->next)
    {
        write_one(current->data);

        if (current->next != NULL)
            printf("\n");
    }
}

void delete_list(NODE **phead, NODE **ptail)
{
    while (*phead != NULL)
        delete_node(phead, ptail, *phead);
}