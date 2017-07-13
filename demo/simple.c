#include <stdio.h>
#include <math.h>
#include <cmat.h>

void do_this(MATRIX* m, int row){
	int i;
	for(i = 0; i < m->cols; i++)
		cmat_set(m, 0, i, row);
}


int main(){
	MATRIX *tra_data, *tra_labels, *tra_attributes,
		   *tes_data, *tes_labels, *tes_attributes, *m, *n;

	tra_data = cmat_from_file(3823, 65, "training_set");
	tra_attributes = cmat_submatrix(tra_data, 0, 0, 3822, 63);
	tra_labels = cmat_submatrix(tra_data, 0, 64, 3822, 64);


	m = cmat_from_file(5, 5, "matrix.txt");

	cmat_display(m);
	// printf("\n\n");
	// // n = cmat_sum_y(m);
	// cmat_display(n);


	// tes_data = cmat_from_file(3823, 65, "testining_set");
	// tes_attributes = cmat_submatrix(data, 0, 0, 3822, 63);
	// tes_labels = cmat_submatrix(data, 0, 64, 3822, 64);


	// Free the stuff
	return 0;
}