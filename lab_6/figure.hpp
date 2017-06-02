#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <cmath>

class Figure{
    public:
        virtual ~Figure() { --count; }

        virtual void Area() = 0;
        virtual void Perimeter() = 0;
        virtual void SetElem(double, double, double) = 0;

        virtual Figure *NewFigure() = 0;
        virtual Figure *Copy() = 0;

        static int get_count(){ return count; }
    protected:
        Figure() { ++count; }

        static int count;
};

#endif // FIGURE_HPP
