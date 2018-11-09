//
// Created by lorry on 11/9/18.
//

#include <iostream>
using namespace std;

#include "MyTerm.h"

void MyTerm::read(istream &in)
{
    cout << "";

    while (!(in>>coef))
        cout << "" << endl;

    cout << "\t";
    in >> expn;
    cout << endl;

}

void MyTerm::display(ostream &out)
{
    if (coef != 1)
        out << coef;
    else
        out << "x" << expn;
}

istream & operator>> (istream & in, MyTerm & s)
{
    s.read(in);
    return in;
}

ostream & operator<< (ostream & out, MyTerm & s)
{
    s.display(out);
    return out;
}
