class B {
    static int n;
public:
    B(int x=0){};
    B(const B &b){};
    ~B() {};
    B& operator= (const B &b) { return *this; };
    B operator+ (const B &b) const;
    int get() const {n+=10; return n;};

};

int B::n = 0;
