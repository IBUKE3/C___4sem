#include <iostream>
using std::cout;

class OptInt {
    int n;
    bool flag = false;
public:
    OptInt() : n{0}, flag{false} {};
    OptInt(int x) : n{x}, flag{true}{};
    OptInt(bool f) : n{0}, flag{f} {};

    OptInt(const OptInt& x) : n(x.n), flag(x.flag) {};
    OptInt(OptInt&& x) : n(x.n), flag(x.flag) {};
    ~OptInt() {};
    OptInt operator+(const OptInt& y) const;
    OptInt& operator=(const OptInt& y);
    OptInt& operator=(OptInt&& y);
    bool isSet() const;
    friend std::ostream& operator<<(std::ostream& out, const OptInt& x);
};

bool OptInt::isSet() const {
    return flag;
}

OptInt OptInt::operator+(const OptInt& y) const {
    if (y.isSet() && flag) {
        return OptInt(n+y.n);
    } else {
        return OptInt(false);
    }
}



std::ostream& operator<<(std::ostream& out, const OptInt& x) {
    if (x.isSet()) {
        out << x.n;
    } else {
        out << "undefined";
    }
    return out;
}

OptInt& OptInt::operator=(const OptInt& y) {
    if (this == &y) {
        return *this;
    }
    n = y.n;
    flag = true;
    return *this;
}

OptInt& OptInt::operator=(OptInt &&y) {
    n = y.n;
    flag = true;
    return *this;
}


