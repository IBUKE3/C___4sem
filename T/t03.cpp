class A {
    int n;
public:
    A(int x=7) : n(x) {};
    ~A() {};
    A& operator= (const A& c) { return *this; };
    A& operator*=(const A& t) { n*=t.n; return *this; };
    int get() { return n; };
};

