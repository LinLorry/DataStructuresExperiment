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

    Status getElem(int i, ElemType & e) const;

    NodePointer getElem(int i) const;

    NodePointer getHead() const;

    int getLength() const;

    Status insert(int i, ElemType e);

    bool isEmpty() const;

    Status locateElem(ElemType e, Status (*compare)(ElemType, ElemType), int & i) const;

    Status nextElem(ElemType e, ElemType & next_e) const;
    Status priorElem(ElemType e, ElemType & prior_e) const;

    LinkList<ElemType> & operator= (const LinkList<ElemType> & rightL);
    LinkList<ElemType> & operator= (LinkList<ElemType> && rightL);

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
Status LinkList<ElemType>::getElem(int i, ElemType & e) const
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

template  <typename ElemType>
typename LinkList<ElemType>::NodePointer LinkList<ElemType>::getElem(int i) const
{
    NodePointer p = head;

    while (--i>0 && p)
        p = p->next;

    if(!p)
        return NULL;

    return p;
}

template <typename ElemType>
typename LinkList<ElemType>::NodePointer LinkList<ElemType>::getHead() const { return head; }

template <typename ElemType>
int LinkList<ElemType>::getLength() const
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
    LinkNode linkNode;
    NodePointer p = &linkNode, q = &linkNode;
    NodePointer s;

    //if input i is error return ERROR.
    if (i < 1 || (i!=1 && !head))
        return ERROR;

    //make linkNode next is head and move p to be location before insert.
    p->next = head;
    while (i-->1 && p)
        p = p->next;

    if (!p || i>1)
        return ERROR;

    s = new LinkNode();
    assert(s!=0);
    s->data = e;

    s->next = p->next;
    p->next = s;
    head = q->next;

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
bool LinkList<ElemType>::isEmpty() const { return head!=NULL; }

template <typename ElemType>
Status LinkList<ElemType>::locateElem(ElemType e, Status (*compare) (ElemType, ElemType), int &i) const
{
    NodePointer p = head;
    i = 1;

    while (p && !(*compare)(p->data, e))
        ++i, p=p->next;

    if (!p) return ERROR;

    return OK;
}

template <typename ElemType>
Status LinkList<ElemType>::nextElem(ElemType e, ElemType &next_e) const
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
Status LinkList<ElemType>::priorElem(ElemType e, ElemType &prior_e) const
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
LinkList<ElemType> & LinkList<ElemType>::operator=(const LinkList<ElemType> & rightL)
{
    NodePointer p, s;
    NodePointer rp = rightL.getHead();

    clear();

    while (rp)
    {
        s = new LinkNode();
        assert(s!=0);
        s->data = rp->data;

        if(!head)
        {
            head = p = s;
        }
        else
        {
            p->next = s;
            p = p->next;
        }
        rp = rp->next;
    }

    if(p)
        p->next = NULL;

    return *this;


    /*NodePointer q = new LinkNode();
    assert(q!=0);

    NodePointer p = q;
    NodePointer rp = rightL.head;

    NodePointer s;

    clear();

    while (rp)
    {
        s = new LinkNode();
        assert(s!=0);
        s->data = rp->data;

        p->next = s;
        p = p->next;
        rp = rp->next;
    }
    p->next = NULL;

    head = q->next;

    return *this;*/
}

template <typename ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator=(LinkList<ElemType> &&rightL)
{
    NodePointer q = new LinkNode();
    assert(q!=0);

    NodePointer p = q;
    NodePointer rp = rightL.head;

    NodePointer s;

    clear();

    while (rp)
    {
        s = new LinkNode();
        assert(s!=0);
        s->data = rp->data;
        rp = rp->next;
        p->next = s;
        p = p->next;
    }
    p->next = NULL;

    head = q->next;

    return *this;
}



template <typename ElemType>
LinkList<ElemType>::LinkList() { head = NULL; }

template <typename ElemType>
LinkList<ElemType>::~LinkList() { clear(); }

template <typename ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &otherL)
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

    if (head && p!=NULL)
        p->next = NULL;
}

#endif //ALGORITHM_LINKLIST_H
