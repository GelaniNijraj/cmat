#include <stdio.h>

#include "../include/cmat.h"

void cmat_display(MATRIX* m){
	int i, j;
	for(i = 0; i < m->rows; i++){
		for(j = 0; j < m->cols; j++){
			printf(" %.2f ", cmat_get(m, i, j));
		}
		printf("\n");
	}
}