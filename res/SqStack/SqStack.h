//
// Created by lorry on 12/15/18.
//

#include <cassert>

#include "../../include/myhead.h"

#ifndef ALGORITHM_SQSTACK_H
#define ALGORITHM_SQSTACK_H

template <typename Object>
class SqStack
{
public:
    explicit SqStack(int initSize=0) : theSize { initSize }, theCapacity { initSize+ SPARE_CAPACITY }
        { base = new Object[theCapacity]; assert(base!=0); }
    SqStack(const SqStack<Object> & rhs) : theSize { rhs.theSize }, theCapacity { rhs.theCapacity }
    {
        base = new Object[theCapacity];
        assert(base!=0);

        for(int i=0; i<theSize; ++i)
            base[i] = rhs.base[i];
    }

    SqStack & operator=(const SqStack & rhs)
    {
        SqStack copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    virtual ~SqStack() { delete [] base; }

    SqStack(SqStack && rhs) noexcept : theSize { rhs.theSize },
        theCapacity { rhs.theCapacity },
        base { rhs.base }
    {
        rhs.base = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    SqStack & operator=(SqStack && rhs) noexcept
    {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(base, rhs.base);

        return *this;
    }

public:
    void resize(int newSize)
    {
        if(newSize > theCapacity)
            reserve(newSize*2);

        theSize = newSize;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity < theSize)
            return;

        auto *newArray = new Object[newCapacity];
        assert(newArray!=0);
        for(int k=0; k < theSize; ++k)
            newArray[k] = std::move(base[k]);

        theCapacity = newCapacity;
        std::swap(base, newArray);
        delete [] newArray;
    }

    bool empty() const { return theSize == 0; };

    int size() const { return theSize; }

    int capacity() const { return theCapacity; }

    void clear() { theSize = 0; }

    void push_back(const Object & object)
    {
        if (theSize == theCapacity) reserve(2*theCapacity + 1);
        base[theSize++] = object;
    }

    void push_back(Object && object)
    {
        if (theSize == theCapacity) reserve(2*theCapacity + 1);
        base[theSize++] = std::move(object);
    }

    void pop_back() { --theSize; }

    const Object & back() const { return base[theSize-1]; }

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin() { return &base[0]; }
    const_iterator begin() const { return &base[0]; }

    iterator end() { return &base[size()]; }
    const_iterator end() const { return &base[size()]; }

    static const int SPARE_CAPACITY = 16;

protected:
    Object *base;
    int theCapacity;
    int theSize;
};

#endif //ALGORITHM_SQSTACK_H
