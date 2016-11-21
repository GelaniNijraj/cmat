# cmat
A small C library for matrix manipulation.


## Usage

To install, run following commands from terminal :

```
make
make install
```

Use `LIB_PATH` and `INCLUDE_PATH` to install the library in specific directory. By default, library is installed at `/usr/local/lib` and header file is stored at `/usr/local/include`.

At compilation, use `-lcmat` flag. i.e.

```
gcc sample.c -lcmat
```

After installation, include `cmat` and use any of the following functions.

### Basic Functions
* ```MATRIX* cmat_malloc(int r, int c);```

	Returns a pointer to MATRIX structure with `r` rows and `c` columns.


* ```void cmat_free(MATRIX* m);```
	
	Frees the memory allocated to the matrix pointed my `m`.
    
    
* ```int cmat_set(MATRIX* m, int row, int col, double data);```
	
    Sets the value of (`row`, `col`) to `data` in the matrix pointed by `m`. Returns 0 on success, -1 if `row` or `col` is out of bounds.
    
    
* ```double cmat_get(MATRIX* m, int row, int col);```
	
    Returns the value stored at (`row`, `col`) in matrix `m`; 0 if either `row` or `col` is out of bounds.
    
### Arithmetic Functions
* ```MATRIX* cmat_add_const(MATRIX* m, double a);```
	
    Adds constant `a` to the each element of matrix `m` and returns the new matrix.
    
    
* ```MATRIX* cmat_multiply_const(MATRIX* m, double a);```

	Multiplies each element of matrix `m` with `a` and returns the new matrix.
    
    
* ```MATRIX* cmat_add(MATRIX* m, MATRIX* n);```

	Adds two matrices `m` and `n` and returns the new matrix. NULL if both matrices do not have same number of rows and columns.


* ```MATRIX* cmat_subtract(MATRIX* m, MATRIX* n);```

	Subtracts two matrices `m` and `n` and returns the new matrix. NULL if both matrices do not have same number of rows and columns.
 
 
* ```MATRIX* cmat_divide_each(MATRIX* m, MATRIX* n);```

	Divides each element of `m` with respective element of `n` and returns the new matrix. NULL if both matrices do not have same number of rows and columns.


* ```MATRIX* cmat_multiply_each(MATRIX* m, MATRIX* n);```

	Multiplies each element of `m` with respective element of `n` and returns the new matrix. NULL if both matrices do not have same number of rows and columns.
    
    
* ```MATRIX* cmat_multiply(MATRIX* m, MATRIX* n);```

	Performs matrix manipulation on matrices `m` and `n` and returns the answer matrix.
    
    
### Special Matrices

* ```MATRIX* cmat_zeros(int r, int c);```

	Returns a matrix of dimension `r`x`c`, filled with zeros.
    
    
* ```MATRIX* cmat_ones(int r, int c);```

	Returns a matrix of dimension `r`x`c`, filled with ones.
    
* ```MATRIX* cmat_identity(int dim);```

	Returns an identity matrix of dimension `dim`x`dim`.
  
  
* ```MATRIX* cmat_upper_trig(int dim);```

	Returns an upper triangular matrix of dimension `dim`x`dim`.
    
    
* ```MATRIX* cmat_lower_trig(int dim);```

	Returns an lower triangular matrix of dimension `dim`x`dim`.
    
    
### Other Operations

* ```double cmat_min(MATRIX* m);```

	Returns the smallest element in the matrix `m`.
    
    
* ```double cmat_max(MATRIX* m);```

	Returns the largest element in the matrix `m`.
    
    
* ```MATRIX* cmat_transpose(MATRIX* m);```

	Returns the transpose matrix of the matrix `m`.
    
    
* ```MATRIX* cmat_normalize(MATRIX* m);``` (TODO)

	Returns the normalized version of the matrix `m`.


## TODO

- [x] Transpose
- [ ] Normalization
- [ ] Determinant and rank of the matrix
- [ ] Inverse of a matrix
- [ ] Gaussian Reduction
- [ ] Reshaping and merging


## License

Copyright (C) 2016  Nijraj Gelani (MIT)