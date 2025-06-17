#include <print>
#include <trait>

void const_intro() {
  const uint16_t a = 1;
  // This will throw a compiler error
  // error: cannot assign to variable 'a' with const-qualified type 'const
  // uint16_t' a++;
}

void f(const int a) {
  // This won't compile
  // error: cannot assign to variable 'a' with const-qualified type 'const int'
  // a++;
}

void pointer_and_const() {
  const int8_t SIZE{4};
  int* x = new int[SIZE];
  int* x1 = new int[SIZE];
  for (size_t i{0}; i < SIZE; i++) {
    x[i] = i;
    x1[i] = i;
  }
  const int* y = x;
  x[0] = 8;

  for (size_t i{0}; i < SIZE; i++) {
    std::println("i = {}, x[i] = {}, y[i] = {}", i, x[i], y[i]);
  }
  /*
  i = 0, x[i] = 8, y[i] = 8
  i = 1, x[i] = 1, y[i] = 1
  i = 2, x[i] = 2, y[i] = 2
  i = 3, x[i] = 3, y[i] = 3
  */
  // This won't compile
  // error: read-only variable is not assignable
  // y[0] = 3;

  // The value of the pointer can be modified.
  y = x1;

  // The elements the pointer refers to
  // be modified.
  int* const z = x;
  z[0] = 15;

  // The value of the pointer may not be modified.
  // error: cannot assign to variable 'z' with const-qualified type 'int *const'
  // z = x1;
}

void const_expr() {
  // Evaluated at compile time!
  constexpr int a = 1;
}

constexpr int square(int x) { return x * x; };

// Always evaluated at runtime because
// contains run-time arguments with a lifetime that begins with the expression,
// even if the function doesn’t depend on them
const int square2(int& x) { return x * x; };

// Can guarantuee with consteval
consteval int square3(int x) { return x * x; };

// Consteval guarantues constant arg
// So we can't modify inside
consteval int try_modify(int x) {
  x++;
  return x;
};

int main() {
  const_intro();
  f(4);
  pointer_and_const();
  const_expr();
  // Eval at runtime because arg is evaluated at compile time
  square(4);
  // Same
  constexpr int to_square = 2;
  square(to_square);
  // Not, because arg is dynamic
  int to_square_dynamic = 4;
  square(to_square);
  square2(to_square_dynamic);
  // Won't compile
  // error: call to consteval function 'square3' is not a constant expression
  // square3(to_square_dynamic);
}