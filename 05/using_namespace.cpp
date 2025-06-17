#include <iostream>

namespace my_namespace {
void f() { std::cout << "Hello from my_namespace!" << std::endl; }
using T = int;
}  // namespace my_namespace

int main() {
  using my_namespace::f;
  using my_namespace::T;
  f();
  T x = 10;
  std::cout << x << std::endl;
}