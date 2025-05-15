#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

void write_one(const void *data)
{
    printf("%s", (char *)data);
}

int main(void)
{
    NODE *phead = NULL, *ptail = NULL;

    char *days[] = {
        "ponedjeljak",
        "utorak",
        "srijeda",
        "cetvrtak",
        "petak",
        "subota"};

    for (int i = 0; i < sizeof(days) / sizeof(days[0]); i++)
    {
        char *day = (char *)malloc(strlen(days[i]) + 1);
        strcpy(day, days[i]);
        add(&phead, &ptail, day, cmp);
    }

    printf("Lista:\n");
    printf("=====================\n");
    write(phead, write_one);
    printf("\n");

    printf("\n");

    printf("Brisem subotu iz liste... ");
    delete(&phead, &ptail, "subota", cmp);
    printf("Obrisano.\n");

    printf("\n");

    printf("Lista:\n");
    printf("=====================\n");
    write(phead, write_one);
    printf("\n");
}