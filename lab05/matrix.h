//
// Created by Kovacs Dani on 13.10.2025.
//

#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
    public:
        Matrix(int rows = 10, int cols = 10);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        ~Matrix() = default;

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        void fillMatrix(double value);
        void randomMatrix(int a, int b);

        void printMatrix(std::ostream& os = std::cout) const;

        bool isSquare() const {return mRows == mCols; }
        int getRows() const {return mRows;}
        int getCols() const {return mCols;}

        friend Matrix operator+(const Matrix& x, const Matrix& y);
        friend Matrix operator*(const Matrix& x, const Matrix& y);

        friend std::istream& operator>>(std::istream& is, Matrix& mat);
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

        double* operator[](int row);
        const double* operator[](int row) const;

        double& operator()(int row, int col);
        const double& operator()(int row, int col) const;
    private:
    int mRows;
    int mCols;
    std::vector<double> mElements;
};

#endif //LAB5_MATRIX_H