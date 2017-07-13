#include <stdio.h>
#include <stdlib.h>

#include "../include/cmat.h"

int cmat_add_const(MATRIX* m, double a, MATRIX* result){
	int i, j;

    if(!cmat_has_same_dimensions(m, result))
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) + a);
    }
    return CMAT_SUCCESS;
}

int cmat_multiply_const(MATRIX* m, double a, MATRIX* result){
	int i, j;

    if(!cmat_has_same_dimensions(m, result))
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) * a);
    }
    return CMAT_SUCCESS;
}

int cmat_add(MATRIX* m, MATRIX* n, MATRIX* result){
    int i, j;

    if(!cmat_has_same_dimensions(m, n) || !cmat_has_same_dimensions(m, result))
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) + cmat_get(n, i, j));
    }
    return CMAT_SUCCESS;
}

int cmat_add_to_rows(MATRIX* m, MATRIX* n, MATRIX* result){
    int i, j;

    // N has to be a row matrix with same columns as M
    if(!cmat_has_same_dimensions(m, result) || m->cols != n->cols || n->rows != 1)
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) + cmat_get(n, 0, j));
    }
    return CMAT_SUCCESS;
}

int cmat_subtract(MATRIX* m, MATRIX* n, MATRIX* result){
    int i, j;

    if(!cmat_has_same_dimensions(m, n) || !cmat_has_same_dimensions(m, result))
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) - cmat_get(n, i, j));
    }
    return CMAT_SUCCESS;
}

int cmat_divide_each(MATRIX* m, MATRIX* n, MATRIX* result){
    int i, j;

    if(!cmat_has_same_dimensions(m, n) || !cmat_has_same_dimensions(m, result))
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) / cmat_get(n, i, j));
    }
    return CMAT_SUCCESS;
}

int cmat_multiply_each(MATRIX* m, MATRIX* n, MATRIX* result){
    int i, j;

    if(!cmat_has_same_dimensions(m, n) || !cmat_has_same_dimensions(m, result))
        return CMAT_FAIL;

    for(i = 0; i < m->rows; i++){
        for(j = 0; j < m->cols; j++)
            cmat_set(result, i, j, cmat_get(m, i, j) * cmat_get(n, i, j));
    }
    return CMAT_SUCCESS;
}

int cmat_multiply(MATRIX* m, MATRIX* n, MATRIX* result){
    int i, j, k;
    double tmp;

    if(m->cols != n->rows)
        return CMAT_FAIL;

    // TODO: check if result is of proper dimension

    for(i = 0; i < n->cols; i++){
        for(j = 0; j < m->rows; j++){
            tmp = 0;
            for(k = 0; k < m->cols; k++){
                tmp += cmat_get(m, k, j) * cmat_get(n, i, k);
            }
            cmat_set(result, j, i, tmp);
        }
    }
    return CMAT_SUCCESS;
}


MATRIX* cmat_sum_x(MATRIX* m){
    MATRIX* result = cmat_malloc(m->rows, 1);
    int i, j, t;

    for(i = 0; i < m->rows; i++){
        t = 0;
        for(j = 0; j < m->cols; j++){
            t += cmat_get(m, i, j);
        }
        cmat_set(result, i, 0, t);
    }

    return result;
}

MATRIX* cmat_sum_y(MATRIX* m){
    MATRIX* result = cmat_malloc(1, m->cols);
    int i, j, t;

    for(i = 0; i < m->cols; i++){
        t = 0;
        for(j = 0; j < m->rows; j++){
            t += cmat_get(m, j, i);
        }   
        cmat_set(result, 0, i, t);
    }

    return result;
}