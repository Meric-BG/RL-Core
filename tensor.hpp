//tensor.hpp
#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class Tensor {
private:    
    float* data_;
    size_t* shape_;
    size_t ndim_;
    size_t size_;

public:
    Tensor(std::vector<size_t> shape) {
        ndim_ = shape.size();
        shape_ = new size_t[ndim_]; 

        size_ = 1;
        for (size_t i = 0; i < ndim_; i++) {
            shape_[i] = shape[i];
            size_ *= shape[i];
        }

        data_ = new float[size_];

        for (size_t i = 0; i < size_; i++) {
            data_[i] = 0.0f;
        }
    }    
        ~Tensor() {
            delete[] data_;
            delete[] shape_;
            data_ = nullptr;
            shape_ = nullptr;
        }

        float& operator[] (size_t i) {
            if (i >= size_) {
                throw std::out_of_range("Out of range");
            }
            return data_[i];
        }

        void print() const {
            std::cout << "Tensor(" ;
            for (size_t i = 0; i < ndim_; i++) {
                std::cout << shape_[i];
                if (i < ndim_ -1 ) 
                    std::cout << ",";
            }
            std::cout << "): [";
            for (size_t i = 0; i < size_; i++) {
                std::cout << data_[i];
                if (i < size_ -1 ) 
                    std::cout << ",";
            }
            std::cout << "]";
        }

};

#endif