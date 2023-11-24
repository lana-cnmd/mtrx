#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrix, test_1)
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

TEST(EqMatrix, test_2)
{
    S21Matrix matrix_a(2, 2), matrix_b(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b = matrix_a;

    ASSERT_EQ(matrix_a, matrix_b);
}

TEST(EqMatrix, test_3)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    ASSERT_NE(matrix_a(0, 0), 0);
    ASSERT_NE(matrix_a(0, 1), 0);
    ASSERT_NE(matrix_a(1, 0), 1);
    ASSERT_NE(matrix_a(1, 1), 0);
}

TEST(EqMatrix, test_4)
{
    S21Matrix matrix_a(2, 2), matrix_b(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_b = matrix_a;

    ASSERT_FALSE(matrix_a != matrix_b);
}

TEST(EqMatrix, test_5)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;

    ASSERT_FALSE(matrix_a == matrix_b);
    ASSERT_TRUE(matrix_a != matrix_b);
    ASSERT_EQ(matrix_a.EqMatrix(matrix_b), 0);
}

TEST(EqMatrix, test_6)
{
    S21Matrix matrix_a(3, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;
    matrix_a(2, 0) = 100;
    matrix_a(2, 1) = 100;

    S21Matrix matrix_b(3, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;
    matrix_b(2, 0) = 100;
    matrix_b(2, 1) = 100;

    ASSERT_FALSE(matrix_a == matrix_b);
    ASSERT_TRUE(matrix_a != matrix_b);
    ASSERT_EQ(matrix_a.EqMatrix(matrix_b), 0);
}

TEST(EqMatrix, test_7)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = 3;
    matrix_a(1, 1) = 4;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;

    ASSERT_FALSE(matrix_a != matrix_b);
    ASSERT_TRUE(matrix_a == matrix_b);
    ASSERT_EQ(matrix_a.EqMatrix(matrix_b), 1);
}

TEST(SumMatrixTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;

    S21Matrix result(2, 2);
    result(0, 0) = 3;
    result(0, 1) = 5.2;
    result(1, 0) = 3;
    result(1, 1) = -19.45;

    matrix_a.SumMatrix(matrix_b);
    ASSERT_EQ(matrix_a, result);
}

TEST(SumMatrixTests, test_2)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;

    S21Matrix result(2, 2);
    result(0, 0) = -3;
    result(0, 1) = 5.2;
    result(1, 0) = 3;
    result(1, 1) = -19.45;
    matrix_a.SumMatrix(matrix_b);
    ASSERT_NE(matrix_a, result);
}

TEST(SumMatrixTests, test_3)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(1, 1);
    matrix_b(0, 0) = 1;

    ASSERT_ANY_THROW(matrix_a.SumMatrix(matrix_b));
}

TEST(SubMatrixTests, test_1)
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

    S21Matrix result(2, 2);
    result(0, 0) = 1;
    result(0, 1) = 1.2;
    result(1, 0) = -3;
    result(1, 1) = -27.45;

    matrix_a.SubMatrix(matrix_b);
    ASSERT_EQ(matrix_a, result);
}

TEST(SubMatrixTests, test_2)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;

    S21Matrix result(2, 2);
    result(0, 0) = -1;
    result(0, 1) = 1.2;
    result(1, 0) = -3;
    result(1, 1) = -27.45;

    matrix_a.SubMatrix(matrix_b);
    ASSERT_EQ(matrix_a.EqMatrix(matrix_b), 1);
}

TEST(SubMatrixTests, test_3)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(1, 1);
    matrix_b(0, 0) = 1;

    ASSERT_ANY_THROW(matrix_a.SubMatrix(matrix_b));
}

TEST(SumOperatorTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 2;
    matrix_b(1, 0) = 3;
    matrix_b(1, 1) = 4;

    S21Matrix result(2, 2);
    result(0, 0) = 3;
    result(0, 1) = 5.2;
    result(1, 0) = 3;
    result(1, 1) = -19.45;

    ASSERT_TRUE((matrix_a + matrix_b) == result);
}

