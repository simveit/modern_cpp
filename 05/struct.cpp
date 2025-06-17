#include <print>

void intro_struct() {
  std::println("Test struct");

  struct Point {
    int x;
    int y;
  } p1, p2;

  p1.x = 1;
  p1.y = 2;

  p2.x = 3;
  p2.y = 4;

  std::println("p1: ({}, {})", p1.x, p1.y);
  std::println("p2: ({}, {})", p2.x, p2.y);
}

void struct_in_function(int x) {
  struct A {
    int x;
  } a;

  a.x = x;

  std::println("a: {}", a.x);
}

int main() {
  intro_struct();
  struct_in_function(10);
}
