#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <iostream>

class S21Matrix
{
public:
    S21Matrix();
    S21Matrix(size_t rows, size_t cols);
    S21Matrix(const S21Matrix &other);
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

    S21Matrix &operator=(S21Matrix other)
    {
        // S21Matrix copy = other;
        // std::swap(copy);
        // return *this;
        std::swap(other.rows_, rows_);
        std::swap(other.cols_, cols_);
        std::swap(other.matrix_, matrix_);
        return *this;
    }

    // S21Matrix &operator=(const S21Matrix &other)
    // {
    //     if (&other == this)
    //         return *this;

    //     if (matrix_ != nullptr)
    //     {
    //         for (size_t i = 0; i < rows_; ++i)
    //         {
    //             delete[] matrix_[i];
    //         }
    //         delete[] matrix_;
    //     }

    //     rows_ = other.rows_;
    //     cols_ = other.cols_;
    //     matrix_ = new double *[rows_];
    //     for (size_t i = 0; i < rows_; ++i)
    //     {
    //         matrix_[i] = new double[cols_];
    //     }

    //     for (size_t i = 0; i < rows_; ++i)
    //     {
    //         for (size_t j = 0; j < cols_; ++j)
    //         {
    //             matrix_[i][j] = other.matrix_[i][j];
    //         }
    //     }
    //     return *this;
    // }

private:
    size_t rows_;
    size_t cols_;
    double **matrix_;
};

#endif // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
