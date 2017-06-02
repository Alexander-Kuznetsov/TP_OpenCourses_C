#ifndef BTREE_H
#define BTREE_H

#define ERROR_OUT_FILE -4
#define MEMORY_NO_ALLOCATED -5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Btree Btree;

Btree *create_tree();
int add_in_tree(Btree *tree, char *str);
int print_reverse_sort_tree(FILE *out, Btree *tree);
void printInOrder(FILE *out, Btree *tree);
void free_tree(Btree *tree);

//Work with DOT
void export_to_dot(FILE *f, Btree *tree);

#endif // BTREE_H
