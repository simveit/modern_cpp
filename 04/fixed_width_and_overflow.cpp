#include <cstdint>
#include <iostream>
#include <limits>
#include <print>

void iostream_behavior() {
  int8_t x = 2;
  std::cout << x << ";" << x * 2 << std::endl;
  size_t y = 2;
  std::cout << y << ";" << y * 2 << std::endl;
}

void overflow() {
  int a = INT_MAX;
  std::cout << a << ";" << a + 1 << std::endl;
  int64_t one = 1;
  int64_t b = ((one << 63) - 1);
  std::cout << b << ";" << b + 1 << std::endl;
}

void query_props() {
  auto int8_min = std::numeric_limits<int8_t>::min();
  auto int8_max = std::numeric_limits<int8_t>::max();

  // Strange behavior for std::cout.
  std::print("int8 ranges from {} to {}\n", int8_min, int8_max);

  auto size_t_min = std::numeric_limits<size_t>::min();
  auto size_t_max = std::numeric_limits<size_t>::max();

  std::print("size_t ranges from {} to {}\n", size_t_min, size_t_max);

  auto uint64_t_min = std::numeric_limits<uint64_t>::min();
  auto uint64_t_max = std::numeric_limits<uint64_t>::max();

  std::print("uint64_t ranges from {} to {}\n", uint64_t_min, uint64_t_max);
}

void conversion() {
  int8_t x = 2;
  int16_t y = x;

  int16_t u = 128;
  int8_t v = u;

  std::print("x = {}, y = {}, u = {}, v = {}\n", x, y, u, v);
}

void calculation() {
  unsigned x = 32;
  x += 2u - 4;  // 2 - 4 -> 2^32 - 2
                // (32 + 2^32 - 2) = 31 + 2^32 -1 = 30 + 0 = 30
  std::print("x = {}\n", x);

  uint64_t y = 32;  // Ranges from -2^63 to 2^63 - 1
  y += 2u - 4;      // Won't wrap around -> unexpected behavior!
  std::print("y = {}\n", y);
}

int main() {
  iostream_behavior();
  overflow();
  query_props();
  conversion();
  calculation();
}