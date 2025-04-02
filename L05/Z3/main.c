#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_choice() {
    printf("   CIJELI BROJEVI   \n");
    printf("====================\n");
    printf(" 1. Novi unos       \n");
    printf(" 2. Citaj iz fajla  \n");
    printf("====================\n");
    printf("\n");
    printf("   IZBOR: ");

    int choice;
    scanf("%d", &choice);

    return choice;
}

int desc_ints(const void *a, const void *b) {
    int a_int = *(int *) a;
    int b_int = *(int *) b;

    return b_int - a_int;
}

int main(int argc, char *argv[])
{
    int choice;
    do {
        system("cls");
        choice = get_choice();
    } while (choice != 1 && choice != 2);

    system("cls");
    getchar();

    if (choice == 1) {
        FILE *output;

        if (argc != 2) {
            printf("Program prima tacno 1 argument sa komandne linije...\n");
            return -1;
        }

        if (!(output = fopen(argv[1], "wb"))) {
            printf("Nije moguce kreirati ili pronaci izlaznu datoteku...\n");
            return -1;
        }

        int n;
        do {
            printf("n = ");
            scanf("%d", &n);
        } while (n < 1 && printf("n mora biti prirodan broj!\n"));
        printf("\n");

        printf("Unesite brojeve: ");

        int nums[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        qsort(nums, n, sizeof(int), desc_ints);

        fwrite(nums, sizeof(int), n, output);
        fclose(output);
    } else if (choice == 2) {
        char filename[255];

        printf("Ime datoteke: ");
        scanf("%s", filename);
        printf("\n");

        FILE *input;

        if (strcmp(filename, "#") == 0) {
            if (argc != 2) {
                printf("Program prima tacno 1 argument sa komandne linije...\n");
                return -1;
            }

            strcpy(filename, argv[1]);
        }

        if (!(input = fopen(filename, "rb"))) {
            printf("Ulazna datoteka nije pronadjena...\n");
            return -1;
        }

        printf("Sacuvani brojevi: ");
        for (int num; fread(&num, sizeof(int), 1, input); ) {
            printf("%d ", num);
        }
        printf("\n");

        fclose(input);
    }

    return 0;
}