TEST(SumOperatorTests, test_2)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(1, 1);
    matrix_b(0, 0) = 1;

    ASSERT_ANY_THROW(matrix_a + matrix_b);
}

TEST(SumOperatorTests, test_3)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 3.2;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = -23.45;

    S21Matrix matrix_b(1, 1);
    matrix_b(0, 0) = 1;

    ASSERT_ANY_THROW(matrix_a += matrix_b);
}

TEST(SubOperatorTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 10;
    matrix_a(1, 0) = 100;
    matrix_a(1, 1) = 1000;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = 1;
    matrix_b(0, 1) = 1;
    matrix_b(1, 0) = 1;
    matrix_b(1, 1) = 1;

    S21Matrix result(2, 2);
    result(0, 0) = 0;
    result(0, 1) = 9;
    result(1, 0) = 99;
    result(1, 1) = 999;

    ASSERT_TRUE((matrix_a - matrix_b) == result);
}

TEST(SubOperatorTests, test_2)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 10;
    matrix_a(1, 0) = 100;
    matrix_a(1, 1) = 1000;

    S21Matrix matrix_b(1, 1);
    matrix_b(0, 0) = 1;

    ASSERT_ANY_THROW(matrix_a - matrix_b);
}

TEST(SubOperatorTests, test_3)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 10;
    matrix_a(1, 0) = 100;
    matrix_a(1, 1) = 1000;

    S21Matrix matrix_b(1, 1);
    matrix_b(0, 0) = 1;

    ASSERT_ANY_THROW(matrix_a -= matrix_b);
}

TEST(MulNumberTests, test_1)
{
    const double num = 100.0;

    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = -1;
    matrix_a(1, 0) = 234.4567;
    matrix_a(1, 1) = -456543.3;

    S21Matrix result(2, 2);
    result(0, 0) = 100;
    result(0, 1) = -100;
    result(1, 0) = 23445.67;
    result(1, 1) = -45654330;

    matrix_a.MulNumber(num);
    ASSERT_TRUE(matrix_a == result);
}

TEST(MulNumberOperTests, test_1)
{
    const double num = 100.0;

    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = -1;
    matrix_a(1, 0) = 234.4567;
    matrix_a(1, 1) = -456543.3;

    S21Matrix result(2, 2);
    result(0, 0) = 100;
    result(0, 1) = -100;
    result(1, 0) = 23445.67;
    result(1, 1) = -45654330;

    ASSERT_TRUE((matrix_a * num) == result);
}

TEST(MulNumberOperTests, test_2)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = -1;
    matrix_a(1, 0) = 234.4567;
    matrix_a(1, 1) = -456543.3;

    S21Matrix result(2, 2);
    result(0, 0) = 100;
    result(0, 1) = -100;
    result(1, 0) = 23445.67;
    result(1, 1) = -45654330;

    ASSERT_TRUE((matrix_a *= 100) == result);
}

TEST(MulMatrixTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    S21Matrix result(2, 2);
    result(0, 0) = -28;
    result(0, 1) = 4;
    result(1, 0) = 46.2;
    result(1, 1) = 0;

    matrix_a.MulMatrix(matrix_b);
    ASSERT_TRUE(matrix_a == result);
}

TEST(MulMatrixTests, test_2)
{
    S21Matrix matrix_a(1, 1);
    matrix_a(0, 0) = 3;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    ASSERT_ANY_THROW(matrix_a.MulMatrix(matrix_b));
}

TEST(MulMatrixOperTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 3;
    matrix_a(0, 1) = 2;
    matrix_a(1, 0) = -6.6;
    matrix_a(1, 1) = 0;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    S21Matrix result(2, 2);
    result(0, 0) = -28;
    result(0, 1) = 4;
    result(1, 0) = 46.2;
    result(1, 1) = 0;

    ASSERT_TRUE((matrix_a * matrix_b) == result);
}

