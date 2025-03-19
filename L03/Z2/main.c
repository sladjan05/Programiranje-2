#include <stdio.h>
#include <stdlib.h>

int is_even(int n) {
    return n % 2 == 0;
}

int is_positive(int n) {
    return n > 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina) {
    *duzina = 0;
    *pocetak = NULL;

    int current_length = 0;
    int *current_start = NULL;

    for (int i = 0; i < n; i++) {
        if (s(niz[i])) {
            current_length++;

            if (current_start == NULL) {
                current_start = &niz[i];
            }
        } else {
            if (current_length > *duzina) {
                *duzina = current_length;
                *pocetak = current_start;
            }

            current_length = 0;
            current_start = NULL;
        }
    }

    if (current_length > *duzina) {
        *duzina = current_length;
        *pocetak = current_start;
    }
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

    int *is_even_start;
    int is_even_length;
    serija(arr, n, is_even, &is_even_start, &is_even_length);

    int *is_positive_start;
    int is_positive_length;
    serija(arr, n, is_positive, &is_positive_start, &is_positive_length);

    printf("Najduzi podniz ciji su clanovi parni brojevi je: ");
    for (int i = 0; i < is_even_length; i++) {
        printf("%d ", is_even_start[i]);
    }
    printf("\n");

    printf("Najduzi podniz ciji su clanovi pozitivni brojevi je: ");
    for (int i = 0; i < is_positive_length; i++) {
        printf("%d ", is_positive_start[i]);
    }
    printf("\n");

    return 0;
}
