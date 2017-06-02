#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_int(FILE *file);
int type_matrix(FILE *file);
int count_no_zero(Matrix *matrix);

Matrix* create_matrix_from_file(FILE* file){
    int row, col;

    row = get_int(file);
    col = get_int(file);

    if (row < 1 || col < 1)
        return NULL;

    Matrix *matrix = create_matrix(row, col);

    int tmp1 = ftell(file);
    int type = type_matrix(file);
    if (fseek(file, tmp1, SEEK_SET) != 0)
        return NULL;

    int tmp_i = 0, tmp_j = 0, count = 0;
    double val;
    if (type){
        int tmp_count = row*col;

        while(fscanf(file, "%lf", &(val)) == 1){
            matrix->matrix[tmp_i][tmp_j] = val;
            ++tmp_j;
            ++count;
            if (tmp_j == col){
                tmp_j = 0;
                ++tmp_i;
            }
        }
        if(count != tmp_count)
            return NULL;
    }
    else{
        int non_zero = get_int(file);

        while(fscanf(file, "%d%d%lf", &tmp_i, &tmp_j, &val) == 3){
            set_elem(matrix, tmp_i, tmp_j, val);
            if (count_no_zero(matrix) == non_zero)
                break;
        }
        /*for (int i = 0; i < non_zero; i++){
            if(fscanf(file, "%d%d%lf", &i_in, &j_in, &val_in) != 3)
                return NULL;
        }*/
        if (count_no_zero(matrix) != non_zero)
            return NULL;
    }
    return matrix;
}

int count_no_zero(Matrix *matrix){
    int count = 0;
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->col; j++)
            if (matrix->matrix[i][j] != 0) ++count;
    return count;
}

int type_matrix(FILE *file){
    int buf = 0, count = 0;
    char symbol = fgetc(file);

    while(symbol != '\n' && symbol != EOF){
        if(isdigit(symbol) != 0){
            if (buf == 0) ++count;
            if (count >= 2) return 1;
            buf = 1;
        }
        else if (isspace(symbol) && buf != 0){
            buf = 0;
            ++count;
        }
        symbol = fgetc(file);
    }
    return 0;
}

Matrix* create_matrix(int row, int col){
    Matrix *matrix = (Matrix*) malloc(sizeof(Matrix));
    if (!matrix)
        return NULL;

    matrix->row = row;
    matrix->col = col;

    matrix->matrix = (double**) malloc(sizeof(double*) * row);
    if (!(matrix->matrix))
        return NULL;
    for (int i = 0; i < row; i++){
        matrix->matrix[i] = (double*) (calloc(col, sizeof(double)));
        if (!matrix->matrix[i])
            return NULL;
    }

    return matrix;
}

int get_rows(Matrix* matrix){
    if (!matrix) return ERROR_GET_ROWS;
    return (matrix->row);
}

int get_cols(Matrix* matrix){
    if (!matrix) return ERROR_GET_COLS;
    return (matrix->col);
}

double get_elem(Matrix* matrix, int row, int col){
    int rows = get_rows(matrix);
    int cols = get_cols(matrix);

    if ((row >= rows || row < 0) || (col >= cols || col < 0))
        return COLS_OVERFLOW;
    return (matrix->matrix[row][col]);
}

void set_elem(Matrix* matrix, int row, int col, double val){
    int rows = get_rows(matrix);
    int cols = get_cols(matrix);

    if ((row >= rows || row < 0) || (col >= cols || col < 0))
        return;
    matrix->matrix[row][col] = val;
}

int get_int(FILE *file){
    int buf = 0;
    char symbol = fgetc(file);

    while(symbol != '\n' && symbol != EOF){
        if(isdigit(symbol) != 0)
            buf = buf * 10 + atoi(&symbol);
        else if (buf != 0 && isspace(symbol))
            return -1;
        symbol = fgetc(file);
    }

    if (!buf)
        return -1;
    else
        return buf;
}

void free_matrix(Matrix* matrix){
    if (get_rows(matrix) == ERROR_GET_ROWS)
        return;
    for (int i = 0; i < matrix->row; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
    matrix = NULL;
}
