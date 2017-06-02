#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checks.h"

void about(){
    printf("_______________________Menu_______________________\n");
    printf("0 - Sorting file in lexicographical order\n");
    printf("1 - Sorting file in reverse lexicographical order\n");
    printf("__________________________________________________\n");
}

int input_key(int key1, int key2){
    int res;

    while(1){
        printf(">> ");
        if(scanf("%d", &res) && (res >= key1 && res <= key2)){
            return res;
        }
        else{
            printf("incorrect input, please return input...\n");
            fflush(stdin);
        }
    }
}

void print_string(FILE *f, char **str, int len_str){
    if (len_str != 0){
        for (int i = 0; i < len_str; i++)
            fprintf(f, "%s ", str[i]);
        fprintf(f, "\n");
    }
}

void free_mas(char **str, int len_str){
    for (int i = 0; i < len_str; i++){
        free(str[i]);
        str[i] = NULL;
    }
}

int read_string(FILE *f, char **str, int *len_str){
    char buf[MAX_LEN_WORD + 1] = "";
    char ch, ch_back = ' ';
    int i = 0; 

    *len_str = 0;
    ch = fgetc(f);

    while(ch_back != '\n' && ch_back != EOF){
        if (ch_back != ' '  && (ch == ' ' || ch == '\n' || ch == EOF)){
            if(*len_str == MAX_LEN_STR){
                return ERROR_LEN_STR;
            }

            buf[i] = '\0';
            str[*len_str] = (char*) malloc(sizeof(char)*(strlen(buf) + 1));
            if (!str[*len_str])
                return CANT_ALLOCATE_MEMORY;
            
            strcpy(str[*len_str], buf);
            *len_str+=1;
            i = 0;
        }

        if (ch != ' ' && ch != '\n' && ch != EOF){
            if (i == MAX_LEN_WORD){
                return ERROR_LEN_WORD;
            }
            if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
                buf[i] = ch;
                ++i;
            }
            else{
                return ERROR_SYMBOL;
            }
        }

        ch_back = ch;
        if (ch_back != '\n' && ch_back != EOF)
            ch = fgetc(f);
    }

    return 0;
}

/*void read_string(FILE *f, char **str, int *len_str){
    char buf[1024];
    *len_str = 0;

    while(!feof(f)){
        fscanf(f, "%s", buf);
        str[*len_str] = (char*) malloc(sizeof(char)*strlen(buf));
        strcpy(str[*len_str], buf);
        *len_str+=1;
    }
}*/
