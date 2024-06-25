#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T, size_t N>
class Vector {
public:
    Vector() {
        data.resize(N);
    }

    Vector(std::initializer_list<T> init_list) {
        if (init_list.size() != N) {
            throw std::length_error("Initializer list size must match vector size");
        }
        data.assign(init_list);
    }

    T& operator[](size_t idx) {
        if (idx >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[idx];
    }

    const T& operator[](size_t idx) const {
        if (idx >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[idx];
    }

    size_t size() const {
        return N;
    }

    Vector<T, N> operator+(const Vector<T, N>& other) const {
        Vector<T, N> result;
        for (size_t i = 0; i < N; ++i) {
            result[i] = data[i] + other[i];
        }
        return result;
    }

    Vector<T, N> operator*(const T& scalar) const {
        Vector<T, N> result;
        for (size_t i = 0; i < N; ++i) {
            result[i] = data[i] * scalar;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vec) {
        os << "[";
        for (size_t i = 0; i < N; ++i) {
            os << vec[i];
            if (i != N - 1) os << ", ";
        }
        os << "]";
        return os;
    }

private:
    std::vector<T> data;
};

int main() {
    // Example usage
    Vector<int, 4> vec1 = {1, 2, 3, 4};
    Vector<int, 4> vec2 = {5, 6, 7, 8};
    Vector<int, 4> vecSum = vec1 + vec2;
    Vector<int, 4> vecMult = vec1 * 3;

    std::cout << "vec1: " << vec1 << std::endl;
    std::cout << "vec2: " << vec2 << std::endl;
    std::cout << "vecSum: " << vecSum << std::endl;
    std::cout << "vecMult: " << vecMult << std::endl;

    Vector<Vector<int, 4>, 4> vec2D = {
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 3, 0},
        {0, 0, 0, 4}
    };

    std::cout << "vec2D: " << std::endl;
    for (size_t i = 0; i < vec2D.size(); ++i) {
        std::cout << vec2D[i] << std::endl;
    }

    return 0;
}
