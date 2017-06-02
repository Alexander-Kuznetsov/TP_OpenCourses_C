#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include "btree.h"

#define FILE_EMPTY -1
#define FILE_NOT_EXIST -2
#define NOT_INPUT_FILE -3
#define ERROR_READ -4
#define MEMORY_NO_ALLOCATED -5
#define ERROR_INPUT_STREAM -6
#define BUF_OVERFLOW -7
#define MAX_LEN_WORD 100
#define ERROR_LEN_WORD -8
#define ERROR_FILE -9

int sread_from_file(FILE *f, Btree *tree);

#endif // FUNCTIONS_H
