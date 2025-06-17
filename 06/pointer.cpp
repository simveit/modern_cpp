#include <iostream>

void pointer_cast() {
  std::cout << "Test pointer cast" << std::endl;
  void *x;
  size_t y = (size_t)x;
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
}

void pointer_dereference() {
  std::cout << "Test pointer dereference" << std::endl;
  int *ptr1 = new int;
  *ptr1 = 10;
  int a = *ptr1;
  std::cout << "ptr1 = " << ptr1 << std::endl;
  std::cout << "*ptr1 = " << *ptr1 << std::endl;
  std::cout << "a = " << a << std::endl;
}

void address_operator() {
  std::cout << "Test address operator" << std::endl;
  int a = 10;
  int *ptr1 = &a;
  std::cout << "*ptr1 = " << *ptr1 << std::endl;
  std::cout << "a = " << a << std::endl;
  a++;
  std::cout << "a = " << a << std::endl;
  std::cout << "*ptr1 = " << *ptr1 << std::endl;
}

void pointer_arithmetic() {
  std::cout << "Test pointer arithmetic" << std::endl;

  int arr[4] = {1, 2, 3, 4};
  std::cout << "arr[1] = " << arr[1] << std::endl;
  std::cout << "*(arr + 1) = " << *(arr + 1) << std::endl;
  std::cout << "arr = " << arr << std::endl;
  std::cout << "arr + 1 = " << arr + 1 << std::endl;
  std::cout << "arr + 2 = " << arr + 2 << std::endl;
  std::cout << "arr + 3 = " << arr + 3 << std::endl;

  int *ptr = arr + 2;
  std::cout << "ptr[-2] = " << ptr[-2] << std::endl;
  std::cout << "ptr[-1] = " << ptr[-1] << std::endl;
  std::cout << "ptr[0] = " << ptr[0] << std::endl;
  std::cout << "ptr[1] = " << ptr[1] << std::endl;
}

void free_pointer() {
  std::cout << "Test free pointer" << std::endl;
  int *arr = new int[4];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  std::cout << "arr[0] = " << arr[0] << std::endl;
  std::cout << "arr[1] = " << arr[1] << std::endl;
  std::cout << "arr[2] = " << arr[2] << std::endl;
  std::cout << "arr[3] = " << arr[3] << std::endl;
  delete[] arr;
}

int main() {
  pointer_cast();
  pointer_dereference();
  address_operator();
  pointer_arithmetic();
  free_pointer();
}