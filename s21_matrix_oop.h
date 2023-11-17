#ifndef _S21_MATRIX_OOP_H  // название проекта - путь к файлу (не считая src)
#define _S21_MATRIX_OOP_H

#include <iostream>

class S21Matrix {
    public:
        S21Matrix();
        S21Matrix(size_t rows, size_t cols);
        // S21Matrix(const S21Matrix& other);
        // S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        // bool EqMatrix(const S21Matrix& other);
        // void SumMatrix(const S21Matrix& other);
        // void SubMatrix(const S21Matrix& other);
        // void MulNumber(const double num);
        // void MulMatrix(const S21Matrix& other);
        // S21Matrix Transpose();
        // S21Matrix CalcComplements();
        // double Determinant();
        // S21Matrix InverseMatrix();

    private:
        size_t rows_;
        size_t cols_;
        double **matrix_;
};

#endif //_S21_MATRIX_OOP_H
