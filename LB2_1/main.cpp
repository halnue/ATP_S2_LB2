#include <iostream>
#include "Grosser.h"
//#include "Human.h"
#include "Sprobotnik.h"
#include "Student.h"

int main() {
    Human *list[4]{
        new Human(),
        new Grosser(),
        new Sprobotnik(),
        new Student()
    };
    for (int i = 0; i < 4; ++i) {
        list[i]->show();
    }

    return 0;
}
