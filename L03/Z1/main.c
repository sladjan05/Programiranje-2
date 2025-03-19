#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

char* formiraj(int n, ...) {
    va_list args;
    va_start(args, n);

    int capacity = 100;
    int length = 0;
    char *res = calloc(capacity + 1, sizeof(char));

    for (int i = 0; i < n; i++) {
        int arg = va_arg(args, int);
        length = sprintf(res, "%s%d", res, arg);

        if (capacity - length < 13) {
            capacity *= 2;
            res = realloc(res, (capacity + 1) * sizeof(char));
        }
    }

    res = realloc(res, (length + 1) * sizeof(char));

    va_end(args);
}

int main() {
    printf("%s\n", formiraj(3, 234, 567, INT_MAX));

    return 0;
}
