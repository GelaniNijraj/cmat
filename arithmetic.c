#include <stdio.h>
#include <stdlib.h>

#include "cmat.h"

MATRIX* cmat_add_const(MATRIX* m, double a){
	int i, j;
    MATRIX* result = cmat_malloc(m->rows, m->cols);
    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) + a);
    }
	return result;
}

MATRIX* cmat_multiply_const(MATRIX* m, double a){
	int i, j;
    MATRIX* result = cmat_malloc(m->rows, m->cols);
    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) * a);
    }
	return result;
}

MATRIX* cmat_add(MATRIX* m, MATRIX* n){
    int i, j;
    MATRIX* result = NULL;
    if(m->rows == n->rows && m->cols == n->cols){
        result = cmat_malloc(m->rows, m->cols);
        for(i = 0; i < m->rows; i++){
            for(j = 0; j < m->cols; j++)
                cmat_set(result, i, j, cmat_get(m, i, j) + cmat_get(n, i, j));
        }
    }
    return result;
}

MATRIX* cmat_subtract(MATRIX* m, MATRIX* n){
    int i, j;
    MATRIX* result = NULL;
    if(m->rows == n->rows && m->cols == n->cols){
        result = cmat_malloc(m->rows, m->cols);
        for(i = 0; i < m->rows; i++){
            for(j = 0; j < m->cols; j++)
                cmat_set(result, i, j, cmat_get(m, i, j) - cmat_get(n, i, j));
        }
    }
    return result;
}

MATRIX* cmat_divide_each(MATRIX* m, MATRIX* n){
    int i, j;
    MATRIX* result = NULL;
    if(m->rows == n->rows && m->cols == n->cols){
        result = cmat_malloc(m->rows, m->cols);
        for(i = 0; i < m->rows; i++){
            for(j = 0; j < m->cols; j++)
                cmat_set(result, i, j, cmat_get(m, i, j) / cmat_get(n, i, j));
        }
    }
    return result;
}

MATRIX* cmat_multiply_each(MATRIX* m, MATRIX* n){
    int i, j;
    MATRIX* result = NULL;
    if(m->rows == n->rows && m->cols == n->cols){
        result = cmat_malloc(m->rows, m->cols);
        for(i = 0; i < m->rows; i++){
            for(j = 0; j < m->cols; j++)
                cmat_set(result, i, j, cmat_get(m, i, j) * cmat_get(n, i, j));
        }
    }
    return result;
}

MATRIX* cmat_multiply(MATRIX* m, MATRIX* n){
    int i, j, k;
    double tmp;
    MATRIX* result;
    if(m->cols != n->rows)
        return NULL;
    result = cmat_malloc(m->rows, n->cols);
    for(i = 0; i < n->cols; i++){
        for(j = 0; j < m->rows; j++){
            tmp = 0;
            for(k = 0; k < m->cols; k++){
                tmp += cmat_get(m, k, j) * cmat_get(n, i, k);
            }
            cmat_set(result, j, i, tmp);
        }
    }
    return result;
}
