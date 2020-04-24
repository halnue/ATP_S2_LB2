//
// Created by Michael on 10.02.2020.
//

#ifndef S2LB2_1_SPROBOTNIK_H
#define S2LB2_1_SPROBOTNIK_H


#include <ostream>

class Sprobotnik: public Grosser {
public:
    std::string value = "Sprobotnik";
    virtual void show();
};


#endif //S2LB2_1_SPROBOTNIK_H
