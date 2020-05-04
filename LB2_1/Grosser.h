//
// Created by Michael on 10.02.2020.
//

#ifndef S2LB2_1_GROSSER_H
#define S2LB2_1_GROSSER_H


#include <ostream>
#include "Human.h"

class Grosser: public Human {
public:
    std::string value = "Grosser";
    virtual void show(){
        std::cout << value << std::endl;

    }
};


#endif //S2LB2_1_GROSSER_H
