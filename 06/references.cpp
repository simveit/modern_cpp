#include <print>

void intro_references() {
  // Won't compile. A reference is an alias
  // to an already existing variable.
  // error: declaration of reference variable 'a' requires an initializer
  // int &a;
  int a = 1;
  int &b = a;

  std::println("a = {}, b = {}", a, b);

  // This won't compile. A reference may not change!
  int c = 2;
  // error: expression is not assignable
  // &b = c;

  // The reference will change as well.
  a++;
  std::println("a = {}, b = {}", a, b);
}

void f(int (&array)[3]) {};

int main() {
  intro_references();
  int A[3], B[4];
  f(A);
  // compile error, reference needs to
  // be initialised according to the signature
  // error: no matching function for call to 'f'
  // f(B);
}