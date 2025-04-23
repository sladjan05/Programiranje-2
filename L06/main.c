#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ime[255];
    char prezime[255];
    char broj_indeksa[8];
} STUDENT;

typedef struct cvor {
    STUDENT info;
    struct cvor *next;
} CVOR;

void add_front(CVOR **list, STUDENT info) {
    CVOR *new = (CVOR *) malloc(sizeof(CVOR));

    new->info = info;
    new->next = *list;

    *list = new;
}

void print_all(FILE *output, CVOR *list) {
    fprintf(output, "====  ====================  ====================  =======\n");
    fprintf(output, " RB.  IME                   PREZIME                INDEKS\n");
    fprintf(output, "====  ====================  ====================  =======\n");

    for (int i = 1; list != NULL; i++, list = list->next) {
        STUDENT info = list->info;
        fprintf(output, "%3d.  %-20s  %-20s  %7s\n", i, info.ime, info.prezime, info.broj_indeksa);
    }

    fprintf(output, "====  ====================  ====================  =======\n");
}

void print_all_stdout(CVOR *list) {
    print_all(stdout, list);
}

int main() {
    CVOR *students = NULL;

    add_front(&students, (STUDENT) {
        .ime = "Sladjan",
        .prezime = "Stevanovic",
        .broj_indeksa = "1160/24"
    });

    add_front(&students, (STUDENT) {
        .ime = "Jovan",
        .prezime = "Jevtic",
        .broj_indeksa = "1159/24"
    });

    add_front(&students, (STUDENT) {
        .ime = "Nebojsa",
        .prezime = "Kaisarevic",
        .broj_indeksa = "1196/24"
    });

    add_front(&students, (STUDENT) {
        .ime = "Aleksandar",
        .prezime = "Stanisic",
        .broj_indeksa = "1158/24"
    });

    print_all_stdout(students);
    printf("\n");

    FILE *output;
    if ((output = fopen("students.txt", "w")) != NULL) {
        print_all(output, students);
        printf("Studenti su uspjesno upisani u datoteku \"students.txt\".\n");

        fclose(output);
    } else {
        printf("Nije moguce otvoriti izlaznu datoteku \"students.txt\"...\n");
    }

    return 0;
}
