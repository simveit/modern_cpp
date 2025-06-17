#include <iostream>

void test_init() {
  std::cout << "Test init" << std::endl;

  int a = 10;
  int b{10};
  // This will compile
  unsigned c = -1;
  // This won't compile
  // constant expression evaluates to -1 which cannot be narrowed to type
  // 'unsigned int'
  // unsigned d{-1};
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
}

void test_init_struct() {
  std::cout << "Test init struct" << std::endl;

  struct S {
    unsigned x;
    unsigned y;
  };

  S s1;  // Default constructor (here not defined)
  S s2{1, 2};
  S s3{1};  // This will contain default value for y (here not defined)

  std::cout << "s1.x = " << s1.x << std::endl;
  std::cout << "s1.y = " << s1.y << std::endl;
  std::cout << "s2.x = " << s2.x << std::endl;
  std::cout << "s2.y = " << s2.y << std::endl;
  std::cout << "s3.x = " << s3.x << std::endl;
  std::cout << "s3.y = " << s3.y << std::endl;

  struct S2 {
    unsigned x = 3;
    unsigned y = 4;
  };

  S2 s4;
  S2 s5{1};

  std::cout << "s4.x = " << s4.x << std::endl;
  std::cout << "s4.y = " << s4.y << std::endl;
  std::cout << "s5.x = " << s5.x << std::endl;
  std::cout << "s5.y = " << s5.y << std::endl;

  struct S3 {
    unsigned x;
    unsigned y;
  };

  S3 s6{.x = 1, .y = 2};

  std::cout << "s6.x = " << s6.x << std::endl;
  std::cout << "s6.y = " << s6.y << std::endl;
}

int main() {
  test_init();
  test_init_struct();
}