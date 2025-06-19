#include <print>

// Call by value
int f_v(int a, int b) { return a + b; }

// Call by pointer
int f_p(int *a, int *b) { return *a + *b; }

// Call by reference (use this most of the time)
int f_r(int &a, int &b) { return a + b; }

int main() {
  int a = 1;
  int b = 2;
  int *a_ptr;
  int *b_ptr;
  a_ptr = &a;
  b_ptr = &b;

  std::println("f_v = {}, f_p = {}, f_r = {}", f_v(a, b), f_p(a_ptr, b_ptr),
               f_r(a, b));
}