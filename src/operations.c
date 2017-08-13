#include <stdio.h>
#include <stdlib.h>

#include "../include/cmat.h"

double cmat_min(MATRIX* m){
	int i, j;
    double min = cmat_get(m, 0, 0);

	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++){
			if(min > cmat_get(m, i, j))
				min = cmat_get(m, i, j);
		}
	}
	return min;
}

double cmat_max(MATRIX* m){
	int i, j;
    double max = cmat_get(m, 0, 0);

	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++){
			if(max < cmat_get(m, i, j))
				max = cmat_get(m, i, j);
		}
	}
	return max;
}

int cmat_transpose(MATRIX* m, MATRIX* result){
	int i, j;

	if(m->cols != result->rows || m->rows != result->cols)
		return CMAT_FAIL;

	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++)
			cmat_set(result, j, i, cmat_get(m, i, j));
	}
	return CMAT_SUCCESS;
}

int cmat_normalize(MATRIX* m, MATRIX* result){ 
	int i, j;
	double min = 0, max = 0;

	if(!cmat_has_same_dimensions(m, result))
		return CMAT_FAIL;

	// Finding the minimum and maximum elements
	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++){
			double tmp = cmat_get(m, i, j);
			if(tmp < min)
				min = tmp;
			if(tmp > max)
				max = tmp;
		}
	}
	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++)
			cmat_set(result, i, j, (cmat_get(m, i, j) - min) / (max - min));
	}
	return CMAT_SUCCESS;
}

int cmat_partial_pivotize(MATRIX *m, MATRIX *identity) {
    MATRIX *temp = cmat_malloc_shape(m);
    int parity = 0;
	for (int i = 0; i < m->rows; i++) {
		double max = cmat_get(m, i, i);
		int row = i;
		for (int j = i; j < m->rows; j++) {
			if (cmat_get(m, j, i) > max) {
				max = cmat_get(m, j, i);
				row = j;
			}
		}

		if (i != row) {
            parity++;
			cmat_row_exchange(identity, i, row);
            cmat_multiply(m, identity, temp);
            m = temp;
		}
	}

    return parity;
}

int cmat_lu_decompose(MATRIX *m, MATRIX *l, MATRIX *u) {
	MATRIX *identity = cmat_identity(m->rows), *pivot_m = cmat_malloc_shape(m);
	int parity = cmat_partial_pivotize(m, identity);
	cmat_multiply(m, identity, pivot_m);
	for (int j = 0; j < m->rows; j++) {
		for (int i = 0; i <= j; i++) {
			double sum = 0;
			for (int k = 0; k < i; k++) {
				sum += cmat_get(u, k, j) * cmat_get(l, i, k);
			}
			cmat_set(u, i, j, cmat_get(pivot_m, i, j) - sum);
		}
		for (int i = j; i < m->rows; i++) {
			double sum = 0;
			for (int k = 0; k < j; k++) {
				sum += cmat_get(u, k, j) * cmat_get(l, i, k);
			}
			cmat_set(l, i, j, (cmat_get(pivot_m, i, j) - sum) / cmat_get(u, j, j));
		}
	}

    return parity;
}

double cmat_determinant_triangular(MATRIX *m) {
	double determinant = 1;
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			if (i == j) determinant *= cmat_get(m, i, j);
		}
	}

	return determinant;
}

int cmat_determinant(MATRIX *m, double *result) {
    int parity = 0;
	if (m->rows != m->cols) {
		return CMAT_FAIL;
	}

	MATRIX *l = cmat_malloc_shape(m), *u = cmat_malloc_shape(m);
	parity = cmat_lu_decompose(m, l, u);
	*result = cmat_determinant_triangular(l) * cmat_determinant_triangular(u) * (parity % 2 == 1 ? -1 : 1);
    cmat_free(l);
    cmat_free(u);
	return CMAT_SUCCESS;
}

MATRIX* cmat_submatrix(MATRIX* m, int start_row, int start_col, int end_row, int end_col){
	int i, j;
	MATRIX* result = cmat_malloc(end_row - start_row + 1, end_col - start_col + 1);
	for(i = 0; i <= end_row - start_row; i++){
		for(j = 0; j <= end_col - start_col; j++){
			cmat_set(result, i, j, cmat_get(m, start_row + i, start_col + j));
		}
	}

	return result;
}

MATRIX* cmat_join_x(MATRIX* m, MATRIX* n){ 
	int i, j;
	MATRIX* result = cmat_malloc(m->rows, m->cols + n->cols);

	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++){
			cmat_set(result, i, j, cmat_get(m, i, j));
		}
	}

	return NULL;
}

MATRIX* cmat_join_y(MATRIX* m, MATRIX* n){ return NULL; }