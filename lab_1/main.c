#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checks.h"

void action(int key, FILE *input_file, char **str, int *len_str);

int cmp(const void *a, const void *b){
    return strcmp(*(char**) a, *(char**) b);
}

int cmp_reverse(const void *a, const void *b){
    return (strcmp(*(char**) a, *(char**) b) * (-1));
}

int main(int argc, char **argv){
    FILE *input_file;

    if (argc != 2){
        printf("%s", "Error: no input file!\n");
        return ERROR;
    }

    input_file = fopen(argv[1], "r");
    if (!input_file){
        printf("%s", "Error: file not exist!\n");
        return ERROR;
    }

    if(getc(input_file) == EOF){
        printf("%s", "Error: file is empty!\n");
        fclose(input_file);
        return ERROR;
    }

    int len_str = 0, key_sort;
    char **str = (char **) malloc(sizeof(char*) * MAX_LEN_STR);
    
    if (!str){
        fclose(input_file);
        return CANT_ALLOCATE_MEMORY;
    }

    about();
    fseek(input_file, -1, 1);
    key_sort = input_key(0, 1);

    switch(key_sort){
    case 0:
        action(key_sort, input_file, str, &len_str);
        break;
    case 1:
        action(key_sort, input_file, str, &len_str);
        break;
    }

    free(str);
    fclose(input_file);

    return 0;
}

void action(int key, FILE *input_file, char **str, int *len_str){
    int key_error;

    while(!feof(input_file)){
        key_error = read_string(input_file, str, len_str);
        if (key_error == 0){
            if(key == 0) 
                qsort(str, *len_str, sizeof(char *), cmp);
            else if(key == 1)
                qsort(str, *len_str, sizeof(char *), cmp_reverse);
            
            print_string(stdout, str, *len_str);
            free_mas(str, *len_str);
        }
        else if(key_error == ERROR_LEN_STR){
            printf("%s", "Error: string is overflow!\n");
            free_mas(str, *len_str);
            break;
        }
        else if(key_error == ERROR_LEN_WORD){
            printf("%s", "Error: word is overflow!\n");
            free_mas(str, *len_str);
            break;
        }
        else if(key_error == ERROR_SYMBOL){
            printf("%s", "Error: in file incorrect symbol!\n");
            free_mas(str, *len_str);
            break;
        }
        else if(key_error == CANT_ALLOCATE_MEMORY){
            printf("%s", "Error: Can`t allocate memory!\n");
            free_mas(str, *len_str);
            break;
        }
    }
}