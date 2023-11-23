#include <stdio.h>

int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    if (!f1 || !f2) {
        printf("Error opening files!\n");
        return -1;
    }

    int equal_chars = 0;
    while (1) {
        int c1 = fgetc(f1);
        int c2 = fgetc(f2);

        // Skip newline characters
        while (c1 == '\n') c1 = fgetc(f1);
        while (c2 == '\n') c2 = fgetc(f2);

        if (c1 == EOF || c2 == EOF)
            break;

        if (c1 == c2)
            equal_chars++;
        else
            break;
    }

    fclose(f1);
    fclose(f2);

    return equal_chars;
}

int main() {
    const char *file1 = "ValorReal.txt";
    const char *file2 = "ValorPthreads.txt";
    int equal_chars = compare_files(file1, file2);
    if (equal_chars >= 0) {
        printf("The first %d characters are sequentially equal.\n", equal_chars);
    }
    return 0;
}
