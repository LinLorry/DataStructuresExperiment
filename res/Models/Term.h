//
// Created by lorry on 11/23/18.
//

#include <iostream>
using namespace std;

#ifndef ALGORITHM_TERM_H
#define ALGORITHM_TERM_H

class Term
{
public:
    Term();
    Term(const int expn, const float coef);
    virtual ~Term();

public:
    void setCoef(float coef);
    float getCoef() const;

    void setExpn(int expn);
    int getExpn() const;

public:
    Term & operator=(const Term & t);
    Term & operator+(const Term & t);
    void read(istream & in);
    void display (ostream & out) const;

private:
    float coef;
    int expn;
};

extern Status equal(const Term & i, const Term & j);
extern Status bigger(const Term & i, const Term & j);

#endif //ALGORITHM_TERM_H
