#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) // тут выделяешь память в теле конструктора
{
    matrix_ = new double *[rows];
    for (size_t i = 0; i < rows; ++i)
    {
        matrix_[i] = new double[cols]();
    }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(new double *[other.rows_]) // тут выделяешь память в списке инициализации
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

S21Matrix &S21Matrix::operator=(S21Matrix &other)
{
    // S21Matrix copy = other;
    // std::swap(copy);
    // return *this;
    std::swap(other.rows_, rows_);
    std::swap(other.cols_, cols_);
    std::swap(other.matrix_, matrix_);
    return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const
{
    return EqMatrix(other);
}

bool S21Matrix::operator!=(const S21Matrix &other) const
{
    return !(*this == other);
}

double &S21Matrix::operator()(size_t i, size_t j)
{
    return matrix_[i][j];
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        return false;
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            if (fabs(matrix_[i][j] - other.matrix_[i][j] > 1.e-7))
                return false;
        }
    }
    return true;
}