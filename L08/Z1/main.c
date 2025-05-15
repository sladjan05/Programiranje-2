#include "process_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    QUEUE queue = create_queue();

    int process_count;
    do
    {
        printf("Unesite broj procesa: ");
        scanf("%d", &process_count);
    } while (process_count < 1 && printf("Broj procesa mora biti prirodan broj!\n"));

    printf("\n");

    printf("Dodajem procese u red:\n");
    printf("===============================================\n");
    while (process_count--)
        put(&queue);

    printf("\n");

    char input[15];
    do
    {
        printf("Unesite 'START' za pokretanje procesa: ");
        fflush(stdout);
        scanf("%s", input);
    } while (strcmp(input, "START") != 0);

    printf("\n");

    printf("Izvrsavam procese:\n");
    printf("=========================================================\n");

    PROCESS *process;
    while (get(&queue, &process))
    {
        print_process(process);
        fflush(stdout);

        sleep(process->execution_time);
        printf(" - IZVRSEN\n");

        free(process);
    }
}