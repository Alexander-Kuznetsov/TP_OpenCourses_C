#include "functions.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>

int resize (char **str, int *len){
    char *realstr = *str;
    char *tmp = new char[*len * 2 + 1];

    if (!tmp)
        return MEMORY_ALLOCATED;
    if (!memcpy(tmp, *str, *len)){
        delete[] tmp;
        return MEMORY_ALLOCATED;
    }

    delete[] realstr;
    *str = tmp;
    (*len) *= 2;
    return 0;
}

int resize_phone (Phone **phone, int *len) {
    Phone *realPhone = *phone;
    Phone *second = new Phone[*len * 2];

    if (!second)
        return MEMORY_ALLOCATED;

    for (int i = 0; i < *len; i++)
        second[i] = realPhone[i];
    delete[] realPhone;
    *phone = second;
    (*len) *= 2;
    return 0;
}

void get_inf_limit_timeIn(Phone *phone, int len, double limit){
    for(int i = 0; i < len; i++){
        if(phone[i].get_time_in() > limit)
            phone[i].print_phone();
    }
}

void get_inf_limit_timeOut(Phone *phone, int len){
    for(int i = 0; i < len; i++){
        if(phone[i].get_time_out() > 0)
            phone[i].print_phone();
    }
}

Phone* read_from_file(std::istream &file, int *index){
    int len = 10, len_str = len, len_phone = len;
    int i = 0, full = 1;
    char c;
    *index = 0;

    Phone *phone = new Phone[len];
    if(!phone)
        return NULL;
    char *str = new char[len + 1];
    if (!str)
        return NULL;

    while(!file.eof()){
        c = file.get();
        if(isspace(c) != 0 && i != 0){
            if (*index >= len_phone){
                if (resize_phone(&phone, &len_phone) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            }

            str[i] = '\0';
            if (full == 1)
                if(phone[*index].set_name(str) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            if (full == 2)
                if(phone[*index].set_surname(str) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            if (full == 3)
                if(phone[*index].set_fathername(str) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            if (full == 4)
                if(phone[*index].set_address(str) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            if (full == 5)
                if(phone[*index].set_number(str) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            if (full == 6)
                phone[*index].set_time_in(atof(str));
            if (full == 7)
                phone[*index].set_time_out(atof(str));;

            i = 0;
            delete[] str;
            len_str = len;
            str = new char[len + 1];
            if (!str)
                return NULL;

            if (full >= 7){
                full = 1;
                ++(*index);
            }
            else
                ++full;
        }
        else{
            if (i >= len_str){
                if(resize(&str, &len_str) == MEMORY_ALLOCATED){
                    delete[] str;
                    return NULL;
                }
            }
            str[i] = c;
            ++i;
        }
    }

    delete[] str;
    if (full >= 7)
        ++(*index);
    return phone;
}