TEST(MulMatrixOperTests, test_2)
{
    S21Matrix matrix_a(2, 1);
    matrix_a(0, 0) = 3;
    matrix_a(1, 0) = -6.6;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = -7;
    matrix_b(0, 1) = 0;
    matrix_b(1, 0) = -3.5;
    matrix_b(1, 1) = 2;

    ASSERT_ANY_THROW(matrix_a *= matrix_b);
}

TEST(MulMatrixOperTests, test_3)
{
    S21Matrix matrix_a(1, 1);
    matrix_a(0, 0) = 3;

    S21Matrix matrix_b(2, 2);
    matrix_b(0, 0) = -23;
    matrix_b(0, 1) = 30;
    matrix_b(1, 0) = -345.5;
    matrix_b(1, 1) = 234;

    ASSERT_ANY_THROW(matrix_a * matrix_b);
}

TEST(BracOperTests, test_1)
{
    S21Matrix matrix_a(3, 3);
    ASSERT_ANY_THROW(matrix_a(-1, -2));
}

TEST(BracOperTests, test_2)
{
    S21Matrix matrix_a(3, 3);
    ASSERT_ANY_THROW(matrix_a(4, 4));
}

TEST(TransponceMatrix, test_1)
{
    S21Matrix matrix_a(5, 1);
    matrix_a(0, 0) = -701;
    matrix_a(1, 0) = -991;
    matrix_a(2, 0) = 23.4;
    matrix_a(3, 0) = 0;
    matrix_a(4, 0) = 234;

    S21Matrix result(1, 5);
    result(0, 0) = -701;
    result(0, 1) = -991;
    result(0, 2) = 23.4;
    result(0, 3) = 0;
    result(0, 4) = 234;

    S21Matrix transponse = matrix_a.Transpose();
    ASSERT_TRUE(transponse == result);
}

TEST(TransponceMatrix, test_2)
{
    S21Matrix matrix_a(5, 2);
    matrix_a(0, 0) = -2;
    matrix_a(0, 1) = -15;
    matrix_a(1, 0) = -48;
    matrix_a(1, 1) = -83.45;
    matrix_a(2, 0) = 83;
    matrix_a(2, 1) = -39;
    matrix_a(3, 0) = 48;
    matrix_a(3, 1) = -79;
    matrix_a(4, 0) = -34;
    matrix_a(4, 1) = -18;

    S21Matrix result(2, 5);
    result(0, 0) = -2;
    result(0, 1) = -48;
    result(0, 2) = 83;
    result(0, 3) = 48;
    result(0, 4) = -34;
    result(1, 0) = -15;
    result(1, 1) = -83.45;
    result(1, 2) = -39;
    result(1, 3) = -79;
    result(1, 4) = -18;

    S21Matrix transponse = matrix_a.Transpose();
    ASSERT_TRUE(transponse == result);
}

TEST(TransponceMatrix, test_3)
{
    S21Matrix matrix_a(4, 3);
    matrix_a(0, 0) = 7;
    matrix_a(0, 1) = -98;
    matrix_a(0, 2) = 0.5;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = 5.4;
    matrix_a(1, 2) = 32;
    matrix_a(2, 0) = 3.12;
    matrix_a(2, 1) = 2323;
    matrix_a(2, 2) = 23;
    matrix_a(3, 0) = -78;
    matrix_a(3, 1) = 476.4;
    matrix_a(3, 2) = 21;

    S21Matrix result(3, 4);
    result(0, 0) = 7;
    result(0, 1) = 0;
    result(0, 2) = 3.12;
    result(0, 3) = -78;
    result(1, 0) = -98;
    result(1, 1) = 5.4;
    result(1, 2) = 2323;
    result(1, 3) = 476.4;
    result(2, 0) = 0.5;
    result(2, 1) = 32;
    result(2, 2) = 23;
    result(2, 3) = 21;

    S21Matrix transponse = matrix_a.Transpose();
    ASSERT_TRUE(transponse == result);
}

