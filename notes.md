5/12/25
Is Tensor a class ?
We discoverd taht Tensir are class. 
Then we'll look for what inside the class Tensor ?
https://docs.pytorch.org/tutorials/beginner/basics/tensorqs_tutorial.html

8/12/25
Constructor
Destructor 
Operator 

18/12/25
In C++, move constructors should take rvalue references

Tensor& operator=(const Tensor& other)   // Copy assignment operator
Tensor(const Tensor& other);       // Copy constructor (const lvalue ref)
Tensor(Tensor&& other);            // Move constructor (rvalue ref)
Tensor& operator=(Tensor&& other); // Move assignment operator

We use "noexcept" for the 2 move constructors.























