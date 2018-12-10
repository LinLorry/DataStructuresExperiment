//
// Created by lorry on 12/7/18.
//

#include <cassert>

#include "../../include/myhead.h"

#ifndef ALGORITHM_DOUBLELINKLIST_H
#define ALGORITHM_DOUBLELINKLIST_H

template <typename Object>
class DoubleLinkList
{
protected:
    struct Node
    {
        Object data;
        Node* prev;
        Node* next;

        explicit Node(const Object & d = Object { }, Node* p = nullptr, Node* n = nullptr)
            : data { d }, prev { p }, next { n } { }

        explicit Node(Object && d, Node* p = nullptr, Node* n = nullptr)
            : data { std::move(d) }, prev { p }, next { n } { }
    };
    typedef Node* NodePointer;

public:
    class const_iterator
    {
    public:
        const_iterator() : current { nullptr } { }

        virtual const Object & operator*() const { return retrieve(); }

        virtual const_iterator & operator++()
        {
            current = current->next;
            return  *this;
        }

        virtual const_iterator operator++( int )
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator & rhs) const { return current == rhs.current; }
        bool operator!=(const const_iterator & rhs) const { return current != rhs.current; }

    protected:
        NodePointer current;

        Object & retrieve() const { return current->data; }

        const_iterator(NodePointer p) : current { p } { }

        friend class DoubleLinkList<Object>;

    };

    class iterator : public const_iterator
    {
    public:
        iterator()= default;

        Object & operator*() { return const_iterator::retrieve(); }
        const Object & operator*() const { return const_iterator::operator*(); }

        iterator & operator++()
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++( int )
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(NodePointer p):const_iterator { p } { }

        friend class DoubleLinkList<Object>;
    };

public:
    DoubleLinkList() { head = nullptr, theSize = 0; }
    DoubleLinkList(const DoubleLinkList & doubleLinkList)
    {
        NodePointer p = nullptr, q = doubleLinkList.head;
        NodePointer s;
        theSize = 0;
        head = nullptr;

        if (doubleLinkList.empty()) return ;

        do
        {
            if(head == nullptr)
            {
                s = new Node(q->data);
                assert(s!=0);

                head = s;
                s->next = head;
                s->prev = head;
                p = head;
            }
            else
            {
                s = new Node(q->data, p->next, p);
                assert(s!=0);

                p->next = s;
                p = p->next;
            }
            ++theSize;
            q = q->next;
        }
        while (q->next != doubleLinkList.head);
    }

    DoubleLinkList(DoubleLinkList && doubleLinkList)
    {
        NodePointer p = nullptr, q = doubleLinkList.head;
        NodePointer s;
        theSize = 0;
        head = nullptr;

        if (doubleLinkList.empty()) return ;

        do
        {
            if(head == nullptr)
            {
                s = new Node(q->data);
                assert(s!=0);

                head = s;
                s->next = head;
                s->prev = head;
                p = head;
            }
            else
            {
                s = new Node(q->data, p->next, p);
                assert(s!=0);

                p->next = s;
                p = p->next;
            }
            ++theSize;
            q = q->next;
        }
        while (q->next != doubleLinkList.head);
    }

    virtual ~DoubleLinkList() { }

    DoubleLinkList & operator=(const DoubleLinkList & rightList)
    {
        NodePointer p = nullptr, q = rightList.head;
        NodePointer s;

        if (this == &rightList) return *this;

        clear();

        if (rightList.empty()) return *this;

        do
        {
            if(head == nullptr)
            {
                s = new Node(q->data);
                assert(s!=0);

                head = s;
                s->next = head;
                s->prev = head;
                p = head;
            }
            else
            {
                s = new Node(q->data, p->next, p);
                assert(s!=0);

                p->next = s;
                p = p->next;
            }
            ++theSize;
            q = q->next;

        }
        while (q->next != rightList.head);

        return *this;
    }
    DoubleLinkList & operator=(DoubleLinkList && rightList)
    {
        NodePointer p = nullptr, q = rightList.head;
        NodePointer s;

        if (this == &rightList) return *this;

        clear();

        if (rightList.empty()) return *this;

        do
        {
            if(head == nullptr)
            {
                s = new Node(q->data);
                assert(s!=0);

                head = s;
                s->next = head;
                s->prev = head;
                p = head;
            }
            else
            {
                s = new Node(q->data, p->next, p);
                assert(s!=0);

                p->next = s;
                p = p->next;
            }
            ++theSize;
            q = q->next;

        }
        while (q->next != rightList.head);

        return *this;
    }

    iterator begin() { return iterator(head); }
    const_iterator begin() const { return { head }; }

    iterator end() { return { head->prev }; }
    iterator end() const { return { head->prev }; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear()
    {
        if (head == nullptr)
            return;

        NodePointer p; // New a Node pointer.

        /*
         * Delete Node except head.
         */
        while (head!=head->next) // While this list only have head.
        {
            p = head->next;
            head->next = p->next;
            delete p;// If i bigger than list length, return ERROR.
        }

        delete head; // Delete the head.
        head = nullptr;
        theSize = 0;
    }

    const_iterator & insert(int i, const Object & x)
    {
        auto iterator =  new const_iterator(nullptr);
        assert(iterator!=0);

        NodePointer p = head;

        if (i < 0) return *iterator; // If input i is error, return ERROR.

        if (i==0) // If input i is 0, insert a head or change head.
        {
            auto s = new Node(x);

            if (!head) // If head is Nullptr, insert a head.
            {

                assert(s != 0);

                s->next = s;
                s->prev = s;
            }
            else // If head is e, insert a Node and change head.
            {
                s = new Node(x);
                assert(s != 0);

                s->next = head;
                s->prev = head->prev;

                head->prev->next = s;
                head->prev = s;
            }
            head = s;

            delete iterator;
            iterator = const_iterator(s);
            assert(iterator!=0);

            return *iterator;
        }

        do
            p = p->next;
        while (--i>0 && p->next!=head);

        if (i==0)
        {
            auto s = new Node(x, p->prev, p->next);
            p->prev->next = s;
            p->prev = s;

            delete iterator;
            iterator = new const_iterator(s);
            assert(iterator!=0);
        }

        return *iterator;
    }

    Status erase(int i, Object & object)
    {
        NodePointer p = head;

        if (i<0 || head == nullptr) return ERROR; // If i < 0 or link list is null, return ERROR.

        if (i==0)
        {
            head = p->next;

            p->next->prev = p->prev;
            p->prev->next = p->next;

            delete p;
            return OK;
        }

        do
            p = p->next;
        while (--i>0 && p->next!=head);

        if (i > 0) return ERROR;
        else
        {
            p->next->prev = p->prev;
            p->prev->next = p->next;

            delete p;
            return OK;
        }
    }

protected:
    NodePointer head;
    int theSize;
};

#endif //ALGORITHM_DOUBLELINKLIST_H
