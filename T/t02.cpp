class C {
    int n;
public:
    C(int x=0) : n(x) {};
    C(const C &c) {};
    ~C() {};
    C& operator= (const C& c) { return *this; };
    C operator+(const C& c) { return C(2*(n+c.n)); };
    int get() { return n*2; };
};
