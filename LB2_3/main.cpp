//
// Created by Michael on 24.04.2020.
//
#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

#define PRINT_MATRIX(variable) std::cout << std::string(#variable) << ": "<< std::endl<<variable << std::endl;

int main() {

    List<List<double>> list1 = List<List<double>>();
    list1.add(List<double>(2, new double[2]{0.6, 2.3}));
    list1.add(List<double>(2, new double[2]{7.6, 4.7}));

    List<List<double>> list2 = List<List<double>>();
    list2.add(List<double>(2, new double[2]{8.5, 1.5}));
    list2.add(List<double>(2, new double[2]{8.9, 5.5}));

    Matrix matrix1 = Matrix(list1);
    Matrix matrix2 = Matrix(list2);
    PRINT_MATRIX(matrix1[0][0])
    PRINT_MATRIX(matrix1)
    PRINT_MATRIX(&matrix2)
    Matrix matrix3 = changeNum(matrix1);
    PRINT_MATRIX(matrix3)

    Matrix matrixSum = matrix1.plus(matrix2);
    PRINT_MATRIX(matrixSum)
    PRINT_MATRIX(matrix1.subtraction(matrix2))
    PRINT_MATRIX(matrix1 * matrix2)
}