#include "string.hpp"
#include <cstring>

String::String(): len_str(0), str('\0'){}

String::String(const char *str){
    copy(str);
}

String::String(const String &str){
    copy(str.str);
}

String::~String(){
    delete[] str;
}

String &String::operator= (const String &str){
    delete[] this->str;
    copy(str.str);
    return *this;
}

String &String::operator= (const char *ch){
    delete[] this->str;
    copy(ch);
    return *this;
}

char &String::operator[] (size_t size) {
    return str[size];
}

const char &String::operator[] (size_t size) const{
    return str[size];
}


bool operator== (const String &str, char *ch){
    return (strcmp(str.str, ch) == 0);
}

bool operator== (const String &str1, const String &str2){
    return (strcmp(str1.str, str2.str) == 0);
}

bool operator!= (const String &str, char *ch){
    return !(strcmp(str.str, ch) == 0);
}

bool operator!= (const String &str1, const String &str2){
    return !(strcmp(str1.str, str2.str) == 0);
}

size_t String::get_len() const{
    return (len_str);
}

std::ostream& operator<< (std::ostream& out, const String &str){
    out << str.str;
    return out;
}

std::istream& operator>> (std::istream& in, String &str){
    str.get_string(in);
    return in;
}

/*String String::operator+ (const String &str){
    return (String(*this) += str);
}*/

String operator+ (const String &str1, const String &str2){
    size_t len_str = strlen(str1.str) + strlen(str2.str);
    char *newStr = new char[len_str + 1];
    strncpy(newStr, str1.str, strlen(str1.str) + 1);
    strncat(newStr, str2.str, strlen(str2.str) + 1);
    return String(newStr);
}

String &String::operator+= (const String &string){
    len_str = strlen(str) + strlen(string.str);
    char *newStr = new char[len_str + 1];
    strncpy(newStr, str, strlen(str) + 1);
    strncat(newStr, string.str, strlen(string.str) + 1);
    strncpy(str, newStr, len_str + 1);
    delete[] newStr;
    return *this;
}

void String::get_string(std::istream& in){
    char ch;
    while(true){
        if ((ch = in.get ()) == '\n' || ch == EOF)
            break;
        ++len_str;

        char* newStr = new char[len_str + 1];
        if (str != NULL)
            strncpy(newStr, str, strlen(str) + 1);

        newStr[len_str - 1] = ch;
        newStr[len_str] = '\0';

        delete[] str;
        copy(newStr);
        delete[] newStr;
    }
}


void String::copy(const char *data){
    len_str = strlen(data);
    str = new char[len_str + 1];
    strncpy(str, data, len_str + 1);
}
