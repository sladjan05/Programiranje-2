#pragma once

typedef struct process
{
    char name[15];
    int execution_time;
} PROCESS;

void print_process(const PROCESS *process);