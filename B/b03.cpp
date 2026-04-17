#include <iostream>
#include <string>
#include <set>

using std::cout, std::cin, std::endl, std::string;

class ChainGenerator {
    std::set<std::string> chains;
    const size_t MAX_LEN = 12;
    size_t N;
    // ...
public:
    ChainGenerator(size_t);
    void generate();
    void print() const;
    size_t size() const;
    void check_N(size_t) const;
};


void ChainGenerator::check_N(size_t N0) const {
    if ((N0 > MAX_LEN)) {
        throw std::out_of_range("Invalid max size of chains");
    }
}

ChainGenerator::ChainGenerator(size_t N0) {
    check_N(N0);
    chains = {};
    if (N0 != 0) {
        N = N0;
        generate();
    }
}

void ChainGenerator::generate() {
    string s;
    bool flag;
    int prev;
    int pos;
    if (N==0) {
        return;
    }
    for (int Ni = 1; Ni <= int(N); Ni++) {
        int max_n = 1 << Ni;
        int t;
        for (int j = 0; j < max_n; j++) {
            s = "";
            t = j;
            for (int k = 0; k < Ni; k++) {
                s = char(int(t&1) + '0') + s;
                t = t >> 1;
            }

            /*
            //cout << i << max_n;
            cur = i & 1;
            //s += cur + '0';
            pos = 0;
            while ((!cur) && i) {
                i >>= 1;
                cur = i & 1;
                //s += cur + '0';
                pos++;
            }
            if (i) {
                prev = pos;
                i >>= 1;
                cur = i & 1;
                pos++;
                while ((!cur) && i) {
                    i >>= 1;
                    cur  = i & 1;
                    //s += char(cur) + '0';
                    pos++;
                    if (cur && i) {
                        if ((pos - prev) % 2 == 1) {
                            flag = false;
                            break; // между двумя единицами нечетное число нулей
                        } else {
                            prev = pos;
                        }
                    }
                }
            }
            if (flag) {
                chains.insert(s);
            }
            //cout << s << endl;*/
            flag = true;
            prev = -1;
            for (pos = 0; pos < int(s.size()); pos++) {
                if (s[pos] == '1') {
                    if (prev == -1) {
                        prev = pos;
                    } else {
                        if (!((pos - prev) & 1)) {
                            //cout << "----" << s << pos << prev << " ";
                            flag = false;
                        } else {
                            prev = pos;
                        }
                    }
                }
            }
            if (flag) {
                chains.insert(s);
            }

        }
    }
}


void ChainGenerator::print() const {
    if (chains.size()) {
        for (auto elem : chains) {
            cout << elem << '\n';
        }
    }
    cout << "Number of chains = " << chains.size() << '\n';
}

size_t ChainGenerator::size() const {
    return chains.size();
}

int solve() {
    int n;
    cin >> n;
    try {
        ChainGenerator c = ChainGenerator(n);
        c.print();
    } catch (std::out_of_range& e) {
        cout << "ERROR: " << e.what() << '\n';
    }
}
