//
// Created by Michael on 24.04.2020.
//

#include "Equation.h"

double Equation::getMinRoot( double a, double b, double eps) {
    double x = a;
    double min = fun(x);
    double result = x;
    while (x < b) {
        double tmp = fun(x);
        if (tmp <= eps && tmp >= eps * -1) {
            min = tmp;
            result = x;
            return result;
        }
        x += eps;
    }
    return result;
}