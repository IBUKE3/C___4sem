
#include <iostream>
using std::cout;

class Base {
public:
    Base() { cout << "c Base\n"; }
    Base(const Base&) { cout << "cp Base\n"; }
    ~Base() { cout << "d Base\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "c Derived\n"; }
    Derived(const Derived&) { cout << "cp Derived\n"; }
    ~Derived() { cout << "d Derived\n"; }
};


int main() {
    Derived d;
    cout << "---\n";
    Derived d1 = d;
    cout << "---\n";
    Base b1 = d;
    cout << "---\n";
    Base* pb = &d;
    cout << "---\n";
    Base& rb = d;
    cout << "---\n";
}