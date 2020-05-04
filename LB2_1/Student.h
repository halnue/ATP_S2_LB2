//
// Created by Michael on 10.02.2020.
//

#ifndef S2LB2_1_STUDENT_H
#define S2LB2_1_STUDENT_H


#include <ostream>

class Student : public Grosser{
public:
    std::string value = "Student";
    virtual void show(){
        std::cout << value << std::endl;

    }
};


#endif //S2LB2_1_STUDENT_H
