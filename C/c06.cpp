#include <iostream>
#include <algorithm>
#include <vector>



using std::cout, std::cin, std::vector;

template<typename T>
void inputN(T& container, typename T::size_type N) {
    typename T::value_type s;
    for (typename T::size_type i = 0; i < N; i++) {
        cin >> s;
        container.insert(container.end(), s);
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
