#include "tensor.hpp"
#include <iostream>

int main() {
    // 1. Create original tensor
    Tensor t({2, 3});
    for (int i = 0; i < 6; i++) {
        t[i] = (i + 1); // Fill with 1.0, 2.0, ..., 6.0
    }

    std::cout << "Original Tensor t: ";
    t.print();

    // 2. Test Deep Copy Constructor
    Tensor t_copy = t; // This calls the copy constructor
    
    // 3. Modify original to prove they are independent
    t[0] = 99.0;
    
    std::cout << "Modified Original t: ";
    t.print(); 

    std::cout << "Copy t_copy (should be unchanged): ";
    t_copy.print();

    // Verification
    if (t_copy[0] == 1.0) {
        std::cout << "\nSUCCESS: Deep copy is working!\n";
    } else {
        std::cout << "\nFAILURE: Shallow copy detected (t_copy was modified)!\n";
    }

    return 0;
}
