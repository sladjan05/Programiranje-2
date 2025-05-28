#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char str[100];
    struct node *left, *right;
} NODE;

void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
void delete(NODE *root);

void preorder(NODE *root)
{
    if (root == NULL)
        return;

    printf("%s", root->str);
    preorder(root->left);
    preorder(root->right);
}

void inorder(NODE *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%s", root->str);
    inorder(root->right);
}

void postorder(NODE *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%s", root->str);
}

void delete(NODE *root)
{
    if (root == NULL)
        return;

    delete(root->left);
    delete(root->right);
    free(root);
}

int main(void)
{
    NODE *A = malloc(sizeof(NODE));
    NODE *B = malloc(sizeof(NODE));
    NODE *C = malloc(sizeof(NODE));
    NODE *D = malloc(sizeof(NODE));
    NODE *E = malloc(sizeof(NODE));
    NODE *F = malloc(sizeof(NODE));
    NODE *G = malloc(sizeof(NODE));
    NODE *H = malloc(sizeof(NODE));
    NODE *I = malloc(sizeof(NODE));
    NODE *J = malloc(sizeof(NODE));

    strcpy(A->str, "A");
    strcpy(B->str, "B");
    strcpy(C->str, "C");
    strcpy(D->str, "D");
    strcpy(E->str, "E");
    strcpy(F->str, "F");
    strcpy(G->str, "G");
    strcpy(H->str, "H");
    strcpy(I->str, "I");
    strcpy(J->str, "J");

    A->left = B;
    A->right = C;

    B->left = D;
    B->right = E;

    C->left = NULL;
    C->right = F;

    D->left = G;
    D->right = NULL;

    E->left = NULL;
    E->right = H;

    F->left = I;
    F->right = NULL;

    G->left = NULL;
    G->right = NULL;

    H->left = J;
    H->right = NULL;

    I->left = NULL;
    I->right = NULL;

    J->left = NULL;
    J->right = NULL;

    printf("Preorder: ");
    preorder(A);
    printf("\n");

    printf("Inorder: ");
    inorder(A);
    printf("\n");

    printf("Postorder: ");
    postorder(A);
    printf("\n");

    delete(A);

    return 0;
}
