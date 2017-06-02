#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <stdexcept>

const int ERROR_INPUT = -1;
const int NOT_CORRECT_FILES = -2;
const int NOT_FOUND = -3;

void count_word(const std::string word, char *(&data),
                size_t &amount_files, size_t &amount_words){
    std::ifstream file(data);
    if (!file.is_open())
        throw std::invalid_argument("Can`t open file: ");
    std::istream_iterator<std::string> words(file), eof;
    amount_words += count(words, eof, word);
    ++amount_files;
    file.close();
}

int main(int argc, char *argv[]){
    if (argc < 3){
        std::cerr << "Need 2 or more parameters!";
        return ERROR_INPUT;
    }

    size_t amount_words = 0, amount_files = 0;
    std::string word(argv[1]);
    for (int i = 2; i < argc; i++){
        try
        {
            count_word(word, argv[i], amount_files, amount_words);
        }
        catch(std::invalid_argument &p)
        {
            std::cerr << p.what() << argv[i] << std::endl;
        }
    }

    if (!amount_files){
        std::cerr << "Don`t have correct files!";
        return NOT_CORRECT_FILES;
    }
    if (!amount_words){
        std::cerr << "Word not found!";
        return NOT_FOUND;
    }
    std::cout << "Average entering word <" + word + "> is "
              << amount_words / amount_files << std::endl;

    return 0;
}
