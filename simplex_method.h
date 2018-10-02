//
// Created by batman on 02/10/18.
//

#ifndef IEEEXTREME_PREP_SIMPLEX_METHOD_H
#define IEEEXTREME_PREP_SIMPLEX_METHOD_H

#include <Eigen/Dense>
#include <iostream>

class simplex_method {
    int x = 4;
    int y = 4;
    Eigen::Matrix4f constraints;
    Eigen::Vector4f objective_function;

public:
    //TODO:how do I encode inequalities
    //this should determine if there is something in the matrix that needs to be fixed
    //this includes going into standard form
    void solve_initial_iteration();

    void solve_subsequent_iteration();

    void two_phase();

    void big_M();

};


#endif //IEEEXTREME_PREP_SIMPLEX_METHOD_H
