//
// Created by Michael on 10.02.2020.
//

#ifndef S2LB2_1_HUMAN_H
#define S2LB2_1_HUMAN_H


#include <ostream>

class Human {
public:
    std::string value = "Human";
    virtual void show(){
        std::cout << value << std::endl;

    }
};


#endif //S2LB2_1_HUMAN_H
