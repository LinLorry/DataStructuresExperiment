//
// Created by lorry on 11/9/18.
//

#include "LinkList.h"

#ifndef ALGORITHM_MYLINKLIST_H
#define ALGORITHM_MYLINKLIST_H

template <typename ElemType>
class MyLinkList:public LinkList<ElemType>
{
public:
    void rankLinkList();
    void mergeRepeat();
};

template <typename ElemType>
void MyLinkList<ElemType>::rankLinkList()
{
    typename MyLinkList<ElemType>::NodePointer p = this->head;

    this->head = NULL;

    while(p)
    {
        typename MyLinkList<ElemType>::NodePointer q = p;
        p = p->next;

        if(this->head)
        {
            typename MyLinkList<ElemType>::NodePointer h = this->head;

            if (bigger(q->data, h->data))
                q->next = this->head, this->head = q;
            else
            {
                while (h->next && bigger(h->next->data, q->data))
                    h = h->next;
                q->next = h->next;
                h->next = q;
            }
        }
        else
            this->head = q, q->next = NULL;
    }
}

template <typename ElemType>
void MyLinkList<ElemType>::mergeRepeat()
{
    this->rankLinkList();
    typename MyLinkList<ElemType>::NodePointer p = this->head;


    if (!p)
        return;

    while(p->next)
    {
        if (equal(p->data, p->next->data))
        {
            p->data = p->data + p->next->data;
            typename MyLinkList<ElemType>::NodePointer q = p->next;
            p->next = q->next;
            delete q;
        }
        else
            p = p->next;
    }
}

#endif //ALGORITHM_MYLINKLIST_H
