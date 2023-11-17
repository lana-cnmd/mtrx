#include "s21_matrix_oop.h"

void func1() {
    S21Matrix local(3, 3);
}

int main() {
    S21Matrix m1(2, 3);
    func1();
    std::cout << "Привет" << std::endl;
    func1();
    std::cout << "Привет2" << std::endl;
    {
        S21Matrix m2(1, 1);
    }

    return 0;
}
