#include <iostream>
class F {
    int n;
public:
    F(int x = 3) : n{x<<1} { x/=(x>0? 1 : 0); };
    ~F() {std::cout << n << std::endl;};
    int combine(const F& b) const {std::cout << 16 << std::endl; return 22; };
    int get() const { return n; };
};


