#include "vector.hpp"

#include <iostream>
int main(){
    Vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    for (int i: vect)
        std::cout << i<<std::endl;
    return 0;
}
