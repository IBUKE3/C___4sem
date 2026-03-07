class A {
    static int x;
public:
    A() {};
    void f() { x++; }
    static int get() {return x;};
};

