#include <algorithm>
#include <print>

struct Descending {
  bool operator()(int a, int b) { return a > b; }
};

struct Ascending {
  bool operator()(int a, int b) { return a < b; }
};

void f(int(lambda_func)(int a, int b)) {
  std::println("lambda_func(2, 3) = {}", lambda_func(2, 3));
}

int main() {
  int array[] = {8, 4, 7, 9};

  // Use functor
  std::sort(array, array + 4, Descending{});
  std::println("{}, {}, {}, {}", array[0], array[1], array[2], array[3]);

  // use functor
  std::sort(array, array + 4, Ascending{});
  std::println("{}, {}, {}, {}", array[0], array[1], array[2], array[3]);

  // use named lambda
  auto lambda = [](int a, int b) { return a > b; };

  std::sort(array, array + 4, lambda);
  std::println("{}, {}, {}, {}", array[0], array[1], array[2], array[3]);

  // provide lambda to arg
  std::sort(array, array + 4, [](int a, int b) { return a < b; });
  std::println("{}, {}, {}, {}", array[0], array[1], array[2], array[3]);

  // Capture arguments with lambda
  int limit = 7;

  // Capture all variables by value
  auto lambda1 = [=](int a) { return a > limit; };
  // Capture all variables by reference
  auto lambda2 = [&](int a) { return a > limit; };
  // Capture limit by value
  auto lambda3 = [limit](int a) { return a > limit; };
  // Capture limit by reference
  auto lambda4 = [&limit](int a) { return a > limit; };

  auto found1 = std::find_if(array, array + 4, lambda1);
  std::println("with lambda1 = {}", *found1);
  auto found2 = std::find_if(array, array + 4, lambda2);
  std::println("with lambda2 = {}", *found2);
  auto found3 = std::find_if(array, array + 4, lambda3);
  std::println("with lambda3 = {}", *found3);
  auto found4 = std::find_if(array, array + 4, lambda4);
  std::println("with lambda4 = {}", *found4);

  auto lambda_for_func = [](int a, int b) { return a * b; };
  f(lambda_for_func);
}