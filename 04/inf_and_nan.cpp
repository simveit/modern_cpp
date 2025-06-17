#include <iostream>
#include <limits>
#include <print>

void inf() {
  std::cout << 5.0 / 0.0 << std::endl;
  std::cout << -5.0 / 0.0 << std::endl;
  std::cout << (-0.0 == 0.0) << std::endl;
  std::cout << ((5.0 / 0.0) == (6.0 / 0.0)) << std::endl;
}

void nan() {
  std::cout << 0 / 0 << std::endl;  // warning: division by zero is undefined
  std::cout << 0.0 / 0.0 << std::endl;  // nan
}

int main() {
  inf();
  nan();
}