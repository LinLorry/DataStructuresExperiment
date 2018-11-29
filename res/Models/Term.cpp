//
// Created by lorry on 11/23/18.
//

#include <iostream>
using namespace std;

#include "../../include/myhead.h"
#include "Term.h"

Term::Term():coef{0}, expn{0} { }
Term::Term(const int expn, const float coef):expn{expn}, coef{coef} { }
Term::~Term() =default;

void Term::setCoef(float coef) { this->coef = coef; }
void Term::setExpn(int expn) { this->expn = expn; }

float Term::getCoef() const { return coef; }
int Term::getExpn() const { return expn; }

Term & Term::operator=(const Term &t)
{
    this->setExpn(t.getExpn());
    this->setCoef(t.getCoef());

    return *this;
}

Term & Term::operator+(const Term & t)
{
    this->setExpn(this->getExpn() + t.getExpn());
    return *this;
}

void Term::read(istream &in)
{
    cout << "";

    while (!(in>>coef))
        cout << "" << endl;

    cout << "\t";
    in >> expn;
    cout << endl;

}

void Term::display (ostream &out) const
{
    out << getExpn() << "X";
    if(getCoef()!=1) out << "^" << getCoef();
}

istream & operator>> (istream & in, Term & term)
{
    term.read(in);
    return in;
}

ostream & operator<< (ostream & out, const Term & term)
{
    term.display(out);
    return out;
}

Status equal(const Term & i, const Term & j)
{
    if(i.getCoef() == j.getCoef())
        return OK;
    else
        return ERROR;
}

Status bigger(const Term & i, const Term & j)
{
    if (i.getCoef() > j.getCoef())
        return OK;
    else
        return ERROR;
}
