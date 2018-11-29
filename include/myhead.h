#include <random>
using std::default_random_engine;

#ifndef MYHEAD_H
#define MYHEAD_H

#define Status bool
#define ERROR false
#define OK true

extern default_random_engine engine;

template <typename ElemType>
Status equal(ElemType i, ElemType j)
{
    if(i == j)
        return OK;
    else
        return ERROR;
}

template <typename ElemType>
Status bigger(ElemType i, ElemType j)
{
    if(i > j)
        return OK;
    else
        return ERROR;
}

template <typename ElemType>
Status smaller(ElemType i, ElemType j)
{
    if(i < j)
        return OK;
    else
        return ERROR;
}

#endif