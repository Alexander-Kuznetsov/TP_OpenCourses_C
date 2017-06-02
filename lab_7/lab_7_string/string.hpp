#ifndef STRING_HPP
#define STRING_HPP

#include "iostream"

class String{
    public:
        String();
        String(const char *str);
        String(const String &str);
        ~String();

        String &operator=(const char *ch);
        String &operator=(const String &str);

        size_t get_len() const;

        //String operator+ (const String &str);
        String &operator+= (const String &string);

        char &operator[] (size_t size);
        const char &operator[] (size_t size) const;

        friend String operator+ (const String &str1, const String &str2);

        friend bool operator== (const String &str, char *ch);
        friend bool operator== (const String &str1, const String &str2);

        friend bool operator!= (const String &str, char *ch);
        friend bool operator!= (const String &str1, const String &str2);

        friend std::ostream &operator<< (std::ostream& out, const String &str);
        friend std::istream &operator>> (std::istream& in, String &str);
    private:
        size_t len_str;
        char *str;

        void copy(const char *data);
        void get_string(std::istream& in);
};

#endif // STRING_HPP
