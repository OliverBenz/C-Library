#include <stdlib.h>
#include <stdio.h>

typedef struct matrix matrix;

matrix *allocate_matrix(size_t rows, size_t cols);
void free_matrix(struct matrix_t *m);

matrix *init_matrix_rand(size_t rows, size_t cols, int r);
matrix *init_matrix_identity(size_t rows, size_t cols);

void print_matrix(matrix *const matrix);
matrix *multiply_matrix(matrix *const a, matrix *const b);
