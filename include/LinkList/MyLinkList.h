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

#endif //ALGORITHM_MYLINKLIST_H
