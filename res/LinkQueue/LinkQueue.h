//
// Created by lorry on 12/26/18.
//

#include <cassert>
#include <algorithm>

#ifndef ALGORITHM_LINKQUEUE_H
#define ALGORITHM_LINKQUEUE_H

template <typename Object>
class LinkQueue
{
public:
    struct Node
    {
        Object data;
        Node *next;

        explicit Node(const Object & d = Object { }, Node *n = nullptr):
                data{ d }, next{ n } { }

        explicit Node(Object && d, Node *n = nullptr): data{ std::move(d) }, next{ n } { }
    };

public:
    class const_iterator
    {
    public:
        const_iterator(): current { nullptr } { }

        const Object & operator*() const { return retrieve(); }

        const_iterator & operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator & operator++(int)
        {
            auto *old = new const_iterator(this->current);
            ++(*this);
            return *old;
        }

        bool operator==(const const_iterator & rhs) const
        { return current==rhs.current; }

        bool operator!=(const const_iterator & rhs) const
        { return current!=rhs.current; }

    protected:
        Node *current;

        Object & retrieve() const { return current->data; }

        const_iterator(Node *p): current { p } { }

        friend class LinkQueue<Object>;
    };

    class iterator:public const_iterator
    {
    public:
        iterator()= default;

        Object & operator*() { return const_iterator::retrieve(); }

    protected:
        iterator(Node *p): const_iterator{ p } { }

        friend class LinkQueue<Object>;
    };

public:
    LinkQueue()
    {
        front = new Node();
        back = front;
        theSize = 0;
    }

    LinkQueue(const LinkQueue & rhs)
    {
        front = new Node();
        assert(front!=0);

        back = front;
        theSize = 0;

        Node *p = rhs.front->next, *q, *t = front;

        while (p!=nullptr)
        {
            q = new Node(p->data);
            assert(q!=0);
            t = t->next = q;
            p = p->next;
        }

        back = t;
        theSize = rhs.size();
    }

    LinkQueue & operator=(const LinkQueue & rhs)
    {
        if (this==&rhs) return *this;

        clear();

        if (rhs.empty()) return *this;

        Node *p = rhs.front->next, *q, *t = front;

        while (p!=nullptr)
        {
            q = new Node(p->data);
            assert(q!=0);
            t = t->next = q;
            p = p->next;
        }

        back = t;
        theSize = rhs.size();

        return *this;
    }

    ~LinkQueue() { clear(), delete front; }

    /*LinkQueue(LinkQueue && rhs) { }

    LinkQueue & operator=(LinkQueue && rhs) { }*/

public:
    const_iterator begin() const { return { front->next }; }
    iterator begin() { return { front->next }; }

    const_iterator end() const { return { back }; }
    iterator end() { return { back }; }

    bool empty() const { return theSize==0; }

    int size() const { return theSize; }

    void clear()
    {
        Node *p;

        while (front->next != nullptr)
        {
            p = front->next;
            front->next = p->next;
            delete p;
        }
        back = front;
        theSize = 0;
    }

    void push(const Object & object)
    {
        auto *p = new Node(object);
        assert(p!=0);

        back->next = p;
        back = p;
        theSize++;
    }

    void push(Object && object)
    {
        auto *p = new Node(std::move(object));
        assert(p!=0);

        back->next = p;
        back = p;
        theSize++;
    }

    const Object & getFornt() const
    {
        if (empty()) return *(new Object());

        return *begin();
    }

    void pop()
    {
        if (empty()) return;

        Node *p = front->next;
        front->next = p->next;

        theSize--;
        delete p;
    }

    const Object & pop_front()
    {
        if (empty()) return *(new Object());

        Node *p = front->next;
        auto *object = new Object(std::move(p->data));

        front->next = p->next;

        theSize--;

        delete p;

        return *object;
    }

    void erase(iterator & itr)
    {
        Node *p = front, *q = itr.current;
        while (p->next==q)
            p=p->next;
        p->next = q->next;
        delete q;
    }

    void erase(const_iterator & itr)
    {
        Node *p = front, *q = itr.current;
        while (p->next!=q)
            p=p->next;
        p->next = q->next;
        theSize--;

        delete q;

    }

protected:
    Node *front;
    Node *back;

    int theSize;

};

#endif //ALGORITHM_LINKQUEUE_H
