MATRIX* cmat_malloc(int rows, int cols){
    MATRIX *m = (MATRIX*) malloc(sizeof(MATRIX));
    m->rows = rows;
    m->cols = cols;
    m->data = (double*) malloc(sizeof(double[rows][cols]));
    return m;
}

void cmat_free(MATRIX* m){
    free(m->data);
    free(m);
}

int cmat_set(MATRIX* m, int row, int col, double data){
    if(row < m->rows && col < m->cols){
        m->data[col + (row * m->cols)] = data;
        return 0;
    }
    return -1;
}

double cmat_get(MATRIX* m, int row, int col){
	if(row < m->rows && col < m->cols)
		return m->data[col + (row * m->cols)];
	else
		return 0;
}