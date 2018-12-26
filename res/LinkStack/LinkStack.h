//
// Created by lorry on 12/22/18.
//
#include <cassert>

#ifndef ALGORITHM_LINKSTACK_H
#define ALGORITHM_LINKSTACK_H

template <typename Object>
class LinkStack
{
protected:
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object & d = Object { }, Node *n = nullptr):
            data{ d }, next{ n } { }

        Node(Object && d, Node *n = nullptr): data{ std::move(d) }, next{ n } { }
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
            const_iterator *old = new const_iterator(this->current);
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

        friend class LinkStack<Object>;
    };

    class iterator:public const_iterator
    {
    public:
        iterator() { }

        Object & operator*() { return const_iterator::retrieve(); }

    protected:
        iterator(Node *p): const_iterator{ p } { }

        friend class LinkStack<Object>;
    };
public:
    LinkStack()
    {
        top = new Node();
        assert(top!=0);

        base = top;
        theSize = 0;
    }

    LinkStack(const LinkStack & rhs)
    {
        top = new Node();
        assert(top!=0);

        base = top;
        theSize = 0;

        Node *p = rhs.top->next, *q, *t = top;

        while (p!=nullptr)
        {
            q = new Node(p->data);
            assert(q!=0);
            t = t->next = q;
            p = p->next;
        }

        base = t;
        theSize = rhs.size();
    }


    LinkStack & operator=(const LinkStack & rhs)
    {
        if (this==&rhs) return *this;

        clear();

        if (rhs.empty()) return *this;

        Node *p = rhs.top->next, *q, *t = top;

        while (p!=nullptr)
        {
            q = new Node(p->data);
            assert(q!=0);
            t = t->next = q;
            p = p->next;
        }

        base = t;
        theSize = rhs.size();
    }

    ~LinkStack()
    {
        clear();
        delete top;
    }

    const_iterator begin() const{ return { top->next }; }

    iterator begin() { return { top->next }; }

    const_iterator end() const { return { base }; }

    iterator end() { return { base }; }

    bool empty() const { return theSize==0; }

    int size() const { return theSize; }

    void clear()
    {
        Node *p;

        while (top->next != nullptr)
        {
            p = top->next;
            top->next = p->next;
            delete p;
        }
        base = top;
        theSize = 0;
    }

    void push(const Object & x)
    {
        Node *p;
        p = new Node(x, top->next);

        assert(p!=0);

        if (empty()) base = p;

        top->next = p;
        theSize++;
    }

    void push(Object && x)
    {
        Node *p;
        p = new Node(std::move(x), top->next->next);

        assert(p!=0);

        if (empty()) base = p;

        top->next = p;
        theSize++;
    }

    const Object & back() const
    {
        if (empty()) return Object{ };
        return *begin();
    }

    void pop()
    {
        if (empty()) return;

        Node *p = top->next;
        top->next = p->next;
        delete p;
        theSize--;
    }

    const Object & pop_back()
    {
        if (empty()) return Object{ };

        Node *p = top->next;
        top->next = p->next;

        Object *o = new Object(std::move(p->data));

        delete p;
        theSize--;

        return *o;
    }

protected:
    Node *base;
    Node *top;

    int theSize;
};

#endif //ALGORITHM_LINKSTACK_H
