#include <iostream>
#include <stdexcept>
#include <cstdlib>  // for malloc and free
#include <initializer_list>  // for std::initializer_list

template <typename T>
class Vector {
private:
    T* data;
    std::size_t size;

public:
    // Constructor
    Vector(std::size_t size) : size(size) {
        data = static_cast<T*>(std::malloc(size * sizeof(T)));
        if (!data) {
            throw std::bad_alloc();
        }
        for (std::size_t i = 0; i < size; ++i) {
            new(&data[i]) T();  // placement new to call default constructor
        }
    }

    // Initializer list constructor
    Vector(std::initializer_list<T> initList) : size(initList.size()) {
        data = static_cast<T*>(std::malloc(size * sizeof(T)));
        if (!data) {
            throw std::bad_alloc();
        }
        std::size_t i = 0;
        for (const auto& item : initList) {
            new(&data[i++]) T(item);
        }
    }

    // Destructor
    ~Vector() {
        for (std::size_t i = 0; i < size; ++i) {
            data[i].~T();
        }
        std::free(data);
    }

    // Access elements with bounds checking
    T& operator[](std::size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Const version of element access
    const T& operator[](std::size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Size of the vector
    std::size_t getSize() const {
        return size;
    }

    // Iterator class
    class Iterator {
    private:
        T* ptr;
    public:
        explicit Iterator(T* p) : ptr(p) {}
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    // Const Iterator class
    class ConstIterator {
    private:
        const T* ptr;
    public:
        explicit ConstIterator(const T* p) : ptr(p) {}
        ConstIterator& operator++() { ++ptr; return *this; }
        ConstIterator operator++(int) { ConstIterator tmp = *this; ++ptr; return tmp; }
        const T& operator*() const { return *ptr; }
        const T* operator->() const { return ptr; }
        bool operator==(const ConstIterator& other) const { return ptr == other.ptr; }
        bool operator!=(const ConstIterator& other) const { return ptr != other.ptr; }
    };

    // Begin and end methods for iterator
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    // Begin and end methods for const iterator
    ConstIterator begin() const { return ConstIterator(data); }
    ConstIterator end() const { return ConstIterator(data + size); }
};

int main() {
    std::size_t rows, cols;

    // Reading the size of the 2D vector from the user
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Create a 2D Vector of integers
    Vector<Vector<int>> vec(rows);
    for (std::size_t i = 0; i < rows; ++i) {
        vec[i] = Vector<int>(cols);
    }

    // Initialize the 2D Vector
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            vec[i][j] = static_cast<int>(i * cols + j);
        }
    }

    // Print values
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
