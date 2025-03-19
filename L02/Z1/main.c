#include <stdio.h>
#include <stdlib.h>

int suma(int *niz, int n) {
    if (n == 1) return niz[0];
    return niz[0] + suma(niz + 1, n - 1);
}

int main() {
    int n;

    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1 && printf("n mora biti pozitivan!\n"));

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Suma clanova niza je %d.\n", suma(arr, n));

    return 0;
}
