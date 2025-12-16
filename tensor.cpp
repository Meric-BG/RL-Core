#include <ostream>

class Vector {
    float* data_;
    size_t size_;

    
private:
    Vector(size_t size) : size_(size) {
        data_ = new float[size];
    }
    
    ~Vector() {
        delete[] data_;
    }

    float& operator[](size_t i) {
        return data_[i]
    }

};

// Test it
int main() {
    Vector v(5);
    v[0] = 1.0;
    v[1] = 2.0;
    std::cout << v[0] << std::endl;
}