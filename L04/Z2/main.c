#include <stdio.h>

#define PI 3.14159265

int main(int argc, char *argv[])
{
    FILE *input;

    if (argc != 2) {
        printf("Program prima tacno 1 argument sa komandne linije...\n");
        return -1;
    }

    if (!(input = fopen(argv[1], "r"))) {
        printf("Ulazna datoteka nije pronadjena...\n");
        return -1;
    }

    double max_x, max_y, max_r, max_area = -1;

    for (double x, y, r; fscanf(input, "(%lf,%lf,%lf)\n", &x, &y, &r) == 3; ) {
        double area = PI * r * r;

        if (max_area < area) {
            max_x = x;
            max_y = y;
            max_r = r;
            max_area = area;
        }
    }

    printf("Najvecu povrsinu (P=%.3lf) ima krug:\n", max_area);
    printf("(%.3lf,%.3lf,%.3lf)\n", max_x, max_y, max_r);

    fclose(input);

    return 0;
}
