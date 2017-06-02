#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include "phone.hpp"

#define NOT_INPUT_FILE -1
#define FILE_NOT_EXIST -2
#define EMPTY_FILE -3
#define MEMORY_ALLOCATED -4

int resize (char **str, int *len);
int resize_phone (Phone **phone, int *len);

void get_inf_limit_timeIn(Phone *phone, int len, double limit);
void get_inf_limit_timeOut(Phone *phone, int len);

Phone* read_from_file(std::istream &file, int *index);

#endif // FUNCTIONS_HPP
