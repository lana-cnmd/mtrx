#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols)
{
    matrix_ = new double *[rows];
    for (size_t i = 0; i < rows; ++i)
    {
        matrix_[i] = new double[cols]();
    }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(new double *[other.rows_])
{
    for (size_t i = 0; i < other.rows_; ++i)
    {
        this->matrix_[i] = new double[other.cols_]();
    }

    for (size_t i = 0; i < other.rows_; ++i)
    {
        for (size_t j = 0; j < other.cols_; ++j)
        {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

// S21Matrix::S21Matrix(S21Matrix&& other) : {}

S21Matrix::~S21Matrix()
{
    if (matrix_ != nullptr)
    {
        for (size_t i = 0; i < rows_; ++i)
        {
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }
}
