#include <iostream>
#include <algorithm>
#include <vector>



using std::cout, std::cin, std::string;

void solve() {
    using T = std::vector<string>;
    T v = {};
    string s;
    while (cin >> s) {
        v.push_back(s);
    }
    std::sort(v.begin(), v.end());
    if (v.size()) {
        for (auto it = v.begin(); it != v.end()-1; it++) {
            cout << *it << " ";
        }
        cout << *(v.end()-1) << '\n';
        for (auto it = v.rbegin(); it != v.rend()-1; it++) {
            cout << *it << " ";
        }
        cout << *(v.rend()-1) << '\n';
    }
}