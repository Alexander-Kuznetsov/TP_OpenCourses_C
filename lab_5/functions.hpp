#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "list.hpp"
#include <iostream>
#include <fstream>

#define NOT_INPUT_FILE - 1
#define FILE_NOT_EXIST -2
#define EMPTY_FILE -3
#define MEMORY_ALLOCATED -5

void sort_array(List *lst, int len);
void print_array(List *lst, int len);

int resize_array_list (List **lst, int *len);
int resize (char **str, int *len);

List* read_from_file(std::istream &file, int *index);

#endif // FUNCTIONS_HPP
