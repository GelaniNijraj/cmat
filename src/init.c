#include <stdio.h>
#include <stdlib.h>

#include "../include/cmat.h"

MATRIX* cmat_malloc(int rows, int cols){
    MATRIX *m = (MATRIX*) malloc(sizeof(MATRIX));
    m->rows = rows;
    m->cols = cols;
    m->data = (double*) malloc(sizeof(double[rows][cols]));
    return m;
}

MATRIX* cmat_malloc_shape(MATRIX* m){
    return cmat_malloc(m->rows, m->cols);
}

MATRIX* cmat_from_file(int rows, int cols, const char* file){
    int i, j;
    FILE* fp;
    double t;
    MATRIX *m = cmat_malloc(rows, cols);

    fp = fopen(file, "r");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            fscanf(fp, "%lf,", &t);
            cmat_set(m, i, j, t);
        }
    }
    fclose(fp);
    
    return m;
}

void cmat_free(MATRIX* m){
    free(m->data);
    free(m);
}

int cmat_set(MATRIX* m, int row, int col, double data){
    if(row < m->rows && col < m->cols){
        m->data[col + (row * m->cols)] = data;
        return CMAT_SUCCESS;
    }
    return CMAT_FAIL;
}

double cmat_get(MATRIX* m, int row, int col){
	if(row < m->rows && col < m->cols)
		return m->data[col + (row * m->cols)];
	else
		return 0;
}
