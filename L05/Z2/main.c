#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_choice() {
    printf("   CEZAROVA SIFRA   \n");
    printf("====================\n");
    printf(" 1. Novi tekst      \n");
    printf(" 2. Citaj iz fajla  \n");
    printf("====================\n");
    printf("\n");
    printf("   IZBOR: ");

    int choice;
    scanf("%d", &choice);

    return choice;
}

char encrypt_char(char ch) {
    if ('A' <= ch && ch <= 'Z') return 'A' + (ch - 'A' + 3) % 26;
    if ('a' <= ch && ch <= 'z') return 'a' + (ch - 'a' + 3) % 26;
    return ch;
}

char decrypt_char(char ch) {
    if ('A' <= ch && ch <= 'Z') return 'A' + (ch - 'A' + 23) % 26;
    if ('a' <= ch && ch <= 'z') return 'a' + (ch - 'a' + 23) % 26;
    return ch;
}

void encrypt(char *string) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        string[i] = encrypt_char(string[i]);
    }
}

void decrypt(char *string) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        string[i] = decrypt_char(string[i]);
    }
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
            printf("Nije moguce kreirati izlaznu datoteku...\n");
            return -1;
        }

        char text[3000] = { 0 };
        printf("Unesite tekst: \n\n");
        fgets(text, sizeof(text), stdin);

        int len = strlen(text) - 1;

        text[len] = '\0';
        encrypt(text);

        fwrite(text, sizeof(char), len, output);
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

        fseek(input, 0, SEEK_END);
        int len = ftell(input);
        fseek(input, 0, SEEK_SET);

        char text[3000] = { 0 };

        fread(text, sizeof(char), len, input);
        printf("Sifrovano:      %s\n", text);

        decrypt(text);
        printf("Original:       %s\n", text);

        fclose(input);
    }

    return 0;
}
