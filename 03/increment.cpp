#include <print>

void prefix_increment() {
  int x = 1;
  int y = ++x;
  std::print("x = {}, y = {}\n", x, y);
  // x = 2, y = 1
}

void postfix_increment() {
  int x = 1;
  int y = x++;
  std::print("x = {}, y = {}\n", x, y);
  // x = 2, y = 2
}

int main() {
  prefix_increment();
  postfix_increment();
}