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
    // S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    bool EqMatrix(const S21Matrix &other) const;
    void SumMatrix(const S21Matrix &other);
    void SubMatrix(const S21Matrix &other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix &other);
    S21Matrix Transpose();
    // S21Matrix CalcComplements();
    // double Determinant();
    // S21Matrix InverseMatrix();

    size_t GetRows() const;
    void SetRows(size_t rows);

    S21Matrix &operator=(S21Matrix &other);        // net // other меняется?
    bool operator==(const S21Matrix &other) const; // net
    bool operator!=(const S21Matrix &other) const; // кидает исключение?
    double &operator()(size_t i, size_t j); //da
    S21Matrix operator+(const S21Matrix &other) const; //da
    S21Matrix &operator+=(const S21Matrix &other); //da
    S21Matrix operator-(const S21Matrix &other) const; //da
    S21Matrix &operator-=(const S21Matrix &other); //da
    S21Matrix operator*(const double num); //?
    S21Matrix operator*(const S21Matrix &other) const; //da
    S21Matrix &operator*=(const double num); //?
    S21Matrix &operator*=(const S21Matrix &other); //da

private:
    size_t rows_;
    size_t cols_;
    double **matrix_;
};

#endif // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
