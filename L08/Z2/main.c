#include <stdio.h>

#include "stack.h"
#include "buffer.h"
#include "util.h"

int main(void)
{
    BUFFER buffer = create_buffer();
    STACK_NODE *top = NULL;

    cls();

    while (true)
    {
        int choice;
        do
        {
            printf("======================\n");
            printf(" [1] Dodaj u bafer    \n");
            printf(" [2] Ukloni iz bafera \n");
            printf(" [3] Ispisi bafer     \n");
            printf("======================\n");
            printf(" => ");
            scanf("%d", &choice);
        } while ((choice < 0 || choice > 3) && (cls(), printf("Pogresan unos!\n\n")));

        cls();

        switch (choice)
        {
        case 0:
        {
            int element;
            while (pop(&top, &element))
                printf("%d ", element);
            printf("\n");

            return 0;
        }
        case 1:
        {
            if (is_full(&buffer))
            {
                printf("Bafer je pun!\n");
                break;
            }

            int element;
            printf("Unesite element: ");
            scanf("%d", &element);

            put(&buffer, element);
            push(&top, element);

            printf("Dodan element: %d\n", element);

            break;
        }
        case 2:
        {
            int element;
            if (get(&buffer, &element))
                printf("Uklonjen element: %d\n", element);
            else
                printf("Bafer je prazan!\n");

            break;
        }
        case 3:
        {
            if (is_empty(&buffer))
            {
                printf("Bafer je prazan!\n");
                break;
            }

            printf("Bafer: ");

            int element;
            while (get(&buffer, &element))
                printf("%d ", element);
            printf("\n");

            break;
        }
        }

        printf("\n");
    }
}