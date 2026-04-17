#include <iostream>
#include <sstream>
#include <string>


class DKA {
    enum State {q0, q1, q2, q3, ERROR};
    public:
        bool accept(const std::string& in);
};


bool DKA::accept(const std::string& in) {
    State state = q0;
    std::istringstream input(in);
    char c;
    while (state != ERROR && input.get(c)) {
        switch (state) {
            case q0:
                if (c == '1') state = q1;
                else if (c == '0') state = q2;
                else state = ERROR;
                break;
            case q1:
                if (c == '1') state = q0;
                else if (c == '0') state = q3;
                else state = ERROR;
                break;
            case q2:
                if (c == '1') state = q3;
                else if (c == '0') state = q0;
                else state = ERROR;
                break;
            case q3:
                if (c == '1') state = q2;
                else if (c == '0') state = q1;
                else state = ERROR;
                break;
            default:
                state = ERROR;
        }
    }
    return state == q0;
}

int solve() {
    DKA g;

    std::string str;
    while (std::cin >> str) {
        if (g.accept(str))
            std::cout << "OK: ";
        else
            std::cout << "ERROR: ";
        std::cout << str << std::endl;
    }
}
