//
// Created by lorry on 12/26/18.
//

#include <cassert>
#include <algorithm>

#ifndef ALGORITHM_BITREE_H
#define ALGORITHM_BITREE_H

template <typename Object>
class BiTree
{
public:
    struct Node
    {
        Object data;
        Node *left;
        Node *right;

        explicit Node(const Object & d={ }, Node *l= nullptr, Node *r= nullptr):
            data { d }, left { l }, right { r } { }

        explicit Node(Object && d, Node* r = nullptr, Node* l = nullptr):
            data { std::move(d) }, left { l }, right { r } { }
    };

public:
    BiTree()
    {
        init();
    }

    BiTree(const BiTree & rhs)
    {
        init();
    }

    BiTree & operator=(const BiTree & rhs)
    {

    }

    BiTree(BiTree && rhs)
    {
        init();
    }

    BiTree & operator=(BiTree && rhs)
    {

    }

    ~BiTree()
    {
        clear();
    }

    void init() { root = nullptr; }

public:

    void clear() { if(!empty()) deleteNode(root), root=nullptr; }

    bool empty() const { return root==nullptr; }

    const int depth() const { return empty()?0:depth(root); }

    const int countLeaf() const { return empty()?0:countLeaf(root); }

    const int countNode() const { return countNode(root); }

    void exchangeLeftRight() { exchangeLefRight(root); }

    void insert(Object & object) { insert(object, this->root); }

protected:

    const int depth(Node *p) const
    {
        if(p->left!=nullptr && p->right!= nullptr)
        {
            int ld = depth(p->left), rd = depth(p->right);
            return (ld>rd?ld:rd)+1;
        }
        else if(p->left!=nullptr && p->right==nullptr)
            return depth(p->left)+1;
        else if(p->left==nullptr && p->right!=nullptr)
            return depth(p->right)+1;
        else
            return 1;
    }

    const int countLeaf(Node *p) const
    {
        if(p->left!=nullptr && p->right!= nullptr)
            return countLeaf(p->left) + countLeaf(p->right);
        else if(p->left!=nullptr && p->right==nullptr)
            return countLeaf(p->left);
        else if(p->left==nullptr && p->right!=nullptr)
            return countLeaf(p->right);
        else
            return 1;
    }

    const int countNode(Node *p) const
    {
        if(p==nullptr) return 0;
        else return countNode(p->right) + countNode(p->left) + 1;
    }

    void exchangeLefRight(Node *p)
    {
        if(p==nullptr) return;
        Node *t = p->left;
        p->left = p->right;
        p->right = t;

        exchangeLefRight(p->left);
        exchangeLefRight(p->right);
    }

    void insert(Object & object, Node * & p)
    {
        if(p==nullptr)
            p = new Node(object);
        else if(p->left==nullptr || p->right!=nullptr) insert(object, p->left);
        else insert(object, p->right);
    }

    void deleteNode(Node *p)
    {
        if(p->left!=nullptr)
            deleteNode(p->left);

        if(p->right!=nullptr)
            deleteNode(p->right);

        delete p;
    }

protected:
    Node *root;
};

#endif //ALGORITHM_BITREE_H
