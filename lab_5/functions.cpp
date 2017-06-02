#include "functions.hpp"

void sort_array(List *lst, int len){
    for (int i = 0; i < len; i++)
        lst[i].bubble_sort_list();
}

void print_array(List *lst, int len){
    for (int i = 0; i < len; i++){
        int len_lst = lst[i].get_len();
        for (int j = 0; j < len_lst; j++)
            std::cout << lst[i].get_elem(j) << " ";
        std::cout << std::endl;
    }
}

int resize_array_list (List **lst, int *len) {
    List *realList = *lst;
    List *second = new(std::nothrow) List[*len * 2];

    if (!second)
        return MEMORY_ALLOCATED;
    for(int i = 0; i < *len; i++)
        second[i] = realList[i];
    delete[] realList;
    *lst = second;
    (*len) *= 2;
    return 0;
}

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

List* read_from_file(std::istream &file, int *index){
    int len = 10, len_str = len, len_list = len;
    int i = 0;
    char c;
    *index = 0;

    List *lst = new(std::nothrow) List[len];
    if(!lst)
        return NULL;
    char *str = new(std::nothrow) char[len + 1];
    if (!str){
        delete[] lst;
        return NULL;
    }

    while(!file.eof()){
        c = file.get();
        if((isspace(c) != 0 || c == EOF) && i != 0 ){
            if (*index >= len_list){
                if (resize_array_list(&lst, &len_list) == MEMORY_ALLOCATED){
                    delete[] str;
                    delete[] lst;
                    return NULL;
                }
            }

            str[i] = '\0';
            lst[*index].push_in_list(atoi(str));

            i = 0;
            delete[] str;
            len_str = len;
            str = new(std::nothrow) char[len + 1];
            if (!str){
                delete[] lst;
                return NULL;
            }
            if (c == '\n' || c == EOF)
                (*index)++;
        }
        else{
            if (i >= len_str){
                if(resize(&str, &len_str) == MEMORY_ALLOCATED){
                    delete[] str;
                    delete[] lst;
                    return NULL;
                }
            }
            if (isdigit(c)){
                str[i] = c;
                ++i;
            }
        }
    }

    delete[] str;
    return lst;
}
