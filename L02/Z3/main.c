#include <stdio.h>
#include <stdlib.h>

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n) {
    if (n == 0) return;

    vektor_rez[0] = vektor_a[0] + vektor_b[0];
    saberi(vektor_a + 1, vektor_b + 1, vektor_rez + 1, n - 1);
}

int main() {
    int n;

    do {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1 && printf("n mora biti pozitivan!\n"));

    double v1[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v1[i]);
    }

    double v2[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v2[i]);
    }

    double res[n];
    saberi(v1, v2, res, n);

    printf("Suma vektora je vektor (");
    for (int i = 0; i < n; i++) {
        printf("%lf", res[i]);
        if (i < n - 1) printf(", ");
    }
    printf(").\n");

    return 0;
}
