//
// Created by lorry on 11/9/18.
//

#include <iostream>
using namespace std;

#ifndef ALGORITHM_MYTERM_H
#define ALGORITHM_MYTERM_H

class MyTerm
{
public:
    void read(istream & in);
    void display(ostream & out);

public:
    float coef;
    int expn;
};

#endif //ALGORITHM_MYTERM_H
