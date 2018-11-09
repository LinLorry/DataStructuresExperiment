//
// Created by lorry on 10/19/18.
//

#include "MySqList.h"

#ifndef ALGORITHM_MYSETSQLIST_H
#define ALGORITHM_MYSETSQLIST_H

template <typename ElemType>
MySqList<ElemType> unionSet (MySqList<ElemType> firstL, MySqList<ElemType> secondL)
{
    ElemType e;
    MySqList<ElemType> thirdL(firstL);

    for(int i=1; i <= secondL.getLength(); ++i)
    {
        secondL.getElem(i, e);
        if(!firstL.locateElem(e, equal))
        {
            thirdL.insert(thirdL.getLength()+1, e);
        }
    }

    return thirdL;
}

template <typename ElemType>
MySqList<ElemType> insersetionSet(MySqList<ElemType> firstL, MySqList<ElemType> secondL)
{
    int k=0;
    ElemType e;
    MySqList<ElemType> thirdL;

    for (int i = 1; i <= firstL.getLength(); ++i)
    {
        firstL.getElem(i, e);
        if(secondL.locateElem(e, equal))
        {
            thirdL.insert(++k, e);
        }
    }

    return thirdL;
}

template <typename ElemType>
MySqList<ElemType> dirfferenceSet(MySqList<ElemType> firstL, MySqList<ElemType> secondL)
{
    int k=0;
    ElemType e;
    MySqList<ElemType> thirdL;

    for(int i=1; i <= firstL.getLength(); ++i)
    {
        firstL.getElem(i, e);
        if(!secondL.locateElem(e, equal))
        {
            thirdL.insert(++k, e);
        }
    }
    return thirdL;
}

#endif //ALGORITHM_MYSETSQLIST_H
