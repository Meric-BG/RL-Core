#include "tensor.hpp"

int main() {
    Tensor t({2, 3});
    
    t[0] = 1.0;
    t[1] = 2.0;
    t[2] = 3.0;
    t[3] = 4.0;
    t[4] = 5.0;
    t[5] = 6.0;
    
    t.print();
    
    return 0;
}