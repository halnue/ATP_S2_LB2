//
// Created by Michael on 14.02.2020.
//

#ifndef S2LB1_2_LISTINT_CPP
#define S2LB1_2_LISTINT_CPP

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

    ArrayList(int width,int height, ArrayList<T> *arrayInt) {
        int maxSize = width * 2;
        array = new ArrayList<T>[maxSize];
        maxLength = maxSize;
        length = 0;
        for (int i = 0; i < width; ++i) {
            add(ArrayList<T>(height,arrayInt[i]));
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


#endif //S2LB1_2_LISTINT_CPP
