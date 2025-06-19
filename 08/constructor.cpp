#include <iostream>

struct A {
  A() { std::cout << "Init" << std::endl; };
};

struct B {
  int x, y;

  B(int x_, int y_) {
    x = x_;
    y = y_;
  };
};

B add(B b1, B b2) { return B(b1.x + b2.x, b1.y + b2.y); }

int main() {
  std::cout << "Init A" << std::endl;
  A a;

  std::cout << "Init B" << std::endl;
  B b(3, 4);
  std::cout << "b.x = " << b.x << " b.y = " << b.y << std::endl;

  B b1(1, 1);
  B b2(2, 2);

  auto b3 = add(b1, b2);
  std::cout << "b3.x = " << b3.x << " b3.y = " << b3.y << std::endl;

  auto b4 = add({10, 10}, {20, 20});
  std::cout << "b4.x = " << b4.x << " b4.y = " << b4.y << std::endl;
}