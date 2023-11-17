#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr){}

S21Matrix::S21Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
    rows_ = rows; // для чего?
    cols_ = cols; // для чего?
    matrix_ = new double*[rows];
    for (size_t i = 0; i < rows; ++i) {
        matrix_[i] = new double[cols]();
    }
}

// S21Matrix::S21Matrix(const S21Matrix& other) : {}

// S21Matrix::S21Matrix(S21Matrix&& other) : {}

S21Matrix::~S21Matrix() {
    for (size_t i = 0; i < rows_; ++i) {
        delete[] matrix_;
    }
    delete matrix_;
    cols_ = 0; // для чего?
    rows_ = 0; // для чего?
}
