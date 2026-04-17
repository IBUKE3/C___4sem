#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using std::isalpha, std::isdigit, std::isalnum;

class DKA {
    enum State {S, A, B, C, ERROR};
public:
    bool accept(const std::string& in);
};

bool DKA::accept(const std::string& in) {
    State state = S;
    std::istringstream input(in);
    char c;
    int count = 0;
    while (state != ERROR && input.get(c)) {
        switch (state) {
            case S:
                if (c == 'a') state = A;
                else state = ERROR;
                break;
            case A:
                if (c == 'b') state = B;
                else state = ERROR;
                break;
            case B:
                if (c == 'a') {state = B; count++;} // можно было не менять, но так прозрачнее
                else if (c == 'b') {state = C; count--;}
                else state = ERROR;
                break;
            case C:
                if (c == 'b') {state = C; count--;}
                else state = ERROR;
                break;
            default:
                state = ERROR;
        }
    }
    return (state == B || state == C) && (count == 0);
}

int main() {
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