#include <print>

// public: No restriction (function members, derived classes, outside the class)
// protected: Function members and derived classes access
// private: Function members only access (internal)

struct A {
 public:
  void f1() { std::println("f1"); };  // This is the default for structs
 protected:
  void f2() { std::println("f2"); };

 private:
  void f3() { std::println("f3"); };  // This is the default for classes
};

struct B : A {
  void h1() { f1(); };  // Ok
  void h2() { f2(); };
  // void h3() { f3(); }; // This won't compile
};

int main() {
  B b{B{}};

  b.h1();
}