#include <climits>
#include <cstdio>

void f(int* ptr, int pos) {
  pos++;
  if (pos < 0) ptr[pos] = 0;
  // <-- the compiler could assume that signed overflow never
  return;  // happen and "simplify" the condition to check
}

int main() {               // the code compiled with optimizations, e.g. -O3
  int* tmp = new int[10];  // leads to segmentation faults with clang, while
  printf("%d\n", tmp[0]);
  f(tmp, INT_MAX);  // it terminates correctly with gcc
  printf("%d\n", tmp[0]);
}