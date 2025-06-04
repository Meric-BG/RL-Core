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

        // Copy
        Tensor(const Tensor& other) {
            size_ = other.size_;
            ndim_ = other.ndim_;

            shape_ = new size_t[ndim_];
            for (size_t i = 0; i < ndim_; i++) {
                shape_[i] = other.shape_[i];
            }
            data_ = new float[size_];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }

        // Assignment
        Tensor operator=(const Tensor& other) {
            delete[] data_;
            data_ = nullptr;
            data_ = new float[other.size];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }

        }

        // Move constructor
        Tensor(const tensor& other) {
            ndim_ = other.ndim_;
            data_ = other.data_;
            shape_ = other.shape_;
            size_ = other.size_;

            for (size_t i = 0; i < ndim_; i++) {
                shape_[i] = other.shape_[i];
                //other.ndim_[i] = 0.0f; 
            }

            for (size_t i = 0; i < size; i++) {
                data_[i] = other.data_[i];

            }
            other.shape_ = nullptr;
            other.data_ = nullptr;
        }

        // Move assignment constructor
        Tensor(const tensor& other) {
            ndim_ = other.ndim_;
            data_ = other.data_;
            shape_ = other.shape_;
            size_ = other.size_;
            
            data_ = nullptr;
            shape_ = nullptr;

            for (size_t i = 0; i < ndim_; i++) {
                shape_[i] = other.shape_[i];
                //other.ndim_[i] = 0.0f; 
            }

            for (size_t i = 0; i < size; i++) {
                data_[i] = other.data_[i];

            }
            other.shape_ = nullptr;
            other.data_ = nullptr;
        }

        // Addition operatot
        Tensor operator+(const tensor& a, const tensor& b) {
            if (!a.ndim_ || !b.ndim_ || !a.size_ || !b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "have underfined ndim or size." << endl;
                std::terminate();
            }
            if (a.ndim_ != b.ndim_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same rank." << endl;
                std::terminate();
            }
            if (a.size_ != b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same size." << endl;
                std::terminate();
            }
            ndim_ = a.ndim_;
            size_ = a.size_;
            for (size_t i = 0; i < ndim_; i++) {
            if (a.shape_[i] != b.shape_[i]) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same shape." << endl;
                std::terminate();
            }
        }

        for (size_t i = 0; i < size_; i++) {
            data_[i] = a.data_[i] + b.data_[i];
        }
        }

        // Substraction operator
        Tensor operator-(const tensor& a, const tensor& b) {
            if (!a.ndim_ || !b.ndim_ || !a.size_ || !b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "have underfined ndim or size." << endl;
                std::terminate();
            }
            if (a.ndim_ != b.ndim_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same rank." << endl;
                std::terminate();
            }
            if (a.size_ != b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same size." << endl;
                std::terminate();
            }
            ndim_ = a.ndim_;
            size_ = a.size_;
            for (size_t i = 0; i < ndim_; i++) {
            if (a.shape_[i] != b.shape_[i]) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same shape." << endl;
                std::terminate();
            }
            }

        for (size_t i = 0; i < size_; i++) {
            data_[i] = a.data_[i] - b.data_[i];
        }
    }

            // Multiplication operator
        Tensor operator*(const tensor& a, const tensor& b) {
            if (!a.ndim_ || !b.ndim_ || !a.size_ || !b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "have underfined ndim or size." << endl;
                std::terminate();
            }
            if (a.ndim_ != b.ndim_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same rank." << endl;
                std::terminate();
            }
            if (a.ndim_ > 1 && (a.shape_[0] != a.shape_[1])) {
                throw cerr << "Error, Tensor" << a << "'s rows number must be equal to Tensor" << b << "cols." << endl;
                std::terminate();
            }
            if (a.size_ != b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same size." << endl;
                std::terminate();
            }
            ndim_ = a.ndim_;
            size_ = a.size_;
            for (size_t i = 0; i < ndim_; i++) {
            if (a.shape_[i] != b.shape_[i]) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same shape." << endl;
                std::terminate();
            }
            }
    for (size_t i = 0; i < a.shape[0]; i++) {
        for (size_t j = 0; j < b.shape[1]; j++) {
            for (size_t k = 0; k < a.shape[1]; k++) {

                data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
}

        // Division operator
        Tensor operator/(const tensor& a, const tensor& b) {
            if (!a.ndim_ || !b.ndim_ || !a.size_ || !b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "have underfined ndim or size." << endl;
                std::terminate();
            }
            if (a.ndim_ != b.ndim_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same rank." << endl;
                std::terminate();
            }
            if (a.ndim_ > 1 && (a.shape_[0] != a.shape_[1])) {
                throw cerr << "Error, Tensor" << a << "'s rows number must be equal to Tensor" << b << "cols." << endl;
                std::terminate();
            }
            if (a.size_ != b.size_) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same size." << endl;
                std::terminate();
            }
            ndim_ = a.ndim_;
            size_ = a.size_;
            for (size_t i = 0; i < ndim_; i++) {
            if (a.shape_[i] != b.shape_[i]) {
                throw cerr << "Error, Tensor" << a << "and Tensor" << b << "must have same shape." << endl;
                std::terminate();
            }
            }
    for (size_t i = 0; i < a.shape[0]; i++) {
        for (size_t j = 0; j < b.shape[1]; j++) {
            for (size_t k = 0; k < a.shape[1]; k++) {
                if (b.data_[k][j] == 0) {
                    throw cerr << "Division by zero at" << b <<".data_[" << k << j << endl; 
                }
                data_[i][j] += a.data_[i][k] / b.data_[k][j];
            }
        }
    }
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
