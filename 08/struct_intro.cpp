#include <print>

struct A {
  int x{4};                         // Data member
  void f() { std::println("A"); };  // Function member
};

// Hierachy
struct B : A {
  int data{2};
  void g() { std::println("B"); };
};

void f(A a) { std::println("Pass by value"); };
void g(B b) { std::println("Pass by value"); };

void f_ref(A &a) { std::println("Pass by reference"); };
void g_ref(B &b) { std::println("Pass by reference"); };

int main() {
  std::println("Simple");

  A a{A{}};
  a.f();

  std::println("Hierachy");

  B b{B{}};
  b.g();
  b.f();

  std::println("Function call");

  f(a);
  f(b);
  g(b);

  f_ref(a);
  f_ref(b);
  g_ref(b);
}