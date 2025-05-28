#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if defined(__linux__)
#define cls() system("clear")
#elif defined(_WIN32)
#define cls() system("cls")
#else
#define cls()
#endif

typedef struct film
{
    char naziv[64];
    char zanr[16];
    char reziser[32];
    char glumci[512];
    int godina;
} FILM;

typedef struct cvor
{
    FILM *film;
    struct cvor *left, *right;
} CVOR;

void filmcpy(FILM *dest, FILM *src);
void add_film(CVOR **root, FILM *film);
FILM *search_film(CVOR *root, const char *naziv);
int delete_film(CVOR **root, const char *naziv);
void delete_tree(CVOR *root);
void print_inorder_films(CVOR *root);
void print_sorted_films(CVOR *root);

void filmcpy(FILM *dest, FILM *src)
{
    if (dest == NULL || src == NULL)
        return;

    strcpy(dest->naziv, src->naziv);
    strcpy(dest->zanr, src->zanr);
    strcpy(dest->reziser, src->reziser);
    strcpy(dest->glumci, src->glumci);
    dest->godina = src->godina;
}

void add_film(CVOR **root, FILM *film)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(CVOR));
        (*root)->film = film;
        (*root)->left = NULL;
        (*root)->right = NULL;

        return;
    }

    int cmp = strcmp(film->naziv, (*root)->film->naziv);

    if (cmp < 0)
        add_film(&(*root)->left, film);
    else if (cmp > 0)
        add_film(&(*root)->right, film);
    else
        filmcpy((*root)->film, film);
}

FILM *search_film(CVOR *root, const char *naziv)
{
    if (root == NULL)
        return NULL;

    int cmp = strcmp(naziv, root->film->naziv);

    if (cmp < 0)
        search_film(root->left, naziv);
    else if (cmp > 0)
        search_film(root->right, naziv);
    else
        return root->film;
}

int delete_film(CVOR **root, const char *naziv)
{
    if (*root == NULL)
        return 0;

    int cmp = strcmp(naziv, (*root)->film->naziv);

    if (cmp < 0)
        return delete_film(&(*root)->left, naziv);
    else if (cmp > 0)
        return delete_film(&(*root)->right, naziv);
    else
    {
        CVOR *temp = *root;

        if ((*root)->left == NULL)
            *root = (*root)->right;
        else if ((*root)->right == NULL)
            *root = (*root)->left;
        else
        {
            CVOR *maxNode = (*root)->left;

            while (maxNode->right != NULL)
                maxNode = maxNode->right;

            filmcpy((*root)->film, maxNode->film);
            delete_film(&(*root)->left, maxNode->film->naziv);

            free(maxNode->film);
            free(maxNode);

            return 1;
        }

        free(temp->film);
        free(temp);

        return 1;
    }
}

void delete_tree(CVOR *root)
{
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);

    free(root->film);
    free(root);
}

void print_inorder_films(CVOR *root)
{
    if (root == NULL)
        return;

    print_inorder_films(root->left);

    printf(" %-63s    %-15s    %-31s     %-5d\n\n", root->film->naziv, root->film->zanr, root->film->reziser, root->film->godina);
    printf("    - Glumci: %s\n\n", root->film->glumci);

    print_inorder_films(root->right);
}

void print_sorted_films(CVOR *root)
{
    printf(" Naziv filma                                                        Zanr               Reziser                            Godina \n");
    printf("=================================================================  =================  =================================  ========\n");
    print_inorder_films(root);
    printf("=================================================================  =================  =================================  ========\n");
}

