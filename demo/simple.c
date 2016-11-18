#include <cmat.h>

int main(){
	MATRIX* m = cmat_ones(4, 5);
	MATRIX* n = cmat_transpose(m);
	puts("Transposed Matrix : ");
	cmat_display(cmat_add_const(n, 3));
	cmat_free(m);
	cmat_free(n);
	return 0;
}