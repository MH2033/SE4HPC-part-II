#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "matrix_multiplication.h"

// ######################### Source code of multiplyMatrices in src/matrix_mult

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
  std::vector<std::vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
  std::vector<std::vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};
  std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

  multiplyMatrices(A, B, C, 2, 3, 2);

  std::vector<std::vector<int>> expected = {{58, 64}, {139, 154}};

  ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test Zero Matrices
TEST(MatrixMultiplicationTest, TestMultiplyZeroMatrices) {
  std::vector<std::vector<int>> A = {{0, 0, 0}, {0, 0, 0}};
  std::vector<std::vector<int>> B = {{0, 0}, {0, 0}, {0, 0}};
  std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

  multiplyMatrices(A, B, C, 2, 3, 2);

  std::vector<std::vector<int>> expected = {{0, 0}, {0, 0}};

  ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test Identity Matrices
TEST(MatrixMultiplicationTest, TestMultiplyIdentityMatrices) {
  std::vector<std::vector<int>> A = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  std::vector<std::vector<int>> B = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

  multiplyMatrices(A, B, C, 3, 3, 3);

  std::vector<std::vector<int>> expected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test Ones Matrices
TEST(MatrixMultiplicationTest, TestMultiplyOnesMatrices) {
  std::vector<std::vector<int>> A = {{1, 1, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> B = {{1, 1}, {1, 1}, {1, 1}};
  std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

  multiplyMatrices(A, B, C, 2, 3, 2);

  std::vector<std::vector<int>> expected = {{3, 3}, {3, 3}};

  ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test diagonal matrices multiplication
TEST(MatrixMultiplicationTest, TestDigonalMatrices) {
  std::vector<std::vector<int>> A = {{8, 4}, {4, 4}, {4, 4}};
  std::vector<std::vector<int>> B = {{4, 4}, {4, 4}};
  std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));

  multiplyMatrices(A, B, C, 3, 2, 2);

  std::vector<std::vector<int>> expected(3, std::vector<int>(2, 0));
  multiplyMatricesWithoutErrors(A, B, expected, 3, 2, 2);

  ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test Matrices containg negative numbers
TEST(MatrixMultiplicationTest, TestMultiplyNegativeMatrices) {
  std::vector<std::vector<int>> A = {{-1, -2, -3}, {-4, -5, -6}};
  std::vector<std::vector<int>> B = {{-7, -8}, {-9, -10}, {-11, -12}};
  std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

  multiplyMatrices(A, B, C, 2, 3, 2);

  std::vector<std::vector<int>> expected = {{58, 64}, {139, 154}};

  ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

// Test Matrices by filling them entirely with the same number ranging from 0 to
// 100 and calculating their power 2
TEST(MatrixMultiplicationTest, TestMultiplySameNumberMatrices) {
  for (int i = 0; i < 100; i++) {
    std::vector<std::vector<int>> A = {{i, i, i}, {i, i, i}};
    std::vector<std::vector<int>> B = {{i, i}, {i, i}, {i, i}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected(2, std::vector<int>(2, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 2, 3, 2);

    EXPECT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
  }
}

// Test multiplication with Identity matrix
TEST(MatrixMultiplicationTest, TestMultiplyWithIdentityMatrix) {
  for (int i = 0; i < 100; i++) {
    std::vector<std::vector<int>> A = {{i, i}, {i, i}};
    std::vector<std::vector<int>> B = {{1, 0}, {0, 1}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected(2, std::vector<int>(2, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 2, 2, 2);

    EXPECT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
