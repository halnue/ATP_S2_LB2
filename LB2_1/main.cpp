#include <iostream>
#include "Grosser.cpp"
#include "Human.cpp"
#include "Sprobotnik.cpp"
#include "Student.cpp"

int main() {
    Human *array[4]{
        new Human(),
        new Grosser(),
        new Sprobotnik(),
        new Student()
    };
    for (int i = 0; i < 4; ++i) {
        array[i]->show();
    }

    return 0;
}
