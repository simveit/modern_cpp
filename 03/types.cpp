#include <iostream>
#include <print>

void size_of_void() {
  // Will throw -> error: invalid application of 'sizeof' to an incomplete type
  // 'void'
  // std::print("sizeof(void) = {}", sizeof(void));
}

void null_pointer() {
  int* p1 = NULL;
  int* p2 = nullptr;

  // warning: implicit conversion of NULL constant to 'int'
  int n1 = NULL;
  // error: a value of type "std::nullptr_t" cannot be used to initialize an
  // entity of type "int" int n2 = nullptr;

  int* p3 = true ? 0 : nullptr;

  // print will fail here
  // std::print("p1 = {}, p2 = {}, n1 = {}, p3 = {}", p1, p2, n1, p3);
  std::cout << "p1 = " << p1 << " p2 = " << p2 << " n1 = " << n1
            << " p3 = " << p3 << std::endl;
  // p1 = 0x0 p2 = 0x0 n1 = 0 p3 = 0x0
}

auto square(int x) {
  std::print("Call int\n");
  return x * x;
}
auto square(float x) {
  std::print("Call float\n");
  return x * x;
}

void f(auto x) { std::print("{}\n", sizeof(x)); }

int main() {
  // size_of_void();
  std::print("Null pointers\n");
  null_pointer();
  auto sq1 = square(2);
  auto sq2 = square(3.0f);
  std::print("sq1 = {}, sq2= {}\n", sq1, sq2);
  int x = 2;      // 4 byte
  bool y = true;  // 1 byte
  f(x);
  f(y);
}