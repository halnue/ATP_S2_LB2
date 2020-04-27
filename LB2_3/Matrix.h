//
// Created by Michael on 09.02.2020.
//

#ifndef S2LB1_2_MATRIX_H
#define S2LB1_2_MATRIX_H


#include <ostream>
#include "List.cpp"
#include "IncompatibleMatrices.h"
#include "NullPointErexception.h"
template <typename T> class Matrix {

private:
    List<List<T>> list = List<List<T>>();
    int width, height;
public:

    Matrix():Matrix(1, 1) {}

    Matrix(const Matrix &m){
        List list = createArray(m.getWidth(), m.getHeight(), 1);

        for (int i = 0; i < m.getWidth(); ++i) {
            for (int j = 0; j < m.getHeight(); ++j) {
                list[i][j] =  m.get(i, j);
            }
        }
        this->list = list;
        this->height = m.getHeight();
        this->width = m.getWidth();
    }

    Matrix(int width, int height);

    Matrix(int width, int height, int defaultValue){
        List list = createArray(width, height, defaultValue);
        this->list = list;
        this->height = height;
        this->width = width;
    }

    Matrix(List<List<T>> array) {
        list = array;
        this->width = array.size();
        this->height = array.get(0).size();
    }

    virtual ~Matrix(){

        width = 0;
        height = 0;
    }

    friend std::ostream &operator<<(std::ostream &os, Matrix *matrix){
//        todo("fix the conclusion")
        for (int i = 0; i < matrix->getWidth(); i++) {
            os << "| ";
            for (int i1 = 0; i1 < matrix->getHeight(); i1++) {
                os << matrix->get(i, i1) << " ";
            }
            os << "|" << std::endl;
        }
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix){
//    todo("fix the conclusion")
        for (int i = 0; i < matrix.getWidth(); i++) {
            os << "| ";
            for (int i1 = 0; i1 < matrix.getHeight(); i1++) {
                os << matrix.get(i, i1) << " ";
            }
            os << "|" << std::endl;
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Matrix matrix){
        for (int j = 0; j < matrix.getWidth(); ++j) {
            for (int i = 0; i < matrix.getHeight(); ++i) {
                int num;
                is >> num;
                matrix.set(j, i, num);
            }
        }
        return is;
    }

    List<T> &operator[](int i){
        if (width > i)
            return list[i];
        else
            throw NullPointErexception();
    }

    friend Matrix operator+(Matrix m1, Matrix m2) {
//    Matrix result = Matrix(m1.getWidth(), m1.getHeight(), 1);

        return m1.plus(m2);
    }

    friend Matrix operator-(Matrix m1, Matrix m2){
//    Matrix result = Matrix(m1.getWidth(), m1.getHeight(), 1);

        return m1.subtraction(m2);
    }

    friend Matrix operator*(Matrix m1, Matrix m2){
        return m1.multiply(m2);
    }

//    friend  Matrix operator=(const Matrix &m)
    int get(int width, int height) const{
        if (width > getWidth() && height > getHeight())
            throw NullPointErexception();
        return list.get(width).get(height);
    }

    void set(int width, int height, int value){
        list[width][height] = value;
    }

    Matrix plus(Matrix matrix){
        if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
            throw IncompatibleMatrices();
        else {
            Matrix matrixResult = Matrix(width, height, 1);
            for (int i = 0; i < matrix.getWidth(); ++i) {
                for (int j = 0; j < matrix.getHeight(); ++j) {
                    int r = get(i, j) + matrix.get(i, j);
                    matrixResult.set(i, j, r);
                }
            }
            return matrixResult;
        }
    }

    const Matrix subtraction(Matrix matrix) {
        if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
            throw IncompatibleMatrices();
        else {
            Matrix matrixResult = Matrix(width, height, 1);
            for (int i = 0; i < matrix.getWidth(); ++i) {
                for (int j = 0; j < matrix.getHeight(); ++j) {
                    matrixResult.set(i, j, get(i, j) - matrix.get(i, j));
                }
            }
            return matrixResult;
        }
    }

    const Matrix multiply(Matrix matrix){
        if (this->getHeight() != matrix.getWidth())
            throw IncompatibleMatrices();
        else {
            Matrix result = Matrix(width, matrix.getHeight(), 1);
            for (int x = 0; x < matrix.getWidth(); ++x) {
                for (int y = 0; y < matrix.getHeight(); ++y) {
                    List<int> m2 = matrix.getLineWidth(y);
                    List<int> m1 = getLineHeight(x);
                    int r = multiplyLines(m1, m2);
                    result.set(x, y, r);
                }
            }
            return result;
        }
    }

    Matrix multiply(int value){
        Matrix matrixResult = Matrix(width, height, 1);
        for (int x = 0; x < matrixResult.getWidth(); ++x) {
            for (int y = 0; y < matrixResult.getHeight(); ++y) {
                matrixResult.set(x, y, this->get(x, y) * value);
            }
        }
        return matrixResult;
    }

    int getWidth() const{
        return width;
    }

    int getHeight() const{
        return height;
    }


    friend Matrix changeNum(Matrix m){
        int w = m.getWidth();
        int h = m.getHeight();
        List<List<int>> l = List<List<int>>();
        for (int x = 0; x < w; ++x) {
            List<int> listInt = List<int>();
            for (int y = 0; y < h; ++y) {
                int num = m.get(x, y);
                if (num == 0)
                    listInt.add(1);
                else
                    listInt.add(num);

            }
            l.add(listInt);
        }
        return Matrix(l);
    }

private:

    int multiplyLines(List<T> line1, List<T> line2){
        int result = 0;
        for (int i = 0; i < line1.size(); ++i) {
            int sum = line1[i] * line2[i];
            result += sum;
        }
        return result;
    }

    List<T> getLineHeight(int width){
        return list[width];
    }

    List<T> getLineWidth(int height){
        List<int> listResult = List<int>();
        for (int j = 0; j < getHeight(); ++j) {
            listResult.add(get(j, height));
        }
        return listResult;
    }

    List<List<T>> createArray(int width, int height, int defaultValue) const{
        List<List<int>> list = List<List<int>>();
        for (int i = 0; i < width; ++i) {
            List<int> list1 = List<int>();
            for (int j = 0; j < height; ++j) {
//            list1.set(j,defaultValue);
                list1.add(defaultValue);
            }
            list.add(list1);
        }
        return list;
    }
};

#endif //S2LB1_2_MATRIX_H
