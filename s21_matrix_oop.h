#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <iostream>
#include <cmath>
#include <cstring>

class S21Matrix
{
public:
    S21Matrix();
    S21Matrix(size_t rows, size_t cols);
    S21Matrix(const S21Matrix &other);
    S21Matrix(S21Matrix &&other);
    ~S21Matrix();
    bool EqMatrix(const S21Matrix &other) const noexcept; 
    void SumMatrix(const S21Matrix &other); 
    void SubMatrix(const S21Matrix &other);  
    void MulNumber(const double num) noexcept; 
    void MulMatrix(const S21Matrix &other); 
    S21Matrix Transpose() noexcept;
    double Determinant();
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();
    size_t GetRows() const noexcept;
    size_t GetCols() const noexcept;
    void SetRows(size_t newValue);
    void SetCols(size_t newValue);
    S21Matrix &operator=(const S21Matrix &other);
    S21Matrix &operator=(S21Matrix &&other) noexcept;
    bool operator==(const S21Matrix &other) const noexcept;
    bool operator!=(const S21Matrix &other) const noexcept; 
    double &operator()(size_t i, size_t j);
    S21Matrix operator+(const S21Matrix &other) const ;
    S21Matrix &operator+=(const S21Matrix &other);     
    S21Matrix operator-(const S21Matrix &other) const ;
    S21Matrix &operator-=(const S21Matrix &other);     
    S21Matrix operator*(const double num) noexcept;    
    S21Matrix operator*(const S21Matrix &other) const; 
    S21Matrix &operator*=(const double num) noexcept;  
    S21Matrix &operator*=(const S21Matrix &other);     

private:
    void CreateMinor(size_t rowRemove, size_t colRemove, S21Matrix &other);

private:
    size_t rows_;
    size_t cols_;
    double **matrix_;
};

#endif // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
