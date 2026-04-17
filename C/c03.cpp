#include <iostream>
#include <algorithm>
#include <vector>



using std::cout, std::cin, std::string;

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

void solve() {
    std::vector<int> v;
    input(v);
    std::sort(v.begin(), v.end());
    output(v.begin(), v.end());
    output(v.rbegin(), v.rend());
}
