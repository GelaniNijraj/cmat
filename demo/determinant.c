#include <stdio.h>
#include <cmat.h>

int main() {
    MATRIX *m = cmat_malloc(3, 3);
    cmat_set(m, 0, 0, 1);
    cmat_set(m, 0, 1, 5);
    cmat_set(m, 0, 2, 0);
    cmat_set(m, 1, 0, 2);
    cmat_set(m, 1, 1, 1);
    cmat_set(m, 1, 2, 0);
    cmat_set(m, 2, 0, 1);
    cmat_set(m, 2, 1, 0);
    cmat_set(m, 2, 2, 3);
    double result = 0;
    cmat_determinant(m, &result);
    printf("%f", result);
}