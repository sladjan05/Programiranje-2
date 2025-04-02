#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_letter(char ch) {
    return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}

void read_next_word(FILE *file, int *len, char *word) {
    for (int i = 0, ch = fgetc(file); ; i++, ch = fgetc(file)) {
        if (ch == EOF) {
            *len = i;
            word[i] = '\0';

            break;
        }

        if (!is_letter(ch)) {
            if (i == 0) {
                read_next_word(file, len, word);
                break;
            }

            *len = i;
            word[i] = '\0';

            break;
        }

        word[i] = ch;
    }
}

int main(int argc, char *argv[])
{
    FILE *input;
    FILE *output;

    if (argc != 3) {
        printf("Program prima tacno 2 argumenta sa komandne linije...\n");
        return -1;
    }

    if (!(input = fopen(argv[1], "r"))) {
        printf("Ulazna datoteka nije pronadjena...\n");
        return -1;
    }

    if (!(output = fopen(argv[2], "w"))) {
        printf("Nije moguce kreirati izlaznu datoteku...\n");
        return -1;
    }

    int max_len = -1;
    char longest_word[255] = { 0 };

    int len;
    char word[255] = { 0 };

    while (read_next_word(input, &len, word), len) {
        fprintf(output, "%s\n", word);

        if (max_len < len) {
            max_len = len;
            strcpy(longest_word, word);
        }
    }

    printf("Najduza rijec je: %s\n", longest_word);

    fclose(input);
    fclose(output);

    return 0;
}