// TEST(DeterminantTests, test_1) {
//   S21Matrix matrix_a(3, 3);
//   matrix_a(0, 0) = 0;
//     matrix_a(0, 1) = 5;
//     matrix_a(0, 2) = 7;
//     matrix_a(1, 0) = 6;
//     matrix_a(1, 1) = 3;
//     matrix_a(1, 2) = 4;
//     matrix_a(2, 0) = 5;
//     matrix_a(2, 1) = -2;
//     matrix_a(2, 2) = -3;

//   double det = matrix_a.Determinant();
//   double result = 1;

// ASSERT_EQ(det, result);
// }

TEST(DeterminantTests, test_2)
{
    S21Matrix matrix_a(3, 3);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 5;
    matrix_a(0, 2) = 7;
    matrix_a(1, 0) = 6;
    matrix_a(1, 1) = 3;
    matrix_a(1, 2) = 4;
    matrix_a(2, 0) = 5;
    matrix_a(2, 1) = -2;
    matrix_a(2, 2) = -3;

    double det = matrix_a.Determinant();
    double result = 0;

    ASSERT_EQ(det, result);
}

TEST(DeterminantTests, test_3)
{
    S21Matrix matrix_a(3, 2);

    ASSERT_ANY_THROW(matrix_a.Determinant());
}

TEST(CalcComplementsTests, test_1)
{
    S21Matrix matrix_a(2, 2);
    matrix_a(0, 0) = 57;
    matrix_a(0, 1) = -55;
    matrix_a(1, 0) = 2;
    matrix_a(1, 1) = -79;

    S21Matrix result(2, 2);
    result(0, 0) = -79;
    result(0, 1) = -2;
    result(1, 0) = 55;
    result(1, 1) = 57;

    ASSERT_TRUE(matrix_a.CalcComplements().EqMatrix(result));
}

TEST(CalcComplementsTests, test_2)
{
    S21Matrix matrix_a(3, 3);
    matrix_a(0, 0) = 1;
    matrix_a(0, 1) = 2;
    matrix_a(0, 2) = 3;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = 4;
    matrix_a(1, 2) = 2;
    matrix_a(2, 0) = 5;
    matrix_a(2, 1) = 2;
    matrix_a(2, 2) = 1;

    S21Matrix result(3, 3);
    result(0, 0) = 0;
    result(0, 1) = 10;
    result(0, 2) = -20;
    result(1, 0) = 4;
    result(1, 1) = -14;
    result(1, 2) = 8;
    result(2, 0) = -8;
    result(2, 1) = -2;
    result(2, 2) = 4;

    ASSERT_TRUE(matrix_a.CalcComplements().EqMatrix(result));
}

TEST(CalcComplementsTests, test_3)
{
    S21Matrix matrix_a(3, 4);
    ASSERT_ANY_THROW(matrix_a.CalcComplements());
}

// TEST(InverseMatrix, test_1)
// {

// }

// TEST(Inverse, False)
// {
//     S21Matrix matrix_a(4, 3);
//     S21Matrix result(3, 4);

//     matrix_a(0, 0) = 7;
//     matrix_a(0, 1) = -98;
//     matrix_a(0, 2) = 0.5;
//     matrix_a(1, 0) = 0;
//     matrix_a(1, 1) = 5.4;
//     matrix_a(1, 2) = 32;
//     matrix_a(2, 0) = 3.12;
//     matrix_a(2, 1) = 2323;
//     matrix_a(2, 2) = 23;
//     matrix_a(3, 0) = -78;
//     matrix_a(3, 1) = 476.4;
//     matrix_a(3, 2) = 21;
//     ASSERT_ANY_THROW(matrix_a.InverseMatrix());
// }
// TEST(Inverse, True)
// {
//     S21Matrix matrix_a(3, 3);
//     S21Matrix result(3, 3);

