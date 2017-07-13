#ifndef CMAT_H
#define CMAT_H

#ifdef __cplusplus
extern "C" {
#endif

enum {
    CMAT_FAIL, CMAT_SUCCESS, CMAT_DIMENSION_MISMATCHED
};

struct matrix {
    double *data; /**< Array where data is stored */
    int rows, /**< Number of rows in the matrix */
    	cols; /**< Number of columns in the matrix */
};

typedef struct matrix MATRIX;

/** 
 * @brief Allocates memory for a matrix
 *
 * Matrices allocated with this method should be freed with
 * cmat_free().
 *
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 *
 * @return Pointer to the allocated matrix
 */
MATRIX *cmat_malloc(int rows, int cols);

/** 
 * @brief Allocates memory for a matrix with same dimensions as `m`
 *
 * Matrices allocated with this method should be freed with
 * cmat_free().
 *
 * @param m pointer to the matrix
 *
 * @return Pointer to the allocated matrix
 */
MATRIX *cmat_malloc_shape(MATRIX *m);


/** 
 * @brief Creates a matrix from file
 *
 * It scans the `file` for `rows`x`cols` matrix, creates
 * the matrix and returns the pointer to it.
 *
 * Each element must be saperated by comma and each row must]
 * be saperated by a new line in the `file`.
 *
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @param file Name of the input file
 *
 * @return Pointer to the allocated matrix
 */
MATRIX *cmat_from_file(int rows, int cols, const char *file);

void cmat_free(MATRIX *);

int cmat_set(MATRIX *, int, int, double);

double cmat_get(MATRIX *, int, int);

// Special matrices
MATRIX *cmat_zeros(int, int);

MATRIX *cmat_ones(int, int);

MATRIX *cmat_n(int, int);

MATRIX *cmat_rand(int, int);

MATRIX *cmat_identity(int);

MATRIX *cmat_upper_trig(int);

MATRIX *cmat_lower_trig(int);

// Arithmetic
int cmat_add_const(MATRIX *, double, MATRIX *);

int cmat_multiply_const(MATRIX *, double, MATRIX *);

int cmat_add(MATRIX *, MATRIX *, MATRIX *);

int cmat_add_to_rows(MATRIX *, MATRIX *, MATRIX *);

int cmat_subtract(MATRIX *, MATRIX *, MATRIX *);

int cmat_divide_each(MATRIX *, MATRIX *, MATRIX *);

int cmat_multiply_each(MATRIX *, MATRIX *, MATRIX *);

int cmat_multiply(MATRIX *, MATRIX *, MATRIX *);

// Operations
int cmat_transpose(MATRIX *, MATRIX *);

int cmat_normalize(MATRIX *, MATRIX *);

MATRIX *cmat_sum_x(MATRIX *);

MATRIX *cmat_sum_y(MATRIX *);

MATRIX *cmat_submatrix(MATRIX *, int, int, int, int);

// Views
void cmat_display(MATRIX *);

// Utils
void cmat_abort(char *);

void cmat_for_each(MATRIX *, double (*)(double));

void cmat_for_each_row(MATRIX *, void (*)(MATRIX *, int));

int cmat_has_same_dimensions(MATRIX *, MATRIX *);

int cmat_to_file(MATRIX *, const char *);

#ifdef __cplusplus
}
#endif

#endif
