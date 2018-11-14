//
// Created by lorry on 11/9/18.
//

#include "../myhead.h"

#ifndef ALGORITHM_LINKLIST_H
#define ALGORITHM_LINKLIST_H

template <typename ElemType>
class LinkList
{
public:
    class LinkNode
    {
    public:
        ElemType data;
        LinkNode* next;
    };
    typedef LinkNode* NodePointer;

    void adverse();

    void clear();

    Status deleteElem(ElemType e);

    void deleteRepeat();

    Status getElem(int i, ElemType & e);

    NodePointer getHead();

    int getLength();

    Status insert(int i, ElemType e);

    bool isEmpty();

    Status locateElem(ElemType e, Status (*compare)(ElemType, ElemType), int & i);

    Status nextElem(ElemType e, ElemType & next_e);

    LinkList<ElemType> operator= (LinkList<ElemType> rightL);

    Status priorElem(ElemType e, ElemType & prior_e);

    LinkList();
    virtual  ~LinkList();
    LinkList(const LinkList<ElemType> & otherL);

protected:
    NodePointer head;
};

template <typename ElemType>
void LinkList<ElemType>::adverse()
{
    NodePointer r, p, q;

    if (!head)
        return;

    r = NULL, p = head, q = p->next;
    while(p)
    {
        p->next = r;
        r = p;
        p = q;
        if (q)
            q = q->next;
    }

    head = r;
}

template <typename ElemType>
void LinkList<ElemType>::clear()
{
    NodePointer p, q = head;

    while (q)
    {
        p = q;
        q = q->next;
        delete p;
    }

    head = NULL;
}

template <typename ElemType>
Status LinkList<ElemType>::deleteElem(ElemType e)
{
    NodePointer r = NULL, p = head;

    while (p && !equal(p->data, e))
        r = p, p = p->next;

    if(p == NULL)
        return ERROR;
    if(r == NULL)
        head = head->next;
    else
        r->next = p->next;

    free(p);
    return OK;
}

template <typename ElemType>
void LinkList<ElemType>::deleteRepeat()
{
    NodePointer p, q = head, s = q->next;

    while (s)
    {
        p = head;
        while (p != s)
        {
            if (equal(p->data, s->data))
            {
                q->next = s->next;
                delete s;
                s = q;
                break;
            }
            p = p->next;
        }
        q = s;
        s = s->next;
    }
}

template <typename ElemType>
Status LinkList<ElemType>::getElem(int i, ElemType & e)
{
    int j = 1;
    NodePointer p = head;

    while (p && j<i)
        p = p->next, ++j;

    if (!p || j>i)
        return ERROR;

    e = p->data;
    return OK;
}

template <typename ElemType>
typename LinkList<ElemType>::LinkNode* LinkList<ElemType>::getHead()
{
    return head;
}

template <typename ElemType>
int LinkList<ElemType>::getLength()
{
    int n = 0;
    NodePointer p = head;

    while (p)
        ++n, p = p->next;

    return n;
}

template <typename ElemType>
Status LinkList<ElemType>::insert(int i, ElemType e)
{
    int j = 0;
    NodePointer p = head;
    NodePointer s;

    if (i < 1)
        return ERROR;

    while (p && j<i-1)
        ++j, p = p->next;

    s = new LinkNode();
    s->data = e;

    s->next = p->next;
    p->next = s;

    return OK;


    /*int  j = 1;
    NodePointer p = head;
    NodePointer s;

    while (p && j<i-1)
        ++j, p = p->next;

    if (!p || j>i)
        return ERROR;

    s = new LinkNode;
    assert(s!=0);

    s->data = e;

    if (i==1)
    {
        s->next = head;
        head = s;
    }
    else
    {
        s->next = p->next;
        p->next = s;
    }

    return OK;*/
}

template <typename ElemType>
bool LinkList<ElemType>::isEmpty()
{
    return (head? false:true);
}

template <typename ElemType>
Status LinkList<ElemType>::locateElem(ElemType e, Status (*compare) (ElemType, ElemType), int &i)
{
    NodePointer p = head;
    i = 1;

    while (p && !(*compare)(p->data, e))
        ++i, p=p->next;

    if (!p) return ERROR;

    return OK;
}

template <typename ElemType>
Status LinkList<ElemType>::nextElem(ElemType e, ElemType &next_e)
{
    NodePointer p = head;

    while (p && !equal(p->data, e))
        p = p->next;

    if (!p || !p->next)
        return ERROR;

    next_e = p->next->data;

    return OK;
}

template <typename ElemType>
LinkList<ElemType> LinkList<ElemType>::operator=(LinkList<ElemType> rightL)
{
    NodePointer p = NULL;
    NodePointer rp = rightL.getHead();

    NodePointer s;

    if(this != &rightL)
    {
        clear();
        while (rp)
        {
            s = new LinkNode;
            assert(s != 0);

            s->data = rp->data;

            if (!head)
                head = s;
            else
                p->next = s;

            p = s;
            p = p->next;
        }

        if (p)
            p->next = NULL;
    }

    return *this;
}

template <typename ElemType>
Status LinkList<ElemType>::priorElem(ElemType e, ElemType &prior_e)
{
    NodePointer r = NULL;
    NodePointer p = head;

    while (p && !equal(p->data, e))
        r = p, p = p->next;

    if (!p||!r)
        return ERROR;

    prior_e = r->data;
    return OK;
}

template <typename ElemType>
LinkList<ElemType>::LinkList()
{
    head = new LinkNode();
    assert(head!=0);
}

template <typename ElemType>
LinkList<ElemType>::~LinkList() { clear(); }

template <typename ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> & otherL)
{
    NodePointer p;
    NodePointer op = otherL.head;

    NodePointer s;

    head = p = NULL;

    while (op)
    {
        s = new LinkNode;
        assert(s != 0);

        s->data = op->data;

        if (!head)
            head = s;
        else
            p->next = s;

        p = s;
        op = op->next;
    }

    if (head)
        p->next = NULL;
}

#endif //ALGORITHM_LINKLIST_H
