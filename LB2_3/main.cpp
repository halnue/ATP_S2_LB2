////
//// Created by Michael on 24.04.2020.
////
//#include <iostream>
//#include "Matrix.h"
//#include "Matrix.cpp"
//
//#define PRINT_MATRIX(variable) std::cout << std::string(#variable) << ": "<< std::endl<<variable << std::endl;
//template<typename T>
//Matrix<T> changeNum(Matrix<T> m);
//int main() {
//    double **m1 = new double *[2];
//    m1[0] = new double[2]{0.0, 2.3};
//    m1[1] = new double[2]{7.6, 4.7};
//    double **m2 = new double *[2];
//    m2[0] = new double[2]{8.5, 1.5};
//    m2[1] = new double[2]{8.9, 5.5};
//
////    ArrayList<ArrayList<double>> list1 = ArrayList<ArrayList<double>>();
////    list1.add(ArrayList<double>(2, new double[2]{0.0, 2.3}));
////    list1.add(ArrayList<double>(2, new double[2]{7.6, 4.7}));
////
////    ArrayList<ArrayList<double>> list2 = ArrayList<ArrayList<double>>();
////    list2.add(ArrayList<double>(2, new double[2]{8.5, 1.5}));
////    list2.add(ArrayList<double>(2, new double[2]{8.9, 5.5}));
//
//    Matrix matrix1 = Matrix(2,2,m1);
//    Matrix matrix2 = Matrix(2,2,m2);
//    PRINT_MATRIX(matrix1)
//    PRINT_MATRIX(&matrix2)
//    Matrix matrix3 = changeNum(matrix1);
//    PRINT_MATRIX(matrix3)
//
//    Matrix matrixSum = matrix1.plus(matrix2);
//    PRINT_MATRIX(matrixSum)
//    PRINT_MATRIX(matrix1.subtraction(matrix2))
//    PRINT_MATRIX(matrix1 * matrix2)
//}
//template<typename T>
//Matrix<T> changeNum(Matrix<T> m) {
//    int w = m.getWidth();
//    int h = m.getHeight();
//    Matrix<T> matrix = Matrix<T>(m.getWidth(), m.getHeight());
//    for (int x = 0; x < w; ++x) {
//        for (int y = 0; y < h; ++y) {
//            T num = m[x][y];
//            if (num == 0)
//                matrix[x][y] = (T)1;
//            else
//                matrix[x][y] = num;
//        }
//    }
//    return matrix;
//}