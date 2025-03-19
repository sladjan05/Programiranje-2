#include <stdio.h>
#include <stdlib.h>

int clan(int n) {
    if (n <= 3) return n;
    return clan(n - 1) + clan(n - 2) + clan(n - 3);
}

int main() {
    int n;

    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1 && printf("n mora biti pozitivan!\n"));

    printf("%d. clan niza je %d.\n", n, clan(n));

    return 0;
}
