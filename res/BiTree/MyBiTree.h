//
// Created by lorry on 12/27/18.
//

#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "BiTree.h"

using std::string;
using std::to_string;
using std::vector;
using std::stack;
using std::queue;

#ifndef ALGORITHM_MYBITREE_H
#define ALGORITHM_MYBITREE_H

template <typename Object>
class MyBiTree:public BiTree<Object>
{
public:
    const string preOrderTraverse() const { return preOrderTraverse(this->root); }
    const string infixOrderTraverse() const { return infixOrderTraverse(this->root); }
    const string afterOrderTraverse() const { return afterOrderTraverse(this->root); }

    const string nonRecursiveInfixOrderTraverse() const
    {
        if(this->empty()) return {};
        string str;
        typename BiTree<Object>::Node *p = this->root;

        typename BiTree<Object>::Node *q = this->root;
        while (q->right!=nullptr) q=q->right;

        stack<typename BiTree<Object>::Node*> pStack;

        while (!pStack.empty() || p!=q)
        {
            if (pStack.empty() || pStack.top()!=p)
            {
                while (p->left!=nullptr)
                {
                    pStack.push(p);
                    p = p->left;
                }
            }

            str+=p->data;

            if(p->right!=nullptr)
            {
                if(pStack.top()==p)
                {
                    pStack.pop();
                }
                p = p->right;
            }
            else
            {
                if(p==pStack.top())
                    pStack.pop();

                p = pStack.top();
            }
        }

        return str+p->data;
    }

    const string & traverse() const
    {
        auto *str = new string();

        if(this->empty())
            return *str;

        queue<typename BiTree<Object>::Node*> pQueue;
        typename BiTree<Object>::Node *p = this->root;

        while (!pQueue.empty() || str->empty())
        {
            if(!pQueue.empty())
            {
                p = pQueue.front();
                pQueue.pop();
            }

            *str+=p->data;

            if (p->left!=nullptr) pQueue.push(p->left);
            if (p->right!=nullptr) pQueue.push(p->right);
        }

        return *str;
    }

    const vector<Object> & getVector() const
    {
        auto *v = new vector<Object>;

        if (this->empty())
            return *v;

        queue<typename BiTree<Object>::Node*> pQueue;
        typename BiTree<Object>::Node *p = this->root;

        auto n =  new typename BiTree<Object>::Node(0);

        while (!pQueue.empty() || v->empty())
        {
            if(!pQueue.empty())
            {
                p = pQueue.front();
                pQueue.pop();
            }

            v->push_back(p->data);

            if(p->left==nullptr && p->right!=nullptr) pQueue.push(n), pQueue.push(p->right);
            else if (p->left!=nullptr && p->right==nullptr) pQueue.push(p->left), pQueue.push(n);
            else if (p->left!=nullptr && p->right!= nullptr) pQueue.push(p->left), pQueue.push(p->right);
        }

        return *v;
    }

    void setFromVector(const vector<Object> & v)
    {
        this->clear();
        bool isLeft=true;
        queue<typename BiTree<Object>::Node*> pQueue;
        typename BiTree<Object>::Node *n;

        for(auto itr: v)
        {
            if(this->empty())
            {
                auto *p = new typename BiTree<Object>::Node(itr);

                this->root = p;
                pQueue.push(p);
            }
            else
            {
                if (itr!=' ')
                {
                    n = pQueue.front();
                    auto *p = new typename BiTree<Object>::Node(itr);

                    if(isLeft)
                        n->left = p;
                    else
                    {
                        pQueue.pop();
                        n->right = p;
                    }
                    pQueue.push(p);
                }
                isLeft=!isLeft;
            }
        }
    }

private:
    const string preOrderTraverse(typename BiTree<Object>::Node *p) const
    {
        if (p== nullptr) return {};
        else return p->data + preOrderTraverse(p->left) + preOrderTraverse(p->right);
    }

    const string infixOrderTraverse(typename BiTree<Object>::Node *p) const
    {
        if (p==nullptr) return {};
        return infixOrderTraverse(p->left) + p->data + infixOrderTraverse(p->right);
    }

    const string afterOrderTraverse(typename BiTree<Object>::Node *p) const
    {
        if (p==nullptr) return {};
        return afterOrderTraverse(p->left) + afterOrderTraverse(p->right) + p->data;
    }
};

#endif //ALGORITHM_MYBITREE_H
