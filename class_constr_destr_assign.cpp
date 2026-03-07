#include <iostream>
#include <map>

class A {
    static int n;
    static std::map<const A*, int> objects;
public:
    A();
    A(int);
    A(const A&);
    A(A&&);
    ~A();
    A& operator=(const A&);
    A& operator=(A&&);

    int c{315};
};

int A::n = 0;
std::map<const A*, int> A::objects;

A::A() {
    std::cout << "#" << ++n << " A::A()\n";
    objects[this] = n;
}
A::A(int) {
    std::cout << "#" << ++n << " A::A(int)\n";
    objects[this] = n;
}
A::A(const A& a) {
    std::cout << "#" << ++n << " A::A(const A&) copy #" << objects[&a] << "\n";
    objects[this] = n;
}
A::A(A&& a) {
    std::cout << "#" << ++n << " A::A(A&&) move #" << objects[&a] << "\n";
    objects[this] = n;
}
A::~A() {
    std::cout << "#" << objects[this] << " ~A()\n";
    objects[this] = 0;
}
A& A::operator=(const A& a) {
    std::cout << "#" << objects[this] << " = copy #" << objects[&a] << "\n";
    return *this;
}
A& A::operator=(A&& a) {
    std::cout << "#" << objects[this] << " = move #" << objects[&a] << "\n";
    return *this;
}

void local_variables() {
    std::cout << "\n~~~~~ " << __func__ << '\n';
    A a;
    A b = 1;
    A c = b;

    A d = A();
    A e = A(1);
    A f = A(a);

    A g{};
    A h{1};
    A i{a};
}

void dynamic_memory() {
    std::cout << "\n~~~~~ " << __func__ << '\n';
    A* a = new A;
    delete a;
    A* b = new A(1);
    A *c = new A(*b);
    delete b;
    delete c;
}

void arrays() {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    A m[2];
    A n[] = { *m, *(m+1), 3, A() };
}

void dynamic_arrays() {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    A* arr = new A[3];
    delete [] arr;
    // delete arr;
    // free(): invalid pointer
    // Аварийный останов      (образ памяти сброшен на диск) ./a.out

    // массивы в динамической памяти можно инициализировать только конструкторами умолчания
}

void f1(A a = 3) {
    std::cout << "inside void f1(A a = 3)\n";
}

void function_argument() {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    A a;
    f1(A());
    f1();
    f1(a);
}

A f21() {
    std::cout << "inside A f21()\n";
    return 1;
}
A f22() {
    std::cout << "inside A f22()\n";
    return A(1);
}
A f23() {
    std::cout << "inside A f23()\n";
    return A();
}

void function_return() {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    f21();
    A a = f22();
    f23();
}

A func1() {
    return A(5); // RVO
}

A func2() {
    A x{1};
    x.c++;
    return x; // NRVO
}

// NRVO не применимо, потому что есть ветвление,
// функция НЕ возвращает всегда один и тот же объект
A func3(const A& b) {
    A a1{3};
    A a2{4};
    if (b.c % 2 == 0)
        return a1; // xvalue (expiring value)
    else
        return a2; // xvalue (expiring value)
}

void function_return_local() {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    A a = func1(); // RVO
    std::cout << "~~~~~\n";

    A b = func2(); // NRVO
    std::cout << "~~~~~\n";

    A c{func2()};
    std::cout << "~~~~~\n";

    A d{A(func2())};
    std::cout << "~~~~~\n";

    A e{A(A(A(func2())))};
    std::cout << "~~~~~\n";

    A f = func3(b);
    std::cout << "~~~~~\n";
}

class B {
    A a{34};
public:
    B() { a = 5; }
    B(int val) : a{val} { } 
};

void aggregate_object() {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    B b{};
    B c{5};
}

void swap(A& a, A& b) {
    std::cout << "\n~~~~~ " << __func__ << '\n';

    A tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main() {
    /*
    local_variables();
    dynamic_memory();
    arrays();
    dynamic_arrays();
    aggregate_object();
    function_argument();
    function_return();
    function_return_local();


    std::cout << "\n~~~~~ " << __func__ << '\n';

    A x{4}, y{7};
    swap(x, y);*/
    A c;
    c = 2;
    A d{c};
}
