#include "s21_matrix_oop.h"

void func1()
{
    S21Matrix local(3, 3);
}

int main()
{
    S21Matrix matrix_a(2, 2), matrix_b(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b = matrix_a;
    return 0;
}