int main(void)
{
    cls();

    CVOR *root = NULL;

    // add some initial films
    FILM *film1 = malloc(sizeof(FILM));
    strcpy(film1->naziv, "INCEPTION");
    strcpy(film1->zanr, "Sci-Fi");
    strcpy(film1->reziser, "Christopher Nolan");
    strcpy(film1->glumci, "Leonardo DiCaprio, Joseph Gordon-Levitt, Ellen Page");
    film1->godina = 2010;
    add_film(&root, film1);

    FILM *film2 = malloc(sizeof(FILM));
    strcpy(film2->naziv, "THE GODFATHER");
    strcpy(film2->zanr, "Crime");
    strcpy(film2->reziser, "Francis Ford Coppola");
    strcpy(film2->glumci, "Marlon Brando, Al Pacino, James Caan");
    film2->godina = 1972;
    add_film(&root, film2);

    FILM *film3 = malloc(sizeof(FILM));
    strcpy(film3->naziv, "THE SHAWSHANK REDEMPTION");
    strcpy(film3->zanr, "Drama");
    strcpy(film3->reziser, "Frank Darabont");
    strcpy(film3->glumci, "Tim Robbins, Morgan Freeman, Bob Gunton");
    film3->godina = 1994;
    add_film(&root, film3);

    FILM *film4 = malloc(sizeof(FILM));
    strcpy(film4->naziv, "THE DARK KNIGHT");
    strcpy(film4->zanr, "Action");
    strcpy(film4->reziser, "Christopher Nolan");
    strcpy(film4->glumci, "Christian Bale, Heath Ledger, Aaron Eckhart");
    film4->godina = 2008;
    add_film(&root, film4);

    while (1)
    {
        int choice;
        do
        {
            printf("==============================\n");
            printf(" [1] Dodajte novi film        \n");
            printf(" [2] Prikaz svih filmova      \n");
            printf(" [3] Pretraga filma           \n");
            printf(" [4] Brisanje filma           \n");
            printf(" [5] Brisanje svih filmova    \n");
            printf(" [0] Izlaz                    \n");
            printf("==============================\n");
            printf("  => ");
            scanf("%d", &choice);
            cls();
        } while (choice < 0 || choice > 5);

        getchar();

        if (choice == 0)
            break;
        else if (choice == 1)
        {
            FILM *film = malloc(sizeof(FILM));

            printf("Naziv:      ");
            scanf(" %[^\n]", film->naziv);
            for (int i = 0; film->naziv[i]; i++)
                film->naziv[i] = toupper((unsigned char)film->naziv[i]);
            printf("Zanr:       ");
            scanf(" %[^\n]", film->zanr);
            printf("Reziser:    ");
            scanf(" %[^\n]", film->reziser);
            printf("Glumci:     ");
            scanf(" %[^\n]", film->glumci);
            printf("Godina:     ");
            scanf("%d", &film->godina);

            add_film(&root, film);

            cls();
            printf("Film '%s' je dodat.\n\n", film->naziv);
        }
        else if (choice == 2)
        {
            print_sorted_films(root);
            getchar();
            cls();
        }
        else if (choice == 3)
        {
            char naziv[64];
            printf("Naziv filma [PRETRAGA]: ");
            scanf(" %[^\n]", naziv);
            getchar();

            for (int i = 0; naziv[i]; i++)
                naziv[i] = toupper((unsigned char)naziv[i]);

            FILM *film = search_film(root, naziv);
            if (film != NULL)
            {
                printf("\n");
                printf(" Naziv:      %s\n", film->naziv);
                printf(" Zanr:       %s\n", film->zanr);
                printf(" Reziser:    %s\n", film->reziser);
                printf(" Glumci:     %s\n", film->glumci);
                printf(" Godina:     %d\n", film->godina);
                printf("\n");

                getchar();
                cls();
            }
            else
            {
                cls();
                printf("Film nije pronadjen.\n\n");
            }
        }
        else if (choice == 4)
        {
            char naziv[64];
            printf("Naziv filma [BRISANJE]: ");
            scanf(" %[^\n]", naziv);
            getchar();

            for (int i = 0; naziv[i]; i++)
                naziv[i] = toupper((unsigned char)naziv[i]);

            cls();

            if (delete_film(&root, naziv))
                printf("Film obrisan.\n\n");
            else
                printf("Film nije pronadjen.\n\n");
        }
        else if (choice == 5)
        {
            delete_tree(root);
            root = NULL;

            printf("Svi filmovi su obrisani.\n\n");
        }
    }
}