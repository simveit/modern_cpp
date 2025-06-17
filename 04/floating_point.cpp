#include <iostream>
#include <limits>

template <typename T>
void properties() {
  std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
  std::cout << "lowest: " << std::numeric_limits<T>::lowest() << std::endl;
  std::cout << "min: " << std::numeric_limits<T>::min() << std::endl;
  std::cout << "denorm_min: " << std::numeric_limits<T>::denorm_min()
            << std::endl;
  std::cout << "epsilon: " << std::numeric_limits<T>::epsilon() << std::endl;
  std::cout << "infinity: " << std::numeric_limits<T>::infinity() << std::endl;
  std::cout << "quiet_NaN: " << std::numeric_limits<T>::quiet_NaN()
            << std::endl;
  std::cout << std::endl;
}

int main() {
  std::cout << "Float" << std::endl;
  properties<float>();
  std::cout << "Double" << std::endl;
  properties<double>();
}