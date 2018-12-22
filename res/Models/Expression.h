//
// Created by lorry on 12/19/18.
//

#ifndef ALGORITHM_EXPRESSION_H
#define ALGORITHM_EXPRESSION_H


class Expression
{
public:
    explicit Expression();
    explicit Expression(char o);
    explicit Expression(float n);
    virtual ~Expression();

    Expression(const Expression & rhs);
    Expression & operator=(const Expression & rhs);

    Expression(Expression && rhs);
    Expression & operator=(Expression && rhs);

public:
    bool isNum() const ;

    void setNum(float num);

    float getNum() const ;

    void setOperator(char oper);

    int getOperator() const;

private:
    short status;
    float num;
};


#endif //ALGORITHM_EXPRESSION_H
