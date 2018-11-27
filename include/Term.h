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
    void setExpn(int expn);

    float getCoef() const;
    int getExpn() const;

public:
    Term & operator=(const Term & t);
    void read(istream & in);
    void display (ostream & out) const;

private:
    float coef;
    int expn;
};

extern Status bigger(const Term & i, const Term & j);


#endif //ALGORITHM_TERM_H
