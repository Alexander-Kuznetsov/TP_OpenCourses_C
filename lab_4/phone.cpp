#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "phone.hpp"

#define MEMORY_ALLOCATED -4

Phone::Phone(){
    this->name = nullptr;
    this->surname = nullptr;
    this->fathername = nullptr;
    this->address = nullptr;
    this->time_in = 0;
    this->time_out = 0;
    this->number = 0;
}

Phone::Phone(char *name, char *surname, char *fathername, char *address, char *number, double time_in, double time_out){
    set_name(name);
    set_surname(surname);
    set_fathername(fathername);
    set_address(address);
    set_time_in(time_in);
    set_time_out(time_out);
    set_number(number);
}

Phone::~Phone(){
    if (name){
        delete[] name;
        name = nullptr;
    }
    if (surname){
        delete[] surname;
        surname = nullptr;
    }
    if (fathername){
        delete[] fathername;
        fathername = nullptr;
    }
    if (address){
        delete[] address;
        address = nullptr;
    }
    if (time_in)
        time_in = 0;
    if (time_out)
        time_out = 0;
    if (number)
        number = 0;
}

void Phone::print_phone(){
    std::cout << get_name() << std::endl;
    std::cout << get_surname() << std::endl;
    std::cout << get_fathername() << std::endl;
    std::cout << get_address() << std::endl;
    std::cout << get_number() << std::endl;
    std::cout << get_time_in() << std::endl;
    std::cout << get_time_out() << std::endl;
    std::cout << std::endl;
}

int Phone::cmp(const void *a, const void *b){
    return strcmp(((Phone*) a)->name, ((Phone *) b)->name);
}

int Phone::sort_alphabit(Phone *phone, int len){
    Phone *tmp = new Phone[len];
    if(!tmp)
        return MEMORY_ALLOCATED;
    tmp = phone;
    qsort(tmp, len, sizeof(Phone), cmp);
    for (int i = 0; i < len; i++){
        tmp[i].print_phone();
    }
    return 0;
}

Phone &Phone::operator=(const Phone &rhs){
    if (this == &rhs)
        return *this;

    if (name){
        delete[] name;
        name = nullptr;
    }
    if (surname){
        delete[] surname;
        surname = nullptr;
    }
    if (fathername){
        delete[] fathername;
        fathername = nullptr;
    }
    if (address){
        delete[] address;
        address = nullptr;
    }
    if (number){
        delete[] number;
        number = nullptr;
    }
    if (time_in)
        time_in = 0;
    if (time_out)
        time_out = 0;

    if (rhs.name)
        set_name(rhs.name);
    if (rhs.surname)
        set_surname(rhs.surname);
    if (rhs.fathername)
        set_fathername(rhs.fathername);
    if (rhs.address)
        set_address(rhs.address);
    if (rhs.number)
        set_number(rhs.number);
    if (rhs.time_in)
        set_time_in(rhs.time_in);
    if (rhs.time_out)
        set_time_out(rhs.time_out);

    return *this;
}

//this blocks for sets
int Phone::set_name(char *name){
    size_t len = strlen(name) + 1;
    this->name = new char[len];
    if(!(this->name))
        return MEMORY_ALLOCATED;
    if(!memcpy(this->name, name, len))
        return MEMORY_ALLOCATED;
    return 0;
}

int Phone::set_surname(char *surname){
    size_t len = strlen(surname) + 1;
    this->surname = new char[len];
    if(!(this->surname))
        return MEMORY_ALLOCATED;
    if(!memcpy(this->surname, surname, len))
        return MEMORY_ALLOCATED;
    return 0;
}

int Phone::set_fathername(char *fathername){
    size_t len = strlen(fathername) + 1;
    this->fathername = new char[len];
    if(!( this->fathername))
        return MEMORY_ALLOCATED;
    if(!memcpy(this->fathername, fathername, len))
        return MEMORY_ALLOCATED;
    return 0;
}

int Phone::set_address(char *address){
    size_t len = strlen(address) + 1;
    this->address = new char[len];
    if(!(this->address))
        return MEMORY_ALLOCATED;
    if(!memcpy(this->address, address, len))
        return MEMORY_ALLOCATED;
    return 0;
}

int Phone::set_number(char *number){
    size_t len = strlen(number) + 1;
    this->number = new char[len];
    if(!(this->number))
        return MEMORY_ALLOCATED;
    if(!memcpy(this->number, number, len))
        return MEMORY_ALLOCATED;
    return 0;
}

void Phone::set_time_in(double time_in){
    this->time_in = time_in;
}

void Phone::set_time_out(double time_out){
    this->time_out = time_out;
}

//this blocks for gets
const char* Phone::get_name() const{
    if (this->name)
        return this->name;
    return NULL;
}

const char* Phone::get_surname() const{
    if (this->surname)
        return this->surname;
    return NULL;
}

const char* Phone::get_fathername() const{
    if (this->fathername)
        return this->fathername;
    return NULL;
}

const char* Phone::get_address() const{
    if (this->address)
        return this->address;
    return NULL;
}

const char* Phone::get_number() const{
    if (this->number)
        return this->number;
    return NULL;
}

const double Phone::get_time_in() const{
    if (this->time_in)
        return this->time_in;
    return 0;
}

const double Phone::get_time_out() const{
    if (this->time_out)
        return this->time_out;
    return 0;
}
