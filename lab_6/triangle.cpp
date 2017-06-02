#include "triangle.hpp"

void Triangle::Perimeter(){
    if ((a + b) > c && (a + c) > b && (b + c) > a){
        double p = a + b + c;
        std::cout << "Your perimeter Triangle is " << p << std::endl;
    }
    else
        std::cout << "Triangle not exist!" << std::endl;
}
void Triangle::Area(){
    if ((a + b) > c && (a + c) > b && (b + c) > a){
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        std::cout << "Your area Triangle is " << s << std::endl;
    }
    else
        std::cout << "Triangle not exist!" << std::endl;
}

void Triangle::SetElem(double _a, double _b, double _c){
    this->a = _a;
    this->b = _b;
    this->c = _c;
}

Triangle &Triangle::operator=(const Triangle &rhs){
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    return *this;
}
