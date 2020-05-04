//
// Created by Michael on 09.02.2020.
//

#ifndef S2LB1_2_MATRIX_H
#define S2LB1_2_MATRIX_H


#include <ostream>
#include "List.cpp"
#include "IncompatibleMatrices.h"
#include "NullPointErexception.h"

template<typename T>
class Matrix {

private:
    ArrayList<ArrayList<T>> list = ArrayList<ArrayList<T>>();

    Matrix() : Matrix(1, 1) {}

public:

    Matrix(const Matrix &m) {
        ArrayList list = createArray(m.getWidth(), m.getHeight(), 1);

        for (int i = 0; i < m.getWidth(); ++i) {
            for (int j = 0; j < m.getHeight(); ++j) {
                list[i][j] = m.get(i, j);
            }
        }
        this->list = list;
    }

    Matrix(int width, int height) {
        ArrayList list = createArray(width, height, (T) 1);
        this->list = list;
    }

    Matrix(ArrayList<ArrayList<T>> array) {
        list = array;
    }

    Matrix(int width, int height, T **array) {
        list = ArrayList<ArrayList<double>>();
        for (int i = 0; i < width; ++i) {
            list.add(ArrayList<double>(height, array[i]));
        }
    }

    friend std::ostream &operator<<(std::ostream &os, Matrix *matrix) {
        for (int i = 0; i < matrix->getWidth(); i++) {
            os << "| ";
            for (int i1 = 0; i1 < matrix->getHeight(); i1++) {
                os << matrix->get(i, i1) << " ";
            }
            os << "|" << std::endl;
        }
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        for (int i = 0; i < matrix.getWidth(); i++) {
            os << "| ";
            for (int i1 = 0; i1 < matrix.getHeight(); i1++) {
                os << matrix.get(i, i1) << " ";
            }
            os << "|" << std::endl;
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Matrix matrix) {
        for (int j = 0; j < matrix.getWidth(); ++j) {
            for (int i = 0; i < matrix.getHeight(); ++i) {
                int num;
                is >> num;
                matrix.set(j, i, num);
            }
        }
        return is;
    }

    ArrayList<T> &operator[](int i) {
        if (getWidth() > i)
            return list[i];
        else
            throw NullPointErexception();
    }

    friend Matrix operator+(Matrix m1, Matrix m2) {
        return m1.plus(m2);
    }

    friend Matrix operator-(Matrix m1, Matrix m2) {
        return m1.subtraction(m2);
    }

    friend Matrix operator*(Matrix m1, Matrix m2) {
        return m1.multiply(m2);
    }

    T get(int width, int height) const {
        if (width > getWidth() && height > getHeight())
            throw NullPointErexception();
        return list.get(width).get(height);
    }

    void set(int width, int height, T value) {
        list[width][height] = value;
    }

    Matrix<T> plus(Matrix matrix) {
        if (this->getWidth() != matrix.getWidth() && this->getHeight() != matrix.getHeight())
            throw IncompatibleMatrices();
        else {
            Matrix<T> matrixResult = Matrix<T>(getWidth(), getHeight());
            for (int i = 0; i < matrix.getWidth(); ++i) {
                for (int j = 0; j < matrix.getHeight(); ++j) {
                    T r = get(i, j) + matrix.get(i, j);
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
            Matrix matrixResult = Matrix(getWidth(), getHeight());
            for (int i = 0; i < matrix.getWidth(); ++i) {
                for (int j = 0; j < matrix.getHeight(); ++j) {
                    matrixResult.set(i, j, get(i, j) - matrix.get(i, j));
                }
            }
            return matrixResult;
        }
    }

    const Matrix multiply(Matrix matrix) {
        if (this->getHeight() != matrix.getWidth())
            throw IncompatibleMatrices();
        else {
            Matrix result = Matrix(getWidth(), matrix.getHeight());
            for (int x = 0; x < matrix.getWidth(); ++x) {
                for (int y = 0; y < matrix.getHeight(); ++y) {
                    ArrayList<T> m2 = matrix.getLineWidth(y);
                    ArrayList<T> m1 = getLineHeight(x);
                    T r = multiplyLines(m1, m2);
                    result.set(x, y, r);
                }
            }
            return result;
        }
    }

    Matrix multiply(int value) {
        Matrix matrixResult = Matrix(getWidth(), getHeight(), 1);
        for (int x = 0; x < matrixResult.getWidth(); ++x) {
            for (int y = 0; y < matrixResult.getHeight(); ++y) {
                matrixResult.set(x, y, this->get(x, y) * value);
            }
        }
        return matrixResult;
    }

    int getWidth() const {
        return list.size();
    }

    int getHeight() const {
        if (getWidth() > 0)
            return list.get(0).size();
        else return 0;
    }


private:

    T multiplyLines(ArrayList<T> line1, ArrayList<T> line2) {
        T result = 0;
        for (int i = 0; i < line1.size(); ++i) {
            T sum = line1[i] * line2[i];
            result += sum;
        }
        return result;
    }

    ArrayList<T> getLineHeight(int width) {
        return list[width];
    }

    ArrayList<T> getLineWidth(int height) {
        ArrayList<T> listResult = ArrayList<T>();
        for (int j = 0; j < getHeight(); ++j) {
            listResult.add(get(j, height));
        }
        return listResult;
    }

    ArrayList<ArrayList<T>> createArray(int width, int height, int defaultValue) const {
        ArrayList<ArrayList<T>> list = ArrayList<ArrayList<T>>();
        for (int i = 0; i < width; ++i) {
            ArrayList<T> list1 = ArrayList<T>();
            for (int j = 0; j < height; ++j) {
                list1.add(defaultValue);
            }
            list.add(list1);
        }
        return list;
    }
};

#endif //S2LB1_2_MATRIX_H
