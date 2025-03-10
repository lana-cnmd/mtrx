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
        matrix_[i] = new double[other.cols_]();
    }

    for (size_t i = 0; i < other.rows_; ++i)
    {
        std::memcpy(matrix_[i], other.matrix_[i], sizeof(double) * other.cols_);
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

bool S21Matrix::EqMatrix(const S21Matrix &other) const noexcept
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

S21Matrix &S21Matrix::operator=(const S21Matrix &other)
{
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

    for (size_t i = 0; i < other.rows_; ++i)
    {
        std::memcpy(matrix_[i], other.matrix_[i], sizeof(double) * other.cols_);
    }
    return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept
{
    for (size_t i = 0; i < rows_; i++)
        delete[] matrix_[i];
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
    return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const noexcept
{
    return EqMatrix(other);
}

bool S21Matrix::operator!=(const S21Matrix &other) const noexcept
{
    return !(*this == other);
}

double &S21Matrix::operator()(size_t i, size_t j)
{
    if (i >= rows_ || j >= cols_)
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
            matrix_[i][j] += other.matrix_[i][j];
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
            matrix_[i][j] -= other.matrix_[i][j];
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

void S21Matrix::MulNumber(const double num) noexcept
{
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            matrix_[i][j] *= num;
        }
    }
}

S21Matrix S21Matrix::operator*(const double num) noexcept
{
    S21Matrix mul = *this;
    return mul *= num;
}

S21Matrix &S21Matrix::operator*=(const double num) noexcept
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

S21Matrix S21Matrix::Transpose() noexcept
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

double S21Matrix::Determinant()
{
    if (rows_ != cols_)
        throw "the matrix is not square";
    if (rows_ == 1)
        return matrix_[0][0];
    S21Matrix tmp = *this; 
    size_t currentStart = 0;
    double first = 0;
    double det = 1;
    for (; currentStart < tmp.rows_; currentStart++)
    { 
        size_t i = currentStart;
        if (fabs(tmp.matrix_[currentStart][currentStart]) < 1e-7)
        {
            for (; i < tmp.rows_ && fabs(tmp.matrix_[i][currentStart]) < 1e-7; ++i)
                ;
            if (i == tmp.rows_)
                det = 0.0;
            else
            {
                det *= -1;
                std::swap(tmp.matrix_[currentStart], tmp.matrix_[i]);
            }
        }
        det *= tmp.matrix_[currentStart][currentStart];
        for (size_t row = currentStart; row < tmp.rows_; ++row)
        {
            first = tmp.matrix_[row][currentStart];
            for (size_t col = currentStart; col < tmp.cols_; ++col)
            {
                if (row == currentStart)
                {
                    tmp.matrix_[row][col] /= first;
                }
                else
                {
                    tmp.matrix_[row][col] -= tmp.matrix_[currentStart][col] * first;
                }
            }
        }
    }
    return det;
}

void S21Matrix::CreateMinor(size_t rowRemove, size_t colRemove, S21Matrix &other)
{
    size_t row = 0;
    for (size_t i = 0; i < other.rows_; ++i)
    {
        size_t col = 0;
        for (size_t j = 0; j < other.cols_; ++j)
        {
            if (i != rowRemove && j != colRemove)
            {
                matrix_[row][col] = other.matrix_[i][j];
                col++;
            }
        }
        col = 0;
        if (i != rowRemove)
            row++;
    }
}

S21Matrix S21Matrix::CalcComplements()
{
    if (rows_ != cols_)
        throw "the matrix is not square";
    S21Matrix res(rows_, cols_);
    if (rows_ == 1)
    {
        res.matrix_[0][0] = 1;
        return res;
    }
    S21Matrix tmp(rows_ - 1, cols_ - 1);
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            tmp.CreateMinor(i, j, *this);
            res.matrix_[i][j] = tmp.Determinant() * pow(-1, i + j);
        }
    }
    return res;
}

S21Matrix S21Matrix::InverseMatrix()
{
    double det = this->Determinant();
    if (det == 0)
        throw "matrix determinant is 0";
    S21Matrix tmp;
    S21Matrix res;
    tmp = CalcComplements();
    res = tmp.Transpose();
    res.MulNumber(1 / det);
    return res;
}

size_t S21Matrix::GetRows() const noexcept
{
    return rows_;
}
size_t S21Matrix::GetCols() const noexcept
{
    return cols_;
}

void S21Matrix::SetRows(size_t newValue)
{
    if (newValue < 1)
        throw "Invalid Matrix size";
    S21Matrix tmp(newValue, cols_);
    if (newValue < rows_)
    {
        for(size_t i = 0; i < newValue; ++i) {
            std::memcpy(tmp.matrix_[i], matrix_[i], sizeof(double) * cols_);
        }
    }
    if (newValue > rows_)
    {
        for(size_t i = 0; i < rows_; ++i) {
            std::memcpy(tmp.matrix_[i], matrix_[i], sizeof(double) * cols_);
        }
    }
    *this = std::move(tmp);
}

void S21Matrix::SetCols(size_t newValue)
{
    if (newValue < 1)
        throw "Invalid Matrix size";
    S21Matrix tmp(rows_, newValue);
    if (newValue < cols_)
    {
       for(size_t i = 0; i < rows_; ++i) {
            std::memcpy(tmp.matrix_[i], matrix_[i], sizeof(double) * newValue);
        }
    }
    if (newValue > cols_)
    {
         for(size_t i = 0; i < rows_; ++i) {
            std::memcpy(tmp.matrix_[i], matrix_[i], sizeof(double) * cols_);
        }
    }
    *this = std::move(tmp);
}
