#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define FILE_EMPTY -1
#define FILE_NOT_EXIST -2
#define NOT_INPUT_FILE -3
#define ERROR_MATRIX -4
#define MEMORY_NO_ALLOCATED -5
#define ERROR_INPUT_STREAM -6
#define BUF_OVERFLOW -7

void print_matrix(Matrix *matrix, int rows, int cols);
double search_max(double *mas, int len);
double max_norm_matrix(Matrix *matrix, int rows, int cols);

int main(int argc, char* argv[]){   
    FILE *input_file;

    if (argc != 2){
        printf("%s", "Error: no input file!");
        return NOT_INPUT_FILE;
    }

    input_file = fopen(argv[1], "r");
    if (!input_file){
        printf("%s", "Error: file not exist!");
        return FILE_NOT_EXIST;
    }

    if (fseek(input_file, 0, SEEK_END) != 0){
        printf("%s", "ERROR: buffer is overflow!");
        fclose(input_file);
        return BUF_OVERFLOW;
    }

    if(ftell(input_file) <= 0){
        printf("%s", "Error: file is empty!");
        fclose(input_file);
        return FILE_EMPTY;
    }
    rewind(input_file);

    Matrix *matrix = create_matrix_from_file(input_file);
    if (matrix == NULL){
        printf("%s", "ERROR: a few problems in input file!");
        free_matrix(matrix);
        fclose(input_file);
        return ERROR_MATRIX;
    }

    if (ferror(input_file) != 0){
        printf("%s", "ERROR in input stream!");
        free_matrix(matrix);
        fclose(input_file);
        return ERROR_MATRIX;
    }

    int rows = get_rows(matrix);
    int cols = get_cols(matrix);
    double max_norm = max_norm_matrix(matrix, rows, cols);

    if (max_norm == MEMORY_NO_ALLOCATED){
       printf("%s", "ERROR: MEMORY NOT ALLOCATED");
       free_matrix(matrix);
       fclose(input_file);
       return MEMORY_NO_ALLOCATED;
    }

    print_matrix(matrix, rows, cols);
    printf("\nMaximum Norm Matrix = %.3lf\n", max_norm);

    free_matrix(matrix);
    fclose(input_file);

	return 0;
}

double max_norm_matrix(Matrix *matrix, int rows, int cols){
    double max = 0;
    double *m = (double*) calloc(rows, sizeof(double));

    if(!m)  return MEMORY_NO_ALLOCATED;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m[i] += fabs(get_elem(matrix, i, j));

    max = search_max(m, rows);
    free(m);

    return max;
}

double search_max(double *mas, int len){
    double max = mas[0];
    for (int i = 1; i < len; i++)
        if (max < mas[i]) max = mas[i];
    return max;
}

void print_matrix(Matrix *matrix, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            printf("%.3lf ", get_elem(matrix, i, j));
        printf("\n");
    }
}
