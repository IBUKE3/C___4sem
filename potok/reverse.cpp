#include <iostream>

using std::cout, std::cin, std::endl;

class A {
    unsigned long long n;
    static bool last_el; // using static here specially
    // since there is only one last element, it is enough for only one flag for all objects
public:
    A();
    ~A();
};

A::A() {
    if (cin >> n) {
        A a;
    } else {
        last_el = true; // have reached the last element
    }
}

A::~A() {
    if (last_el) {
        last_el = false; // the next element to be destructed will not be the last element
    } else {
        cout << n << ' ';
    }
}

bool A::last_el = false;


int main() {
    {A a;}
    cout << endl;
}