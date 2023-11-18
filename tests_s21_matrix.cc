#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqualTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    ASSERT_EQ(matrix_a(0, 0), 2);
    ASSERT_EQ(matrix_a(0, 1), 3.2);
    ASSERT_EQ(matrix_a(1, 0), 0);
    ASSERT_EQ(matrix_a(1, 1), -23.45);
}

TEST(EqualTests, test_2)
{
    S21Matrix matrix_a(2, 2), matrix_b(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b = matrix_a;
    ASSERT_EQ(matrix_a, matrix_b);
}

TEST(EqualTests, test_3)
{
    S21Matrix matrix_a(2, 2); // не понял теста
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    ASSERT_NE(matrix_a(0, 0), 0);
    ASSERT_NE(matrix_a(0, 1), 0);
    ASSERT_NE(matrix_a(1, 0), 1);
    ASSERT_NE(matrix_a(1, 1), 0);
}

TEST(EqualTests, test_4)
{
    S21Matrix matrix_a(2, 2), matrix_b(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b = matrix_a;
    ASSERT_FALSE(matrix_a != matrix_b);
}

TEST(EqualTests, test_5)
{
    S21Matrix matrix_a(2, 2), matrix_b(4, 4);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b = matrix_a;
    ASSERT_TRUE(matrix_a != matrix_b);
}

// Почему не могу так написать?
// TEST(sometest, test_1)
// {
//     S21Matrix matrix_a(2, 2);
//     matrix_a(0, 0) = 2;
//     matrix_a(0, 1) = 3.2;
//     matrix_a(1, 0) = 0;
//     matrix_a(1, 1) = -23.45;
//     S21Matrix matrix_b(2, 2) = matrix_a;  // S21Matrix matrix_b = matrix_a;
// }

TEST(EqualTests, test_6)
{
    S21Matrix matrix_a(2, 2), matrix_b(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;
    ASSERT_FALSE(matrix_a == matrix_b);
    ASSERT_TRUE(matrix_a != matrix_b);
}
TEST(EqualTests, test_7)
{
    S21Matrix matrix_a(3, 2), matrix_b(3, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_a(2, 0) = 100;
    matrix_a(2, 1) = 100;
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;
    matrix_b(2, 0) = 100;
    matrix_b(2, 1) = 100;
    ASSERT_FALSE(matrix_a == matrix_b);
    ASSERT_TRUE(matrix_a != matrix_b);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
