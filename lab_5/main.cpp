#include <iostream>
#include <fstream>
#include "list.hpp"
#include "functions.hpp"

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Error: no input file!";
        return NOT_INPUT_FILE;
    }

    std::ifstream file;
    file.open(argv[1], std::ios::in);
    if (!file.is_open()){
        std::cout << "Error: file not exist!";
        return FILE_NOT_EXIST;
    }

    if (file.peek() == EOF){
        std::cout << "Error: file is empty!";
        file.close();
        return EMPTY_FILE;
    }

    int len = 0;
    List *lst = read_from_file(file, &len);
    if(!lst){
        std::cout << "Error: Memory Allocated!";
        file.close();
        delete[] lst;
        return MEMORY_ALLOCATED;
    }

    sort_array(lst, len);
    print_array(lst, len);

    delete[] lst;
    return 0;
}
