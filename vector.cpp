#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <ostream>
#include <iostream>

class Vector {
    float* data_;
    size_t size_;

    
public:
    Vector(size_t size) : size_(size) {
        data_ = new float[size];
    }
    
    ~Vector() {
        delete[] data_;
    }

    float& operator[](size_t i) {
        return data_[i];
    }

};

int main() {
    Vector v(5);
    v[0] = 1.0;
    v[1] = 2.0;
    std::cout << v[0] << std::endl; 
    // Vector.delete(v);
}