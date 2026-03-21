#include <iostream>


using std::cout, std::endl;

class IntArray {
    int size;
    int* start;
public:
    IntArray(int sz);
    IntArray(const IntArray& other);
    IntArray& operator= (const IntArray& other);
    IntArray(IntArray&& other);
    IntArray& operator= (IntArray&& other);
    int& operator[] (int i);
    const int& operator[] (int i) const;
    friend std::ostream& operator<<(std::ostream& out, const IntArray& ar);
    ~IntArray();
};


IntArray::IntArray(int sz) : size{sz} {
    start = new int[size];
}

IntArray::IntArray(const IntArray &other) : size{other.size} {
    start = new int[size];
    std::copy(other.start, other.start + size, start);
}

IntArray& IntArray::operator= (const IntArray& other) {
    if (this != &other) {
        delete[] start;
        size = other.size;
        std::copy(other.start, other.start + size, start);
    }
    return *this;
}


IntArray::IntArray(IntArray &&other) : size{other.size}, start{other.start} {
    other.size = 0;
    other.start = nullptr;
}


IntArray& IntArray::operator=(IntArray &&other) {
    if (this != &other) {
        std::swap(size, other.size);
        std::swap(start, other.start);
    }
    return *this;
}


int& IntArray::operator[] (int i) {
    if (i >= 0) {
        if (i >= size) {
            cout << "Out of bounds\n";
            exit(0);
        }
        return start[i];
    } else {
        if (-i > size) {
            cout << "Out of bounds\n";
            exit(0);
        } else {
            return start[size + i];
        }
    }
}


const int& IntArray::operator[] (int i) const {
    if (i >= 0) {
        if (i >= size) {
            cout << "Out of bounds\n";
            exit(0);
        }
        return start[i];
    } else {
        if (-i > size) {
            cout << "Out of bounds\n";
            exit(0);
        } else {
            return start[size + i];
        }
    }
}


std::ostream& operator<<(std::ostream& out, const IntArray& ar) {
    for (int i = 0; i < ar.size - 1; i++) {
        out << ar[i] << ' ';
    }
    out << ar[ar.size-1];
    return out;
}


IntArray::~IntArray() {
    delete[] start;
}

