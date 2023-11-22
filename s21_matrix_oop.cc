#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), matrix_(new double *[rows])
{
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

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_)
{
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
}

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

bool S21Matrix::EqMatrix(const S21Matrix &other) const
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        return false;
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            // if (matrix_[i][j] != other.matrix_[i][j])
            if (fabs(matrix_[i][j] - other.matrix_[i][j] > 1.e-7))
                return false;
        }
    }
    return true;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other)
{

    // S21Matrix copy = other;
    // std::swap(copy);
    // return *this;
    // std::swap(other.rows_, rows_);
    // std::swap(other.cols_, cols_);
    // std::swap(other.matrix_, matrix_);
    // return *this;

    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw "different matrix dimensions";

    if (&other == this)
        return *this;

    if (matrix_ != nullptr)
    {
        for (size_t i = 0; i < rows_; ++i)
        {
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double *[rows_];
    for (size_t i = 0; i < rows_; ++i)
    {
        matrix_[i] = new double[cols_];
    }

    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
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
    if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
        throw "index is outside the matrix";
    return matrix_[i][j];
}

void S21Matrix::SumMatrix(const S21Matrix &other)
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw "different matrix dimensions";
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
        }
    }
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const
{
    S21Matrix sum = *this;
    return sum += other;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other)
{
    SumMatrix(other);
    return *this;
}

void S21Matrix::SubMatrix(const S21Matrix &other)
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw "different matrix dimensions";
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
        }
    }
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const
{
    S21Matrix sub = *this;
    return sub -= other;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other)
{
    SubMatrix(other);
    return *this;
}

void S21Matrix::MulNumber(const double num)
{
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            matrix_[i][j] = matrix_[i][j] * num;
        }
    }
}

S21Matrix S21Matrix::operator*(const double num)
{
    S21Matrix mul = *this;
    return mul *= num;
}

S21Matrix &S21Matrix::operator*=(const double num)
{
    MulNumber(num);
    return *this;
}

void S21Matrix::MulMatrix(const S21Matrix &other)
{
    if (cols_ != other.rows_)
        throw "the number of columns of the first matrix is not equal to the number of rows of the second matrix";
    S21Matrix result(rows_, other.cols_);
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < other.cols_; ++j)
        {
            for (size_t k = 0; k < cols_; ++k)
            {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    *this = result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const
{
    S21Matrix mul = *this;
    return mul *= other;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other)
{
    MulMatrix(other);
    return *this;
}

S21Matrix S21Matrix::Transpose()
{
    S21Matrix result(cols_, rows_);
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            result.matrix_[j][i] = matrix_[i][j];
        }
    }
    return result;
}

// double S21Matrix::Determinant(){

// }

size_t S21Matrix::GetRows() const
{
    return rows_;
}
size_t S21Matrix::GetCols() const
{
    return cols_;
}

// void S21Matrix::SetRows(size_t newValue)
// {
//     // проверить на размер? если размер больше выделить память
//     if (newValue == 0)
//         throw "negative or null value";
//     if (newValue > rows_)
//     {
//         for(size_t i = 0; i < newValue; ++i) {
//             for (size_t j = 0; j <)
//         }
//         matrix_ = new double *[newValue];
//     }
//     if (newValue < rows_) {
//         for(size_t i = 0; i < newValue; ++i) {
//             for (size_t j = 0; j < cols_; ++j) {

//             }
//         }
//     }
//     rows_ = newValue;
// }

// void S21Matrix::SetCols(size_t newValue)
// {
//     // проверить на размер? если размер больше выделить память
//     if (newValue == 0)
//         throw "negative or null value";
//     if (newValue > cols_)
//     {
//         for (size_t i = 0; i < rows_; ++i)
//         {
//             this->matrix_[i] = new double[newValue]();
//         }
//     }
//     cols_ = newValue;
// }