//itzhak173@gmail.com

#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace MatOps {

// Helper function to calculate determinant recursively
double determinant(double** mat, int n);

void SquareMat::allocateMemory() {
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
    }
}

void SquareMat::freeMemory() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void SquareMat::copyData(const double** source) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = source[i][j];
        }
    }
}

void SquareMat::checkIndices(int i, int j) const {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        throw std::out_of_range("Matrix index out of range");
    }
}

void SquareMat::checkSameSize(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
}

// Constructors
SquareMat::SquareMat(int n) : size(n) {
    if (n <= 0) {
        throw std::invalid_argument("Matrix size must be positive");
    }
    allocateMemory();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0.0;
        }
    }
}

SquareMat::SquareMat(int n, double value) : size(n) {
    if (n <= 0) {
        throw std::invalid_argument("Matrix size must be positive");
    }
    allocateMemory();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = value;
        }
    }
}

SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
    allocateMemory();
    copyData(const_cast<const double**>(other.data));
}

SquareMat::~SquareMat() {
    freeMemory();
}

// Assignment operator
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        freeMemory();
        size = other.size;
        allocateMemory();
        copyData(const_cast<const double**>(other.data));
    }
    return *this;
}

// Binary arithmetic operators
SquareMat SquareMat::operator+(const SquareMat& other) const {
    checkSameSize(other);
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    checkSameSize(other);
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    checkSameSize(other);
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    checkSameSize(other);
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = fmod(data[i][j], scalar);
        }
    }
    return result;
}

// Unary operators
SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = -data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

double SquareMat::operator!() const {
    return determinant(data, size);
}

// Increment/decrement operators
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat temp(*this);
    ++(*this);
    return temp;
}

SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            --data[i][j];
        }
    }
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat temp(*this);
    --(*this);
    return temp;
}

// Power operator
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Negative power not supported");
    }
    if (power == 0) {
        // Return identity matrix
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i][i] = 1.0;
        }
        return result;
    }
    
    SquareMat result(*this);
    for (int i = 1; i < power; ++i) {
        result = result * (*this);
    }
    return result;
}

// Compound assignment operators
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    *this = *this + other;
    return *this;
}

SquareMat& SquareMat::operator-=(const SquareMat& other) {
    *this = *this - other;
    return *this;
}

SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this * other;
    return *this;
}

SquareMat& SquareMat::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

SquareMat& SquareMat::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

SquareMat& SquareMat::operator%=(const SquareMat& other) {
    *this = *this % other;
    return *this;
}

SquareMat& SquareMat::operator%=(int scalar) {
    *this = *this % scalar;
    return *this;
}

// Comparison operators
bool SquareMat::operator==(const SquareMat& other) const {
    if (size != other.size) return false;
    return sum() == other.sum();
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    return sum() < other.sum();
}

bool SquareMat::operator>(const SquareMat& other) const {
    return sum() > other.sum();
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return sum() <= other.sum();
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return sum() >= other.sum();
}

// Access operators
double* SquareMat::operator[](int i) {
    checkIndices(i, 0); // Only check row index
    return data[i];
}

const double* SquareMat::operator[](int i) const {
    checkIndices(i, 0); // Only check row index
    return data[i];
}

// I/O operator
std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        os << "[ ";
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j] << " ";
        }
        os << "]" << std::endl;
    }
    return os;
}

// Helper functions
double SquareMat::sum() const {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            total += data[i][j];
        }
    }
    return total;
}

// Non-member operator for scalar multiplication (scalar * matrix)
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

// Helper function to calculate determinant recursively
double determinant(double** mat, int n) {
    if (n == 1) {
        return mat[0][0];
    }
    
    double det = 0.0;
    double** submat = new double*[n-1];
    for (int i = 0; i < n-1; ++i) {
        submat[i] = new double[n-1];
    }
    
    for (int c = 0; c < n; ++c) {
        int subi = 0;
        for (int i = 1; i < n; ++i) {
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == c) continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += (c % 2 == 0 ? 1 : -1) * mat[0][c] * determinant(submat, n-1);
    }
    
    for (int i = 0; i < n-1; ++i) {
        delete[] submat[i];
    }
    delete[] submat;
    
    return det;
}

}