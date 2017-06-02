#include <iostream>
#include <fstream>
#include "string.hpp"

#define NOT_INPUT_FILE -1
#define FILE_NOT_EXIST -2
#define EMPTY_FILE -3

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Error: no input file!";
        return NOT_INPUT_FILE;
    }

    std::ifstream file(argv[1], std::ios::in);
    if (!file.is_open()){
        std::cout << "Error: file not exist!";
        return FILE_NOT_EXIST;
    }

    if (file.peek() == EOF){
        std::cout << "Error: file is empty!";
        file.close();
        return EMPTY_FILE;
    }

    String str1;
    file >> str1;
    std::cout << str1 << std::endl;

    String str2 = "ab", str3 = "cd", str4;
    str4 = str2 + str3;
    std::cout << str4 << std::endl;

    str3 += str2;
    std::cout << str3 << std::endl;

    String str5 = "ab";
    if (str5 == str2)
        std::cout << str5 << " " << str2 << " String are equal" << std::endl;
    if (str5 == str3)
        std::cout << str5 << " " << str3 << " String are equal" << std::endl;
    if (str5 != str2)
        std::cout << str5 << " " << str2 << " String are NOT equal" << std::endl;
    if (str5 != str3)
        std::cout << str5 << " " << str3 << " String are NOT equal" << std::endl;

    std::cout << "Len str2 is: " << str2.get_len() << std::endl;

    return 0;
}
