#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "btree.h"
#include "functions.h"

int main(int argc, char* argv[]){
    FILE *input_file;

    if (argc != 3){
        printf("%s", "Error: no input or out file!");
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

    Btree *tree = create_tree();
    if (tree == NULL){
        printf("%s", "ERROR: memory not allocated!");
        fclose(input_file);
        free_tree(tree);
        return MEMORY_NO_ALLOCATED;
    }

    //read
    int key = sread_from_file(input_file, tree);
    if (key == ERROR_LEN_WORD){
        printf("ERROR: size word is overflow!");
        fclose(input_file);
        free_tree(tree);
        return ERROR_LEN_WORD;
    }
    if (key == ERROR_FILE){
        printf("ERROR: file crush!");
        fclose(input_file);
        free_tree(tree);
        return ERROR_FILE;
    }
    if (key == MEMORY_NO_ALLOCATED){
        printf("ERROR: memory not allocated!");
        fclose(input_file);
        free_tree(tree);
        return MEMORY_NO_ALLOCATED;
    }

    //FILE *f_dot = fopen("DOT.gv", "w");
    //export_to_dot(f_dot, tree);

    FILE *out_file = fopen(argv[2], "w");
    key = print_reverse_sort_tree(out_file, tree);
    if (key == ERROR_OUT_FILE)
    {
        printf("ERROR: it out file!");
        free_tree(tree);
        fclose(input_file);
        fclose(out_file);
        return ERROR_OUT_FILE;
    }

    free_tree(tree);
    fclose(input_file);
    fclose(out_file);
    printf("Programm continue is good!\n");

    return 0;
}
