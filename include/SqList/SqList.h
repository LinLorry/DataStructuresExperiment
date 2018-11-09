#include "../myhead.h"

#ifndef ALGORITHM_SQLIST_H
#define ALGORITHM_SQLIST_H

#define LIST_MAX_SIZE 100
#define LISTINCREMENT 10

template <typename ElemType>
class SqList
{
public:
    int bin_Search(ElemType key);

    void clear();

    Status deleteElem(int i, ElemType & e);

    Status getElem(int i, ElemType & e) const;

    int getLength();

    int getListSize();

    Status insert(int i, ElemType e);

    bool isEmpty();

    int locateElem(ElemType e, Status(*compare)(ElemType, ElemType));

    Status nextElem(ElemType e, ElemType & next_e);

    SqList<ElemType> operator=(SqList<ElemType> rightL);

    Status priorElem(ElemType e, ElemType & prior_e);

    int sequentialSearch(ElemType e);

    SqList();

    virtual ~SqList();

    SqList(const SqList<ElemType> & otherL);

protected:
    ElemType* elem;
    int listSize;
    int n;

};

template <typename ElemType>
int SqList<ElemType>::bin_Search(ElemType key)
{
    int low, mid, hight;

    low = 0, hight = n - 1;
    while (low <= hight)
    {
        mid = (low + hight) / 2;

        if (elem[mid] == key)
            return mid + 1;
        else if (elem[mid] < key)
            low = mid + 1;
        else
            hight = mid - 1;
    }

    return 0;
}

template <typename ElemType>
void SqList<ElemType>::clear()
{
    delete[] elem;
    elem = new ElemType[LIST_MAX_SIZE];
    n = 0;
}

template <typename ElemType>
Status SqList<ElemType>::deleteElem(int i, ElemType & e)
{
    if (i<1 || i>n) return ERROR;

    e = elem[i - 1];
    for (int j = i + 1; j <= n; ++j)
        elem[j - 2] = elem[j - 1];

    --n;
    return OK;
}

template <typename ElemType>
Status SqList<ElemType>::getElem(const int i, ElemType & e) const
{
    if (i<1 || i>n) return ERROR;

    e = elem[i - 1];
    return OK;
}

template <typename ElemType>
int SqList<ElemType>::getLength()
{
    return n;
}

template <typename ElemType>
int SqList<ElemType>::getListSize()
{
    return listSize;
}

template <typename ElemType>
Status SqList<ElemType>::insert(int i, ElemType e)
{
    ElemType* newbase;

    if (i<1 || i>n + 1) return ERROR;

    if (n >= listSize)
    {
        newbase = new ElemType[listSize + LISTINCREMENT];
        cout << "SqList 123";
        assert(newbase != 0);
        cout << "SqList 125";
        for (int j = 1; j <= n; ++j)
            newbase[j - 1] = elem[j - 1];

        delete[] elem;
        elem = newbase;
        listSize += LISTINCREMENT;
    }

    for (int j = n; j >= i; --j)
        elem[j] = elem[j - 1];

    elem[i - 1] = e;
    ++n;
    return OK;
}

template <typename ElemType>
bool SqList<ElemType>::isEmpty()
{
    return n==0 ? false : true;
}

template <typename ElemType>
int SqList<ElemType>::locateElem(ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 1;
    for (; i <= n&&!(*compare)(elem[i - 1], e); ++i);

    if (i <= n)
        return i;
    else
        return 0;
}

template <typename ElemType>
Status SqList<ElemType>::nextElem(ElemType e, ElemType & next_e)
{
    int i = locateElem(e, equal);

    if (i < 1 || i == n)
        return ERROR;
    else
        getElem(i + 1, next_e);
    return OK;
}

template <typename ElemType>
SqList<ElemType> SqList<ElemType>::operator=(SqList<ElemType> righyL)
{
    if (this != &righyL)
    {
        if (listSize < righyL.listSize)
        {
            delete[] elem;
            elem = new ElemType[righyL.listSize];

            assert(elem != 0);
            listSize = righyL.listSize;
        }

        n = righyL.n;
        for (int i = 1; i <= n; ++i)
            elem[i - 1] = righyL.elem[i - 1];
    }

    return *this;
}

template <typename ElemType>
Status SqList<ElemType>::priorElem(ElemType e, ElemType & prior_e)
{
    int i = locateElem(e, equal);

    if (i <= 1)
        return ERROR;
    else
        getElem(i - 1, prior_e);

    return OK;
}

template <typename ElemType>
int SqList<ElemType>::sequentialSearch(ElemType key)
{
    int i = 1;

    for (; i <= n && key != elem[i - 1]; ++i);

    if (i <= n)
        return i;
    else
        return 0;
}

template <typename ElemType>
SqList<ElemType>::SqList()
{
    elem = new ElemType[LIST_MAX_SIZE];
    assert(elem != 0);
    listSize = LIST_MAX_SIZE;
    n = 0;
}

template <typename ElemType>
SqList<ElemType>::~SqList()
{
    delete[] elem;
}

template <typename ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> & otherL)
{
    elem = new ElemType[otherL.listSize];

    assert(elem != 0);
    listSize = otherL.listSize;
    n = otherL.n;

    for (int i = 1; i <= n; ++i)
        elem[i - 1] = otherL.elem[i - 1];
}
#endif