//
// Created by Michael on 24.04.2020.
//

#ifndef S2LB2_1_QUADRATICEQUATION_H
#define S2LB2_1_QUADRATICEQUATION_H

#include <cmath>
#include "Equation.h"

class QuadraticEquation: public Equation {
    double fun(double x){
        return sin(x);
    }
};


#endif //S2LB2_1_QUADRATICEQUATION_H
