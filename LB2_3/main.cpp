//
// Created by Michael on 24.04.2020.
//
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

#define PRINT_MATRIX(variable) std::cout << std::string(#variable) << ": "<< std::endl<<variable << std::endl;

int main() {

    List<List<int>> list1 = List<List<int>>();
    list1.add(List<int>(2, new int[2]{0, 2}));
    list1.add(List<int>(2, new int[2]{7, 4}));

    List<List<int>> list2 = List<List<int>>();
    list2.add(List<int>(2, new int[2]{8, 1}));
    list2.add(List<int>(2, new int[2]{8, 5}));

    Matrix matrix1 = Matrix(list1);
    Matrix matrix2 = Matrix(list2);

    PRINT_MATRIX(matrix1)
    PRINT_MATRIX(&matrix2)
    Matrix matrix3 = changeNum(matrix1);
    PRINT_MATRIX(matrix3)

    Matrix matrixSum = matrix1.plus(matrix2);
    PRINT_MATRIX(matrixSum)
    PRINT_MATRIX(matrix1.subtraction(matrix2))
    PRINT_MATRIX(matrix1 * matrix2)
}