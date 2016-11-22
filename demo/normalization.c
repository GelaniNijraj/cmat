#include <stdio.h>
#include <cmat.h>

int main(){
	int i, j;
	MATRIX* m = cmat_malloc(3, 3);
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cmat_set(m, i, j, j + (i * 3));
		}
	}
	m = cmat_normalize(m);
	cmat_display(m);
	return 0;
}