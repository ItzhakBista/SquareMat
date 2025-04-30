//itzhak173@gmail.com

#pragma once
#include <iostream>

namespace MatOps {

class SquareMat {
private:
    int size;
    double** data;

    void allocateMemory();
    void freeMemory();
    void copyData(const double** source);
    void checkIndices(int i, int j) const;
    void checkSameSize(const SquareMat& other) const;

public:
    // Constructors & Destructor
    SquareMat(int n);
    SquareMat(int n, double value);
    SquareMat(const SquareMat& other);
    ~SquareMat();

    // Assignment operator
    SquareMat& operator=(const SquareMat& other);

    // Binary arithmetic operators
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator%(const SquareMat& other) const; // Element-wise multiplication
    SquareMat operator*(double scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator%(int scalar) const; // Modulo with scalar

    // Unary operators
    SquareMat operator-() const;
    SquareMat operator~() const; // Transpose
    double operator!() const; // Determinant

    // Increment/decrement operators
    SquareMat& operator++(); // Prefix ++
    SquareMat operator++(int); // Postfix ++
    SquareMat& operator--(); // Prefix --
    SquareMat operator--(int); // Postfix --

    // Power operator
    SquareMat operator^(int power) const;

    // Compound assignment operators
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);

    // Comparison operators
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // Access operators
    double* operator[](int i);
    const double* operator[](int i) const;

    // I/O operator
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

    // Helper functions
    int getSize() const { return size; }
    double sum() const;
};

// Non-member operator for scalar multiplication (scalar * matrix)
SquareMat operator*(double scalar, const SquareMat& mat);

}
