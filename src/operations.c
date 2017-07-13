#include <stdio.h>
#include <stdlib.h>

#include "../include/cmat.h"

double cmat_min(MATRIX* m){
	int i, j, min = cmat_get(m, 0, 0);

	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++){
			if(min > cmat_get(m, i, j))
				min = cmat_get(m, i, j);
		}
	}
	return min;
}

double cmat_max(MATRIX* m){
	int i, j, max = cmat_get(m, 0, 0);

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