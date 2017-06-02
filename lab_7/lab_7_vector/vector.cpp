//#include "vector.hpp"

//-----------------constructors---------------------

/*template<class T>
Vectors<T>::Vectors(size_t size):size_(size){
    buffer = new T[capacity_];
}

template<class T>
Vectors<T>::Vectors(const Vectors<T> &vector): size_(vector.size_), capacity_(vector.capacity_){
    Log = vector.Log;
    buffer = new T[size_];
    for (size_t i = 0; i < size_; i++)
        buffer[i] = vector.buffer[i];
}

template<class T>
Vectors<T>::Vectors(size_t size, const T &initial): size_(size) {
    Log = ceil(log((double) size) / log(2.0));
    capacity_ = 1 << Log;
    buffer = new T [capacity_];
    for (size_t i = 0; i < size; i++)
        buffer[i] = initial;
}

*/
/*
 * Vector(const Vector<T> &vect): len_vector(vect.len_vector){
            vector = new T[len_vector];
            for (size_t i = 0; i < len_vector; i++)
                vector[i] = vect.vector[i];
        }

        Vector(size_t size, const T &initial): len_vector(size) {
            vector = new T [len_vector];
            for (size_t i = 0; i < len_vector; i++)
                vector[i] = initial;
        }

        Vector(){
             len_vector = 0;
             vector = new T[len_vector];
        }
    */
