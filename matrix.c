#include <stdio.h>

#include "matrix.h"

#include "init.c"

#include "arithmetic.c"

#include "special_metrices.c"

#include "operations.c"

#include "views.c"

int main(){
	MATRIX* m = cmat_ones(4, 4);
    cmat_pretty_display(cmat_multiply_const(cmat_add(m, cmat_lower_trig(4)), 3));
	cmat_free(m);
	return 0;
}
