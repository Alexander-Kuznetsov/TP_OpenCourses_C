#include "circle.hpp"

void Circle::Perimeter(){
    if (r != 0){
        double p = r * 2 * 3.1415;
        std::cout << "Your perimeter Circle is " << p << std::endl;
    }
    else
        std::cout << "Circle not exist!" << std::endl;
}

void Circle::Area(){
    if (r != 0){
        double s = 3.1415 * r * r;
        std::cout << "Your area Circle is " << s << std::endl;
    }
    else
        std::cout << "Circle not exist!" << std::endl;
}

void Circle::SetElem(double _r, double _a = -1, double _b = -1) {
    this->r = _r;
}

Circle &Circle::operator=(const Circle &rhs){
    this->r = rhs.r;
    return *this;
}
