//
// Created by Michael on 02.05.2020.
//

#ifndef S2LB2_1_ARRAYLIST_H
#define S2LB2_1_ARRAYLIST_H

#include "NullPointErexception.h"

template <typename T>class ArrayList {
private:
    T *array;
    int length;
    int maxLength;
public:

    ArrayList(int maxSize) {
        array = new int[maxSize];
        maxLength = maxSize;
        length = 0;
    }

    ArrayList(ArrayList<T> const &listInt) {
        this->length = listInt.size();
        this->maxLength = listInt.size()*2;
        array = new T[maxLength];
        for (int i = 0; i < listInt.size(); ++i) {
            array[i] = listInt.get(i);
        }
    }

    ArrayList() {
        int maxSize = 10;
        array = new T[maxSize];
        maxLength = maxSize;
        length = 0;
    }

    ArrayList(int size, T *arrayInt) {
        int maxSize = size * 2;
        array = new T[maxSize];
        maxLength = maxSize;
        length = 0;
        for (int i = 0; i < size; ++i) {
            add(arrayInt[i]);
        }
    }

    void add(T value) {
        if (length == maxLength) {
            maxLength *= 2;
            T *newArray = new T[maxLength];
            for (int i = 0; i < length; ++i) {
                newArray[i] = get(i);
            }
            array = newArray;
        }
        array[length] = value;
        length++;
    }

    const  T get(int i) const {
        if (i < length)
            return array[i];
        else
            throw NullPointErexception();
    }

    void update(int i, T value) {
        if (i < length)
            array[i] = value;
        else
            throw NullPointErexception();
    }

    int size() const {
        return length;
    }

    void clear() {
        delete[] array;
        length = 0;
    }

    void remove(int i){
        for (int j = i; j < size() - i; ++j) {
            array[j] = array[j++];
        }
    }

    T &operator[](int i) {
        if (i < length)
            return array[i];
        else
            throw NullPointErexception();
    }

};

#endif //S2LB2_1_ARRAYLIST_H
