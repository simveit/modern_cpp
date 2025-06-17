#include <iostream>

enum color_t { BLACK, GREEN, BLUE };
enum fruit_t { APPLE, BANANA };

enum class Color { RED, GREEN, BLUE };
enum class Fruit { APPLE, BANANA };

void enums() {
  std::cout << "Test enums" << std::endl;

  color_t color = BLACK;
  fruit_t fruit = APPLE;

  std::cout << "color: " << color << std::endl;  // color: 0
  std::cout << "fruit: " << fruit << std::endl;  // fruit: 0

  bool equal = color == fruit;
  // warning: comparison of different enumeration types ('color_t' and
  // 'fruit_t') is deprecated will print 1 in c++23
  std::cout << "equal: " << equal << std::endl;
}

void enum_class() {
  std::cout << "Test enum class" << std::endl;

  Color red = Color::RED;
  Color green = Color::GREEN;
  Fruit fruit = Fruit::APPLE;

  // Comparison between the same enum class is allowed
  std::cout << (red == green) << std::endl;

  // This won't compile.
  // std::cout << (red == fruit) << std::endl;

  int red_int = (int)red;
  int fruit_int = (int)fruit;

  std::cout << (red_int == fruit_int) << std::endl;
}

void enum_switch() {
  std::cout << "Test enum switch" << std::endl;

  Color red = Color::RED;

  switch (red) {
    using enum Color;
    case RED:
      std::cout << "Red" << std::endl;
      break;
    case GREEN:
      std::cout << "Green" << std::endl;
      break;
    case BLUE:
      std::cout << "Blue" << std::endl;
      break;
    default:
      std::cout << "Unknown" << std::endl;
      break;
  }
}

int main() {
  enums();
  enum_class();
  enum_switch();
}