#include <iostream>

using std::cout;


class DynArray {
    int size;
    int capacity;
    int *start;
public:
    DynArray() : size{0}, capacity{0}, start{nullptr}  {};
    DynArray(const DynArray& other);
    DynArray& operator= (const DynArray& other);
    DynArray(DynArray&& other);
    DynArray& operator= (DynArray&& other);
    void resize(int last_index);
    int length() const;
    int& operator[] (int i);
    const int& operator[] (int i) const;
    friend std::ostream& operator<<(std::ostream& out, const DynArray& ar);
    ~DynArray();
};

DynArray::DynArray(const DynArray &other) : size{other.size}, capacity{other.capacity} {
    if (other.start) {
        start = new int[capacity];
        std::copy(other.start, other.start + capacity, start);
    } else {
        start = nullptr;
    }
}

DynArray& DynArray::operator= (const DynArray& other) {
    if (this != &other) {
        delete[] start;
        size = other.size;
        capacity = other.capacity;
        std::copy(other.start, other.start + capacity, start);
    }
    return *this;
}


DynArray::DynArray(DynArray &&other) : size{other.size}, capacity{other.capacity}, start{other.start} {
    other.size = 0;
    other.capacity = 0;
    other.start = nullptr;
}


DynArray& DynArray::operator=(DynArray &&other) {
    if (this != &other) {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        std::swap(start, other.start);
    }
    return *this;
}

void DynArray::resize(int last_index) {
    int new_size = last_index + 1;
    if (new_size <= capacity) {
        for (int i = size; i < new_size; i++) {
            start[i] = 0;
        }
        return;
    } else {
        int new_capacity;
        if (capacity) {
            new_capacity = capacity;
        } else {
            new_capacity = 1;
        }
        while (new_capacity < new_size) {
            new_capacity *= 2;
        }
        int* new_start = new int[new_capacity]();
        std::copy(start, start+capacity, new_start);
        delete[] start;
        start = new_start;
        capacity = new_capacity;
        size = new_size;
    }


}


int& DynArray::operator[] (int i) {
    if (i >= size) {
        resize(i);
    }
    return start[i];
}


const int& DynArray::operator[] (int i) const {
    if (i >= size) {
        cout << "Out of bounds\n";
        exit(0);
    }
    return start[i];
}


std::ostream& operator<<(std::ostream& out, const DynArray& ar) {
    if (!ar.start) {
        return out;
    } else {
        for (int i = 0; i < ar.size - 1; i++) {
            out << ar[i] << ' ';
        }
        out << ar[ar.size-1];
        return out;
    }
}

int DynArray::length() const {
    return size;
}

DynArray::~DynArray() {
    delete [] start;
}
