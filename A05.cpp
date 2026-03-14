#include  <iostream>

using std::cout, std::endl;

class UniqueCharPtr {
    char* cp;
public:
    UniqueCharPtr(char* p = nullptr) : cp(p) {};
    UniqueCharPtr(const UniqueCharPtr&) = delete;
    UniqueCharPtr(UniqueCharPtr&& b);
    UniqueCharPtr& operator= (UniqueCharPtr&& b);
    //UniqueCharPtr operator= (const UniqueCharPtr& b) = delete;
    ~UniqueCharPtr();
    operator char* ();
};

UniqueCharPtr::UniqueCharPtr(UniqueCharPtr &&b) : cp(b.cp) {
    b.cp = nullptr;
}

UniqueCharPtr::~UniqueCharPtr() {
    if (cp) { delete [] cp; }
}

UniqueCharPtr& UniqueCharPtr::operator=(UniqueCharPtr&& b) {
    std::swap(cp, b.cp);
    return *this;
}

UniqueCharPtr::operator char* () {
    return cp;
}



