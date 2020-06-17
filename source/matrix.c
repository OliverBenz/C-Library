#include <stdlib.h>
#include <stdio.h>

typedef struct matrix{
    size_t rows;
    size_t cols;
    int **matrix;
} matrix;

matrix *allocate_matrix(size_t rows, size_t cols) {
    matrix *mat;

    mat = (matrix*)malloc(sizeof(matrix));

    mat->matrix = (int**)malloc(rows * sizeof(int*));

    for(size_t i = 0; i < rows; i++)
        mat->matrix[i] = (int*)malloc(cols * sizeof(int));

    mat->rows = rows;
    mat->cols = cols;

    return mat;
}

void free_matrix(matrix *m) {
    if(m == NULL)
        return;
    if(m->matrix == NULL){
        free(m);
        return;
    }

    for(size_t i = 0; i < m->rows; i++)
        free(m->matrix[i]);
    free(m->matrix);
    free(m);
}

matrix *init_matrix_rand(size_t rows, size_t cols, int r) {
    matrix *mat = allocate_matrix(rows, cols);

    for(size_t i = 0; i < mat->rows; i++)
        for(size_t j = 0; j < mat->cols; j++)
            mat->matrix[i][j] = (rand() % r) + 1;
    
    return mat;
}

matrix *init_matrix_identity(size_t rows, size_t cols) {
    if(rows != cols)
        return NULL;

    matrix *mat = allocate_matrix(rows, cols);
    
    for(size_t i = 0; i < mat->cols; i++)
        for(size_t j = 0; j < mat->rows; j++)
            mat->matrix[i][j] = (i == j ? 1 : 0);

    return mat;
}

void print_matrix(matrix *const matrix) {
    for(size_t i = 0; i < matrix->rows; i++){
        for(size_t j = 0; j < matrix->cols; j++)
            printf("%4d", matrix->matrix[i][j]);
        printf("\n");
    }
}

matrix *multiply_matrix(matrix *const a, matrix *const b) {
    if(a->cols != b->rows)
        return NULL;

    matrix *res = allocate_matrix(a->rows, b->cols);

    for(size_t res_i = 0; res_i < res->rows; res_i++){
        for(size_t res_j = 0; res_j < res->cols; res_j++){
            res->matrix[res_i][res_j] = 0;

            for(size_t r = 0; r < a->cols; r++)
                res->matrix[res_i][res_j] += a->matrix[res_i][r] * b->matrix[r][res_j];
        }
    }

    return res;
}