//
// Created by lorry on 12/19/18.
//
#include <iostream>

#include "Expression.h"

Expression::Expression()=default;
Expression::Expression(char o): status { 1 } { this->setOperator(o); }
Expression::Expression(float n): num { n }, status { 0 } { }
Expression::~Expression()=default;

Expression::Expression(const Expression & rhs): status { rhs.status }, num { rhs.num } { }

Expression & Expression::operator=(const Expression & rhs)
{
    Expression copy = rhs;
    std::swap(*this, copy);
    return *this;
}

Expression & Expression::operator=(Expression && rhs)
{
    std::swap(status, rhs.status);
    std::swap(num, rhs.num);

    return *this;
}

Expression::Expression(Expression && rhs): status { rhs.status }, num { rhs.num } { }


bool Expression::isNum() const { return this->status==0; }

void Expression::setNum(float num) { this->num = num; }
float Expression::getNum() const { return this->num; }

void Expression::setOperator(char oper)
{
    switch(oper)
    {
        case '+':
            this->num = 1;
            break;
        case '-':
            this->num = 2;
            break;
        case '*':
            this->num = 3;
            break;
        case '/':
            this->num = 4;
            break;
        case '(':
            this->num = 5;
            break;
        case ')':
            this->num = 6;
            break;
        default:
            this->num = 0;
            break;
    }
}
int Expression::getOperator() const { return (int)this->num; }
