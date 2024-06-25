#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <cstdlib>
#include <iterator>

template<typename T, std::size_t n>
class vector {
private:
    T* data;

public:
    vector() {
        data = (T*)malloc(n * sizeof(T));
        if (!data) {
            throw std::bad_alloc();
        }
        for (size_t i = 0; i < n; i++) {
            new(&data[i]) T();
        }
    }

    vector(std::initializer_list<T> initList) {
        if (initList.size() > n) {
            throw std::out_of_range("Initializer list too large");
        }
        data = static_cast<T*>(std::malloc(n * sizeof(T)));
        if (!data) {
            throw std::bad_alloc();
        }
        std::size_t i = 0;
        for (const auto& item : initList) {
            new(&data[i++]) T(item);
        }
        for (; i < n; ++i) {
            new(&data[i]) T();
        }
    }

    ~vector() {
        for (std::size_t i = 0; i < n; ++i) {
            data[i].~T();
        }
        std::free(data);
    }

    T& operator[](std::size_t index) {
        if (index >= n) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= n) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    std::size_t size() const {
        return n;
    }

    class Iterator {
    private:
        T* ptr;

    public:
        explicit Iterator(T* p) : ptr(p) {}

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + n);
    }

    vector<T, n> operator+(const vector<T, n>& other) const {
        vector<T, n> result;
        for (std::size_t i = 0; i < n; ++i) {
            result[i] = data[i] + other[i];
        }
        return result;
    }

    vector<T, n> operator*(const T& scalar) const {
        vector<T, n> result;
        for (std::size_t i = 0; i < n; ++i) {
            result[i] = data[i] * scalar;
        }
        return result;
    }

    template<std::size_t m>
    friend std::ostream& operator<<(std::ostream& os, const vector<vector<T, m>, n>& vec2D);
};

template<typename T, std::size_t n>
std::ostream& operator<<(std::ostream& os, const vector<T, n>& vec) {
    os << "[";
    for (std::size_t i = 0; i < n; ++i) {
        os << vec[i];
        if (i != n - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template<typename T, std::size_t n, std::size_t m>
std::ostream& operator<<(std::ostream& os, const vector<vector<T, m>, n>& vec2D) {
    os << "[\n";
    for (std::size_t i = 0; i < n; ++i) {
        os << "  " << vec2D[i];
        if (i != n - 1) {
            os << ",\n";
        }
    }
    os << "\n]";
    return os;
}

int main() {
    // Example usage
    vector<int, 4> vec1 = {1, 2, 3, 4};
    vector<int, 4> vec2 = {5, 6, 7, 8};
    vector<int, 4> vecSum = vec1 + vec2;
    vector<int, 4> vecMult = vec1 * 3;

    std::cout << "vec1: " << vec1 << std::endl;
    std::cout << "vec2: " << vec2 << std::endl;
    std::cout << "vecSum: " << vecSum << std::endl;
    std::cout << "vecMult: " << vecMult << std::endl;

    vector<vector<int, 4>, 4> vec2D = {
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 3, 0},
        {0, 0, 0, 4}
    };

    std::cout << "vec2D: " << std::endl;
    std::cout << vec2D << std::endl;

    return 0;
}
