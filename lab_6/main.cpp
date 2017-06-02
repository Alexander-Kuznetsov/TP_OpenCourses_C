#include <iostream>

#include "triangle.hpp"
#include "circle.hpp"

int main(){
    Figure *shape[5] = {};

    shape[0] = new Triangle(3, 4, 5);
    shape[1] = new Circle(5);
    shape[2] = new Circle(8);
    shape[3] = new Triangle(7, 2, 8);
    shape[4] = new Circle(3);
    int len_shape = Figure::get_count();

    for (int i = 0; i < len_shape; i++){
        shape[i]->Area();
        shape[i]->Perimeter();
        std::cout << std::endl;
    }

    for (int i = 0; i < len_shape; i++)
        delete shape[i];

    return 0;
}
