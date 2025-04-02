#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *output;

    if (argc != 2) {
        printf("Program prima tacno 1 argument sa komandne linije...\n");
        return -1;
    }

    if (!(output = fopen(argv[1], "w"))) {
        printf("Nije moguce kreirati izlaznu datoteku...\n");
        return -1;
    }

    fprintf(output, "=== ===== ==================== ======\n");
    fprintf(output, "RB. SIFRA NAZIV                CIJENA\n");
    fprintf(output, "=== ===== ==================== ======\n");

    int n;
    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1 && printf("n mora biti prirodan broj!\n"));

    for (int i = 0; i < n; i++) {
        char id[6];
        char name[22];
        float price;

        printf("%d. artikal: ", i + 1);
        scanf("%5s %[^0-9] %f", id, name, &price);

        name[20] = '\0';

        fprintf(output, "%2d. %5s %-20s %6.2f\n", i + 1, id, name, price);
    }

    fprintf(output, "=== ===== ==================== ======\n");
    fclose(output);

    return 0;
}
