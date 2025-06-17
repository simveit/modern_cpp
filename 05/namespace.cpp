#include <iostream>

namespace ns1 {
void f() { std::cout << "Hello from namespace 1!" << std::endl; }
}  // namespace ns1

namespace ns2 {
void f() { std::cout << "Hello from namespace 2!" << std::endl; }
}  // namespace ns2

int main() {
  ns1::f();
  ns2::f();
}