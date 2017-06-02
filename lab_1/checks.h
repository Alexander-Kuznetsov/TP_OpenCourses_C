#ifndef CHECKS_H
#define CHECKS_H

#define MAX_LEN_STR 20
#define MAX_LEN_WORD 20
#define ERROR_LEN_WORD -1
#define ERROR_LEN_STR -2
#define ERROR_SYMBOL -3
#define CANT_ALLOCATE_MEMORY -4
#define ERROR -5

void about();
int input_key(int key1, int key2);
void print_string(FILE *f, char **str, int len_str);
void free_mas(char **str, int len_str);
int read_string(FILE *f, char **str, int *len_str);

#endif // CHECKS_H
