#include "process.h"

#include <stdio.h>

void print_process(const PROCESS *process)
{
    printf("naziv_procesa: %s; vrijeme_izvrsavanja: %ds", process->name, process->execution_time);
}