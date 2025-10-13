//
// Created by Kovacs Dani on 13.10.2025.
//

#include "matrix.h"
#include <algorithm>
#include <iomanip>
#include <random>

Matrix::Matrix(int rows, int cols): mRows(rows), mCols(cols), mElements(rows * cols) {}

Matrix::Matrix(const Matrix &other): mRows(other.mRows), mCols(other.mCols), mElements(other.mRows * other.mCols) {
    for (int i = 0; i < mRows * mCols; i++) {
        mElements[i] = other.mElements[i];
    }
}

Matrix::Matrix(Matrix &&other) noexcept : mRows(other.mRows), mCols(other.mCols), mElements(std::move(other.mElements)){}

Matrix & Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }
    this->mRows = other.mRows;
    this->mCols = other.mCols;
    this->mElements = other.mElements;
    return *this;
}

Matrix & Matrix::operator=(Matrix &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    this->mRows = other.mRows;
    this->mCols = other.mCols;
    this->mElements = std::move(other.mElements);
    return *this;
}

void Matrix::fillMatrix(double value) {
    std::fill(mElements.begin(), mElements.end(), value);
}

void Matrix::randomMatrix(int a, int b) {
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<double> dist(a, b);

    for (auto &elem : mElements) {
        elem = dist(mt);
    }
}

void Matrix::printMatrix(std::ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; j++) {
            os << std::setw(10)
            << std::fixed << std::setprecision(3)
            << mElements[i * mCols + j] << " ";
        }
        os << '\n';
    }
}

double *Matrix::operator[](int row) {
    return mElements.data() + row * mCols;
}

const double * Matrix::operator[](int row) const {
    return mElements.data() + row * mCols;
}

double & Matrix::operator()(int row, int col) {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[row * mCols + col];
}

const double & Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Index out of range");
    }
    return mElements[row * mCols + col];
}


std::ostream & operator<<(std::ostream &os, const Matrix &m) {
    m.printMatrix(os);
    return os;
}

Matrix operator+(const Matrix &a, const Matrix &b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        throw std::out_of_range("Matrix dimensions must match for addition.");
    }

    Matrix result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows() * a.getCols(); ++i) {
        result.mElements[i] = a.mElements[i] + b.mElements[i];
    }
    return result;
}

Matrix operator*(const Matrix &a, const Matrix &b) {
    if (a.getCols() != b.getRows()) {
        throw std::out_of_range("Matrix dimensions must match for multiplication.");
    }

    Matrix result(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < b.getCols(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < a.getCols(); ++k) {
                sum += a(i, k) * b(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}
