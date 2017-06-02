#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector{
    private:
        T *vector;
        size_t len_vector;
    public:
        typedef T *Iterator;

        Vector(const Vector<T> &vect): len_vector(vect.len_vector){
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

        ~Vector(){
            delete[] vector;
        }

        Iterator begin(){
            return vector;
        }

        Iterator end(){
            return vector + size();
        }

        T &first() {
            return vector[0];
        }

        T &last(){
            return vector[len_vector - 1];
        }

        Vector<T> &operator= (const Vector<T> &vect) {
            delete[] vector;
            len_vector = vect.len_vector;
            vector = new T[len_vector];
            for (size_t i = 0; i < len_vector; i++)
                vector[i] = vect.vector[i];
            return *this;
        }

        T get_elem(size_t i){
            if (i < len_vector){
                return vector[i];
            }
            return (T)NULL;
        }

        void push_back(T data){
            T *newVector = new T[++len_vector];
            for(size_t i = 0; i < len_vector - 1; i++)
                newVector[i] = vector[i];
            newVector[len_vector - 1] = data;
            delete[] vector;
            vector = newVector;
        }

        void push_front(T data){
            T *newVector = new T[++len_vector];
            newVector[0] = data;
            for(size_t i = 1; i < len_vector; i++)
                newVector[i] = vector[i];
            delete[] vector;
            vector = newVector;
        }

        T pop(){
            return popIndex(len_vector - 1);
        }

        void clear(){
            if(vector != NULL)
                delete[] vector;
            len_vector = 0;
            vector = new T[len_vector];
        }

        T operator[] (int index){
            return vector[index];
        }

        int size(){
            return len_vector;
        }

        void pushIndex(T data, int index){
            int oldLen = len_vector;
            len_vector = (len_vector >= index) ?
                        (++len_vector): (len_vector + (index - len_vector));
            T *newVector = new T[len_vector];
            int vecIndex = 0;
            for(int i = 0; i < len_vector; i++){
                if(i == index){
                    newVector[i] = data;
                    continue;
                }
                if(vecIndex != oldLen){
                    newVector[i] = vector[vecIndex++];
                }
            }
            delete[] vector;
            vector = newVector;
        }

        T popIndex(int index){
            T *newVector = new T[--len_vector];
            T resItem;
            int resIndex = 0;
            for(int i = 0; i < len_vector + 1; i++){
                T item = vector[i];
                if(index == i){
                    resItem = item;
                    continue;
                }
                newVector[resIndex++] = vector[i];
            }
            delete[] vector;
            vector = newVector;
            return resItem;
        }
};

#endif // VECTOR_HPP
