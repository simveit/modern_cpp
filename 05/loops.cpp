#include <print>
#include <vector>

void plain_for(size_t x) {
  std::println("Test plain for");

  for (size_t i = 1; i <= x; i++) {
    std::print("i: {}; ", i);
  }
  std::println("");
}

void init_list() {
  std::println("Test init list");

  for (size_t i : {1, 2, 3, 4, 5}) {
    std::print("i: {}; ", i);
  }
  std::println("");
}

void loop_array() {
  std::println("Test loop array");

  int arr[] = {1, 2, 3, 4, 5};
  for (int i : arr) {
    std::print("i: {}; ", i);
  }
  std::println("");
}

void loop_string() {
  std::println("Test loop string");

  for (auto c : "ABC") {
    std::print("c: {}; ", c);
  }
  std::println("");
}

void loop_vec() {
  std::println("Test loop vector");

  std::vector<int> vec = {1, 2, 3, 4, 5};
  for (auto i : vec) {
    std::print("i: {}; ", i);
  }
  std::println("");
}

void loop_struct_arr() {
  std::println("Test loop struct array");

  struct Point {
    int x;
    int y;
  };

  Point arr[] = {{1, 2}, {3, 4}, {5, 6}};
  for (auto p : arr) {
    std::print("p: ({}, {}); ", p.x, p.y);
  }
  std::println("");
}

int main() {
  plain_for(5);
  init_list();
  loop_array();
  loop_string();
  loop_vec();
  loop_struct_arr();
}