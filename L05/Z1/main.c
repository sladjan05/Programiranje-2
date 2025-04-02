#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    char surname[31];
    char phone_number[31];
} Contact;

int get_choice() {
    printf("       IMENIK       \n");
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

int main(int argc, char *argv[])
{
    int choice;
    do {
        system("cls");
        choice = get_choice();
    } while (choice != 1 && choice != 2);

    system("cls");

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

        Contact contacts[n];

        for (int i = 0; i < n; i++) {
            contacts[i] = (Contact) { { 0 }, { 0 }, { 0 } };
            scanf("%s %s %s", contacts[i].name, contacts[i].surname, contacts[i].phone_number);
        }

        fwrite(contacts, sizeof(Contact), n, output);
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

        printf("================================ ================================ ================================\n");
        printf(" IME                              PREZIME                                           BROJ TELEFONA \n");
        printf("================================ ================================ ================================\n");

        for (Contact contact; fread(&contact, sizeof(Contact), 1, input); ) {
            printf(" %-30s   %-30s   %30s \n", contact.name, contact.surname, contact.phone_number);
        }

        printf("================================ ================================ ================================\n");

        fclose(input);
    }

    return 0;
}
