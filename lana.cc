#include "s21_matrix_oop.h"

void func1()
{
    S21Matrix local(3, 3);
}

int main()
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = 3;
    matrix_a(1, 1) = 4;

    S21Matrix inverse = matrix_a.InverseMatrix();

    return 0;
}