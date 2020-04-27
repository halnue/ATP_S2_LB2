//
// Created by Michael on 24.04.2020.
//

#ifndef S2LB2_1_EQUATION_H
#define S2LB2_1_EQUATION_H


class Equation {

    virtual double fun(double x);

public:
    double getMinRoot(double a, double b, double eps);
};


#endif //S2LB2_1_EQUATION_H
