#include <stdio.h>
#include <stdlib.h>

int suma_cifara(int b) {
    if (b == 0) return 0;
    return b % 10 + suma_cifara(b / 10);
}

int main() {
    int b;

    do {
        printf("b = ");
        scanf("%d", &b);
    } while (b < 0 && printf("b mora biti nenegativan!\n"));

    printf("Suma cifara broja %d je %d.\n", b, suma_cifara(b));

    return 0;
}
