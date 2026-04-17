#include <iostream>
#include <algorithm>
#include <vector>



using std::cout, std::cin, std::vector;

template<typename T>
void input(T& v) {
    typename T::value_type s;
    while (cin >> s) {
        v.push_back(s);
    }
}

template<typename Iterator>
void output(Iterator first, Iterator last) {
    if (last != first) {
        for (Iterator it = first; it != last; it++) {
            cout << *it << " ";
        }
        cout <<  '\n';
    }
}

template<typename T, typename Function>
void filter(T& container, Function predicate) {
    auto it = container.begin();
    while (it != container.end()) {
        if (!predicate(*it)) {
            it = container.erase(it);
        } else {
            it++;
        }
    }
}


bool isChet(int x) {
    return x % 2 == 0;
}

void solve() {
    std::vector<int> v;
    input(v);
    filter(v, isChet);
    output(v.begin(), v.end());
}
