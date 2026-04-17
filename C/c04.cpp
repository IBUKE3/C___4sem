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
        for (Iterator it = first; it != last-1; it++) {
            cout << *it << " ";
        }
        cout << *(last-1) << '\n';
    }
}

bool checker(int n) {
    return (n&1)==0;
}

void solve() {
    using T = vector<int>;
    T v;
    input(v);
    T other = {};
    for (auto& elem : v) {
        if (checker(elem)) {
            other.push_back(elem);
        }
    }
    output(other.begin(), other.end());
}
