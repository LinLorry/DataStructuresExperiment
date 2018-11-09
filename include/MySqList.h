//
// Created by lorry on 10/19/18.
//

#include "SqList.h"

#ifndef ALGORITHM_MYSQLIST_H
#define ALGORITHM_MYSQLIST_H

template <typename ElemType>
class MySqList: public SqList<ElemType>
{
public:
    void read(istream & in);

    void display(ostream & out) const;
};

template <typename ElemType>
void MySqList<ElemType>::read(istream &in)
{
    int i;
    ElemType e;
    cout << "\t\t插入到第几个：";
    in >> i;
    cout << "\t\t要插入的数据：";
    in >> e;
    if(!this->insert(i, e))
    {
        cout << "\t\tMySqList 30" << endl;
    }
    cout << "\t\tMySqList 32" << endl;
}

template <typename ElemType>
void MySqList<ElemType>::display(ostream &out) const
{
    ElemType e;
    for(int i=1; i <= this->n; ++i)
    {
        out << "\t[" << i << "]";
    }
    out << endl;
    for(int i=1; i <= this->n; ++i)
    {
        this->getElem(i, e);
        out << "\t" << e;
    }
    out << "\n";
}

template <typename ElemType>
istream & operator>>(istream & in, MySqList<ElemType> & iS)
{
    iS.read(in);
    return in;
}

template <typename ElemType>
istream & operator>>(istream & in, MySqList<ElemType> && iS)
{
    iS.read(in);
    return in;
}

template <typename ElemType>
ostream & operator<<(ostream & out, const MySqList<ElemType> & oS)
{
    oS.display(out);
    return out;
}

template <typename ElemType>
ostream & operator<<(ostream & out, const MySqList<ElemType> && oS)
{
    oS.display(out);
    return out;
}

#endif //ALGORITHM_MYSQLIST_H
