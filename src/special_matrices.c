#include <stdio.h>
#include <stdlib.h>

#include "../include/cmat.h"

MATRIX* cmat_zeros(int rows, int cols){
    MATRIX *m = (MATRIX*) malloc(sizeof(MATRIX));
    m->rows = rows;
    m->cols = cols;
    m->data = (double*) calloc(rows*cols, sizeof(double));
    return m;
}

MATRIX* cmat_ones(int rows, int cols){
    int i, j;
    MATRIX *m = cmat_malloc(rows, cols);

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            cmat_set(m, i, j, 1.0);
        }
    }
    return m;
}

MATRIX* cmat_identity(int dim){
    int i;
    MATRIX* identity = cmat_zeros(dim, dim);

    for(i = 0; i < dim; i++){
        cmat_set(identity, i, i, 1);
    }
    return identity;
}

MATRIX* cmat_rand(int rows, int cols){
    int i, j;
    MATRIX* m = cmat_malloc(rows, cols);

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){

        }
    }
    return m;
}

MATRIX* cmat_upper_trig(int dim){
    int i, j;
    MATRIX* result = cmat_zeros(dim, dim);

    for(i = 0; i < dim; i++){
        for(j = i; j < dim; j++){
            cmat_set(result, i, j, 1);
        }
    }
    return result;
}

MATRIX* cmat_lower_trig(int dim){
    int i, j;
    MATRIX* result = cmat_zeros(dim, dim);

    for(i = 0; i < dim; i++){
        for(j = 0; j <= i; j++){
            cmat_set(result, i, j, 1);
        }
    }
    return result;
}

MATRIX* cmat_n(int rows, int cols){
    int i, j;
    MATRIX* result = cmat_malloc(rows, cols);

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            cmat_set(result, i, j, j + (i * 3));
        }
    }
    return result;
}
