#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

#define ROWS_OVERFLOW -1
#define COLS_OVERFLOW -2
#define ERROR_GET_ROWS -3
#define ERROR_GET_COLS -4

typedef struct Matrix {
    double **matrix;
    int row, col;
} Matrix;

Matrix* create_matrix_from_file(FILE* file);
Matrix* create_matrix(int row, int col);
void free_matrix(Matrix* matrix);
double get_elem(Matrix* matrix, int row, int col);
void set_elem(Matrix* matrix, int row, int col, double val);
int get_rows(Matrix* matrix);
int get_cols(Matrix* matrix);

#endif //_MATRIX_H_
