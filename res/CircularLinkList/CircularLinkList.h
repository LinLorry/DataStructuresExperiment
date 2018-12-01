//
// Created by lorry on 11/29/18.
//

#include <cassert>

#include "../../include/myhead.h"

#ifndef ALGORITHM_CIRCULARLINKLIST_H
#define ALGORITHM_CIRCULARLINKLIST_H

template <typename Object>
class CircularLinkList
{
public:
    struct Node
    {
        Object data;
        Node* next;
    };

    typedef Node* NodePointer;

    class const_iterator
    {
    public:
        const_iterator() : current { nullptr } { }

        const Object & operator*() const { return retrieve(); }

        const_iterator & operator++()
        {
            current = current->next;
            return  *this;
        }

        const_iterator operator++( int )
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

        explicit const_iterator(NodePointer p) : current { p } { }

        friend class CircularLinkList<Object>;

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
        explicit iterator(NodePointer p):const_iterator { p } { }

        friend class CircularLinkList<Object>;
    };

public:

    iterator begin() { return iterator(head); }
    const_iterator begin() const { return const_iterator(head); }

    bool empty() const { return head==nullptr; }

    int size() const
    {
        int i = 1;
        NodePointer p = head;

        if (p == nullptr) return 0;

        while(p->next!=head)
            ++i, p = p->next;

        return i;
    }

    /*
     * This Function is use clear this CircularLinkList.
     */
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
    }

    /*
     * Insert one element into list.
     * Return const_iterator which is object.
     */
    const_iterator & insert(int i, Object & object)
    {
        auto iterator =  new const_iterator(nullptr);
        assert(iterator!=0);

        NodePointer p = head;

        if (i < 0) return *iterator; // If input i is error, return ERROR.

        if (i==0) // If want to insert element to replace head.
        {
            auto s = new Node();
            assert(s!=0);

            if (head == nullptr) // If this list is empty.
            {
                s->data = object;
                s->next = s;
            }
            else
            {
                while (p->next!=head)
                    p = p->next;

                s->data = object;
                p->next = s;
                s->next = head;
            }

            head = s;

            delete iterator;
            iterator = new const_iterator(s);
            assert(iterator!=0);

            return *iterator;
        }

        /*
         * move p pointer before insert element.
         * If i bigger than list length, break.
         */
        while(i>1 && p->next!=head)
            p = p->next, --i;

        if(i>1) return *iterator;
        else
        {
            auto s = new Node();
            assert(s!=0);

            s->data = object;
            s->next = p->next;
            p->next = s;

            delete iterator;
            iterator = new const_iterator(s);
            assert(iterator!=0);
            return *iterator;
        }
    }

    /*
     * Delete the Node while locate i and give data to object.
     */
    Status erase(int i, Object & object)
    {
        NodePointer r =nullptr, p = head;

        if (i<0 || head == nullptr) return ERROR; // If input i is error or list is empty return ERROR.


        if (i==0) // If i is 0, delete the head.
        {
            if (head->next == head) // If list only have one element.
            {
                object = head->data;
                delete head;
                head = nullptr;
                return OK;
            }
            else
            {
                while(p->next!=head) // move pointer to last Node.
                    p=p->next;

                p->next = head->next;
                object = head->data;
                delete head;
                head = p->next;
                return OK;
            }

        }

        /*
         * If i isn't 0
         * Move pointer to Node will be delete and make r is p front pointer.
         */
        while(i>0 && p->next != head)
        {
            r = p;
            p = p->next;
            --i;
        }

        if (i>0) return ERROR; // If i bigger than list length, return ERROR.
        else
        {
            r->next = p->next;

            object = p->data;
            delete p;
            return OK;
        }
    }

    Status moveHead(int i)
    {
        NodePointer p=head;

        if (i<0 || head == nullptr) return ERROR; // If input i is error or list is empty return ERROR.

        while (i>0 && p->next!=head) // Move p to pointer number of i after head.
            p = p->next, --i;

        if (i>0) return ERROR; // If i bigger than list length, return ERROR.
        else head = p;

        return OK;
    }



public:
    CircularLinkList<Object> & operator= (const CircularLinkList<Object> & rightL)
    {
        NodePointer p = NULL, q = rightL.head;
        NodePointer s;

        if (this == &rightL) return *this;

        clear();

        if (rightL.empty()) return *this;

        do
        {
            s = new Node();
            assert(s!=0);

            s->data = q->data;

            if (head == nullptr)
            {
                head = s;
                s->next = s;

                p = head;
            }
            else
            {
                s->next = p->next;
                p->next = s;

                p = p->next;
            }
            q = q->next;
            q = q->next;
        }
        while(q!=rightL.head);

        return *this;

    }

    CircularLinkList<Object> & operator= (CircularLinkList<Object> && rightL)
    {
        NodePointer p = NULL, q = rightL.head;
        NodePointer s;

        if (*this == rightL) return *this;

        clear();

        if (rightL.empty()) return *this;

        do
        {
            s = new Node();
            assert(s!=0);

            s->data = q->data;

            if (head == nullptr)
            {
                head = s;
                s->next = s;

                p = head;
            }
            else
            {
                s->next = p->next;
                p->next = s;

                p = p->next;
            }

            q = q->next;
        }
        while(q!=rightL.head);
    }

    CircularLinkList() { head = nullptr; }
    CircularLinkList(const CircularLinkList & otherL)
    {
        NodePointer p = NULL, q = otherL.head;
        NodePointer s;

        if (otherL.empty())
        {
            head = nullptr;
            return;
        }

        head = nullptr;

        do
        {
            s = new Node();
            assert(s!=0);

            s->data = q->data;

            if (head == nullptr)
            {
                head = s;
                s->next = s;

                p = head;
            }
            else
            {
                s->next = p->next;
                p->next = s;

                p = p->next;
            }
            q = q->next;
        }
        while(q!=otherL.head);
    }

    virtual ~CircularLinkList() { clear(); }

protected:
    NodePointer head;
};

#endif //ALGORITHM_CIRCULARLINKLIST_H
