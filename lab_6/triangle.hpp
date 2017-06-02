#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"

class Triangle: public Figure{
    public:
        Triangle(double _a = 0, double _b = 0, double _c = 0): a(_a), b(_b), c(_c) { }
        ~Triangle() {}

        void Perimeter();
        void Area();
        void SetElem(double _a, double _b, double _c);

        Triangle *NewFigure() { return new Triangle(); }
        Triangle *Copy() { Triangle *rhs = new Triangle(); *rhs = *this; return rhs; }
        Triangle &operator=(const Triangle &rhs);
    private:
        double a, b, c;
};

#endif // TRIANGLE_HPP
