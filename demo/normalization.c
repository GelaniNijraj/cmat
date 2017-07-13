#include <stdio.h>
#include <cmat.h>

int main(){
	int i, j;
	MATRIX* m = cmat_n(3, 3);

	printf("Before normalization : \n");
	cmat_display(m);

	// Normalize and store the result in same matrix
	cmat_normalize(m, m);
	printf("After normalization : \n");
	cmat_display(m);
	return 0;
}