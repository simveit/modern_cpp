#include <iostream>

struct Array {
  int* array;
  Array() {  // constructor
    std::cout << "construct" << std::endl;
    array = new int[10];
  }
  ~Array() {  // destructor called when out of scope
    std::cout << "destruct" << std::endl;
    delete[] array;
  }
};

int main() {
  Array a;

  for (size_t i = 0; i < 3; i++) {
    Array b;
  }
}