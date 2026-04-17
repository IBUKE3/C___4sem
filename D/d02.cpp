#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using std::isalpha, std::isdigit, std::isalnum;

class DKA {
    enum State {S, I, D, Ddot, Dpostdot, N, ERROR};
public:
    bool accept(const std::string& in);
};

bool DKA::accept(const std::string& in) {
    State state = S;
    std::istringstream input(in);
    char c;
    while (state != ERROR && input.get(c)) {
        switch (state) {
            case S:
                if (isalpha(c)) state = I;
                else if (isdigit(c) && c != '0') state = D;
                else if (c == '0') state = N;
                else state = ERROR;
                break;
            case I:
                if (isalnum(c) || c=='_') state = I;
                else state = ERROR;
                break;
            case D:
                if (isdigit(c)) state = D;
                else if (c == '.') state = Ddot;
                else state = ERROR;
                break;
            case Ddot:
                if (isdigit(c)) state = Dpostdot;
                else state = ERROR;
                break;
            case Dpostdot:
                if (isdigit(c)) state = Dpostdot;
                else state = ERROR;
                break;
            case N:
                if (c == '.') state = Ddot;
                else state = ERROR;
                break;
            default:
                state = ERROR;
        }
    }
    return (state == I || state == D || state == Dpostdot || state == N);
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
