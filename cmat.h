#ifndef CMAT_H
#define CMAT_H

#ifdef __cplusplus
extern "C" {
#endif

struct matrix{
	double *data;
	int rows, cols;
};


typedef struct matrix MATRIX;

MATRIX* cmat_malloc(int, int);

void cmat_free(MATRIX*);

int cmat_set(MATRIX*, int, int, double);

double cmat_get(MATRIX*, int, int);

void cmat_display(MATRIX*);

MATRIX* cmat_zeros(int, int);

MATRIX* cmat_ones(int, int);

MATRIX* cmat_add_const(MATRIX*, double);

MATRIX* cmat_multiply_const(MATRIX*, double);

MATRIX* cmat_add(MATRIX*, MATRIX*);

MATRIX* cmat_subtract(MATRIX*, MATRIX*);

MATRIX* cmat_divide_each(MATRIX*, MATRIX*);

MATRIX* cmat_multiply_each(MATRIX*, MATRIX*);

MATRIX* cmat_multiply(MATRIX*, MATRIX*);

MATRIX* cmat_transpose(MATRIX*);

MATRIX* cmat_normalize(MATRIX*);


#ifdef __cplusplus
}
#endif

#endif
