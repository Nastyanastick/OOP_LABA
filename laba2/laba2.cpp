#include "laba2.h"
#include <algorithm>
#include <stdexcept> //класс исключений
#include <cstring> 

Money::Money(const std::string& str){
    size = str.size();
    mon = new unsigned char[size];

    for (size_t i = 0; i < size; ++i){
        if(str[size - 1 - i] < '0' || str[size - 1 - i] > '9')
            throw std::invalid_argument("Invalid character in string");
        mon[i] = str[size - 1 - i] - '0';
    }
}

Money::~Money(){
    delete[] mon;
    mon = nullptr;
    size = 0;
}


Money Money::add(const Money& other) const{
    size_t sizem = std::max(size, other.size);

    unsigned char* res = new unsigned char[sizem + 1];

    int a = 0;
    for (size_t i = 0; i < sizem; ++i){
        int d1;
        if (i < size)
            d1 = mon[i];
        else
            d1 = 0;


        int d2;
        if(i < other.size)
            d2 = other.mon[i];
        else
            d2 = 0;

        int sum = d1 + d2 + a;

        res[i] = sum % 10;

        a = sum / 10;
    }

    if (a > 0){
        res[sizem] = a;
        ++sizem;
    }

    std::string str;
    for (size_t i = 0; i < sizem; ++i){
        str.insert(str.begin(), res[i] + '0');
    }

    delete[] res;
    return Money(str);
}

std::string Money::tostr() const{
    std::string str;
    for (size_t i = size; i > 0; i--){
        str += mon[i - 1] + '0';
    }

    return str;
}



bool Money::men(const Money& other) const{
    if (size < other.size)
        return true;
    if (size > other.size)
        return false;

    for (size_t i = size; i > 0; i--){
        size_t index = i - 1;
        if (mon[index] < other.mon[index])
            return true;
        if (mon[index] > other.mon[index])
        return false;
    }
    return false;
}

bool Money::bol(const Money& other) const{
    if (other.size < size)
        return true;
    if (other.size > size)
        return false;

    for (size_t i = size; i > 0; i--){
        size_t index = i - 1;
        if (other.mon[index] < mon[index])
            return true;
        if (other.mon[index] > mon[index])
            return false;
    }
    return false;
}

bool Money::ravno(const Money& other) const{
    if (!this->men(other) && !this->bol(other))
        return true;
    else
        return false;
}



Money Money::minus(const Money& other) const{
    if (this->men(other))
        throw std::invalid_argument("You can't subtract more from less");

    size_t sizem = size;

    unsigned char* res = new unsigned char[sizem];
    int q = 0;

    for (size_t i = 0; i < sizem; ++i){
        int d1 = mon[i];
        int d2;
        if (i < other.size)
            d2 = other.mon[i];
        else
            d2 = 0;

        int a = d1 - d2 - q;

        if (a < 0){
            a += 10;
            q = 1;
        }else{
            q = 0;
        }

        res[i] = a;
    }

    while (sizem > 1 && res[sizem - 1] == 0){
        --sizem;
    }

    std::string str;
    for (size_t i = 0; i < sizem; ++i)
        str.insert(str.begin(), res[i] + '0');

    delete[] res;
    return Money(str);
}

Money Money::copy() const{
    return Money(this->tostr());
}

Money::Money(){
    mon = nullptr;
    size = 0;
}