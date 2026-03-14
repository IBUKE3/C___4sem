#include <iostream>

class X {
public:
    X(int) { }
    operator int() { return 5; }
};

void f(double x, const char* c = nullptr) {}

void f(char c, char b) {}

void g(int n, const char* s) {}

void g(const char* s) {}
