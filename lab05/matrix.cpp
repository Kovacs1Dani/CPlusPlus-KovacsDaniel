//
// Created by Kovacs Dani on 13.10.2025.
//

#include "matrix.h"
#include <algorithm>
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

}

double * Matrix::operator[](int row) {
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

}


