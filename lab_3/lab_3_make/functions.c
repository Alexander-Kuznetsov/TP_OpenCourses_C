#include <stdlib.h>
#include "functions.h"

int sread_from_file(FILE *f, Btree *tree){
    char buf[MAX_LEN_WORD + 1] = "";
    char ch, *str;
    int i = 0;
    char ch_back = ' ';

    ch = fgetc(f);
    while(ch_back != EOF){
        if (ferror(f) != 0)
            return ERROR_FILE;

        if ((ch_back != ' ' && ch_back != '\n')  && (ch == ' ' || ch == '\n' || ch == EOF)){
            buf[i] = '\0';
            str = (char*) malloc(sizeof(char)*(strlen(buf) + 1));
            if (!str)
                return MEMORY_NO_ALLOCATED;
            strcpy(str, buf);
            if (add_in_tree(tree, str) == MEMORY_NO_ALLOCATED){
                free(str);
                return MEMORY_NO_ALLOCATED;
            }
            i = 0;
            free(str);
        }

        if (ch != ' ' && ch != '\n' && ch != EOF){
            if (i == MAX_LEN_WORD){
                return ERROR_LEN_WORD;
            }
            buf[i] = ch;
            ++i;
        }

        ch_back = ch;
        if (ch_back != EOF)
            ch = fgetc(f);
    }
    return 0;
}
