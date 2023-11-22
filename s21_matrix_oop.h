#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <iostream>
#include <cmath>

class S21Matrix
{
public:
    S21Matrix();
    S21Matrix(size_t rows, size_t cols);
    S21Matrix(const S21Matrix &other);
    S21Matrix(S21Matrix &&other);
    ~S21Matrix();

    bool EqMatrix(const S21Matrix &other) const; // net
    void SumMatrix(const S21Matrix &other);      // different matrix dimensions
    void SubMatrix(const S21Matrix &other);      // different matrix dimensions
    void MulNumber(const double num);            // net
    void MulMatrix(const S21Matrix &other);      // the number of columns of the first matrix is not equal to the number of rows of the second matrix
    S21Matrix Transpose();                       // net
    // S21Matrix CalcComplements(); //the matrix is not square
    // double Determinant(); //the matrix is not square
    // S21Matrix InverseMatrix(); //matrix determinant is 0

    size_t GetRows() const;
    size_t GetCols() const;
    void SetRows(size_t newValue);
    void SetCols(size_t newValue);

    S21Matrix &operator=(const S21Matrix &other);  // net
    bool operator==(const S21Matrix &other) const; // net
    bool operator!=(const S21Matrix &other) const; // кидает исключение?
    double &operator()(size_t i, size_t j);
    S21Matrix operator+(const S21Matrix &other) const; // different matrix dimensions
    S21Matrix &operator+=(const S21Matrix &other);     // different matrix dimensions
    S21Matrix operator-(const S21Matrix &other) const; // different matrix dimensions
    S21Matrix &operator-=(const S21Matrix &other);     // different matrix dimensions
    S21Matrix operator*(const double num);             //?
    S21Matrix operator*(const S21Matrix &other) const; // the number of columns of the first matrix does not equal the number of rows of the second matrix
    S21Matrix &operator*=(const double num);           //?
    S21Matrix &operator*=(const S21Matrix &other);     // the number of columns of the first matrix does not equal the number of rows of the second matrix

private:
    size_t rows_;
    size_t cols_;
    double **matrix_;
};

#endif // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