//     matrix_a(0, 0) = 2;
//     matrix_a(0, 1) = 5;
//     matrix_a(0, 2) = 7;
//     matrix_a(1, 0) = 6;
//     matrix_a(1, 1) = 3;
//     matrix_a(1, 2) = 4;
//     matrix_a(2, 0) = 5;
//     matrix_a(2, 1) = -2;
//     matrix_a(2, 2) = -3;

//     result(0, 0) = 1;
//     result(0, 1) = -1;
//     result(0, 2) = 1;
//     result(1, 0) = -38;
//     result(1, 1) = 41;
//     result(1, 2) = -34;
//     result(2, 0) = 27;
//     result(2, 1) = -29;
//     result(2, 2) = 24;

//     ASSERT_TRUE(matrix_a.InverseMatrix().EqMatrix(result));

//     S21Matrix matrix_c(1, 1);
//     S21Matrix matrix_c_res(1, 1);
//     matrix_c_res(0, 0) = 1;
//     matrix_c(0, 0) = 1;
//     ASSERT_TRUE(matrix_c.InverseMatrix().EqMatrix(matrix_c_res));
// }

TEST(GetTests, test_1)
{
    S21Matrix matrix_a(3, 3);
    matrix_a(0, 0) = 2;
    matrix_a(0, 1) = 5;
    matrix_a(0, 2) = 7;
    matrix_a(1, 0) = 6;
    matrix_a(1, 1) = 3;
    matrix_a(1, 2) = 4;
    matrix_a(2, 0) = 5;
    matrix_a(2, 1) = -2;
    matrix_a(2, 2) = -3;

    ASSERT_EQ(matrix_a.GetRows(), (size_t)3);
    ASSERT_EQ(matrix_a.GetCols(), (size_t)3);
}

TEST(GetTests, test_2)
{
    S21Matrix matrix_a(4, 3);

    matrix_a(0, 0) = 7;
    matrix_a(0, 1) = -98;
    matrix_a(0, 2) = 0.5;
    matrix_a(1, 0) = 0;
    matrix_a(1, 1) = 5.4;
    matrix_a(1, 2) = 32;
    matrix_a(2, 0) = 3.12;
    matrix_a(2, 1) = 2323;
    matrix_a(2, 2) = 23;
    matrix_a(3, 0) = -78;
    matrix_a(3, 1) = 476.4;
    matrix_a(3, 2) = 21;

    ASSERT_EQ(matrix_a.GetRows(), (size_t)4);
    ASSERT_EQ(matrix_a.GetCols(), (size_t)3);
}

TEST(GetTests, test_3)
{
    S21Matrix matrix_a(1, 1);
    matrix_a(0, 0) = 7;

    ASSERT_EQ(matrix_a.GetRows(), (size_t)1);
    ASSERT_EQ(matrix_a.GetCols(), (size_t)1);
}

// TEST(SetTests, test_1)
// {
//     S21Matrix matrix_a(3, 3);

//     matrix_a(0, 0) = 2;
//     matrix_a(0, 1) = 5;
//     matrix_a(0, 2) = 7;
//     matrix_a(1, 0) = 6;
//     matrix_a(1, 1) = 3;
//     matrix_a(1, 2) = 4;
//     matrix_a(2, 0) = 5;
//     matrix_a(2, 1) = -2;
//     matrix_a(2, 2) = -3;

//     matrix_a.SetCols(2);
//     matrix_a.SetRows(2);

//     ASSERT_EQ(matrix_a.GetCols(), (size_t)2);
//     ASSERT_EQ(matrix_a.GetRows(), (size_t)2);
// }

// TEST(SetTests, test_2)
// {
//     S21Matrix matrix_a(2, 2);

//     matrix_a(0, 0) = 2;
//     matrix_a(0, 1) = 5;
//     matrix_a(1, 0) = 6;
//     matrix_a(1, 1) = 3;

//     matrix_a.SetCols(3);
//     matrix_a.SetRows(3);

//     ASSERT_EQ(matrix_a.GetCols(), (size_t)3);
//     ASSERT_EQ(matrix_a.GetRows(), (size_t)3);
// }

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}