#include <iostream>
#include <cstring>
#include <fstream>
#include "phone.hpp"
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
    Phone *phone = read_from_file(file, &len);
    if(!phone){
        std::cout << "Error: Memory Allocated!";
        file.close();
        return MEMORY_ALLOCATED;
    }

    //Print Data
    for (int i = 0; i < len; i++)
        phone[i].print_phone();

    std::cout << "1 - Time in city oferflow your time" << std::endl;
    std::cout << "2 - People use out city" << std::endl;
    std::cout << "3 - Sort phone on Alphabit By name" << std::endl;

    int key;
    std::cin >> key;
    /*сведения об абонентах, время внутригородских разговоров которых
                        превышает заданное*/
    if (key == 1){
        double limit;
        std::cout << "Input limit time(double): ";
        std::cin >> limit;
        get_inf_limit_timeIn(phone, len, limit);
    }
    /*сведения об абонентах, воспользовавшихся междугородней связью*/
    if (key == 2){
        get_inf_limit_timeOut(phone, len);
    }
    /*cведения об абонентах, выведенные в алфавитном порядке(по имени)*/
    if (key == 3){
        if(Phone::sort_alphabit(phone, len) == MEMORY_ALLOCATED){
            std::cout << "Error: Some problems in sort (Memory Allocated)!";
            file.close();
            return MEMORY_ALLOCATED;
        }
    }

    file.close();
    return 0;
}
