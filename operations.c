#include <stdio.h>
#include <stdlib.h>

#include "cmat.h"

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

MATRIX* cmat_transpose(MATRIX* m){
	int i, j;
	MATRIX* transpose = cmat_malloc(m->cols, m->rows);
	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++)
			cmat_set(transpose, j, i, cmat_get(m, i, j));
	}
	return transpose;
}

MATRIX* cmat_normalize(MATRIX* m){ 
	int i, j;
	double min = 0, max = 0;
	MATRIX* normalized = cmat_malloc(m->rows, m->cols);
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
			cmat_set(normalized, i, j, (cmat_get(m, i, j) - min) / (max - min));
	}
	return normalized;
}

MATRIX* cmat_combine_x(MATRIX* m, MATRIX* n){ return NULL; }

MATRIX* cmat_combine_y(MATRIX* m, MATRIX* n){ return NULL; }
