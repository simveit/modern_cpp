#include <iostream>
#include <print>

int main() {
  // Standard way
  std::cout << "Hello World!\n";
  // -std=c++23
  std::print("Hello World! {}, {}, {}\n", 3, 411, "a");
}