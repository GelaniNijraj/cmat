#ifndef GL_MATRIX_H
#define GL_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

struct matrix{
	double *data, (*d)[10];
	int rows, cols;
};


typedef struct matrix MATRIX;

MATRIX* cmat_malloc(int, int);

void cmat_free(MATRIX*);

int cmat_set(MATRIX*, int, int, double);

double cmat_get(MATRIX*, int, int);

MATRIX* cmat_zeros(int, int);

MATRIX* cmat_ones(int, int);

MATRIX* cmat_add_const(MATRIX*, double);

MATRIX* cmat_multiply_const(MATRIX*, double);

MATRIX* cmat_add(MATRIX*, MATRIX*);

MATRIX* cmat_subtract(MATRIX*, MATRIX*);

MATRIX* cmat_divide_each(MATRIX*, MATRIX*);

MATRIX* cmat_multiply_each(MATRIX*, MATRIX*);

MATRIX* cmat_multiply(MATRIX*, MATRIX*);


#ifdef __cplusplus
}
#endif

#endif