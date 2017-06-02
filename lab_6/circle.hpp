#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "figure.hpp"

class Circle: public Figure{
    public:
        Circle(double r = 0): r(r) { }
        ~Circle() {}

        void Perimeter();
        void Area();
        void SetElem(double _r, double _a, double _b);

        Circle *NewFigure() { return new Circle(); }
        Circle *Copy() {
            Circle *rhs = new Circle(*this);

            return rhs; }
        Circle &operator=(const Circle &rhs);
    private:
        double r;

};

#endif // CIRCLE_HPP
