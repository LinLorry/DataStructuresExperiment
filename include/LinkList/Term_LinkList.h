//
// Created by lorry on 11/23/18.
//

#include <random>

#include "../Term.h"

#ifndef ALGORITHM_MYTERM_LINKLIST_H
#define ALGORITHM_MYTERM_LINKLIST_H

extern ostream & operator<< (ostream & out, const Term & term);

void displayCurrentObject(MyLinkList<Term> & termLinkList)
{
    cout << "\t\t" << endl;
    MyLinkList<Term>::NodePointer pointer = termLinkList.getHead();
    while(pointer)
    {
        cout << pointer->data;
        pointer = pointer->next;
        if (pointer)
            cout << "+";
    }
}

void displayMessage(MyLinkList<Term> & termLinkList)
{
    if (termLinkList.getLength() == 0)
        cout << "\t\t当前循环单链表为空。" << endl;
    else
        displayCurrentObject(termLinkList);
}

void termAddTerm(MyLinkList<Term> & t_1, const MyLinkList<Term> & t_2)
{
    int i=1, j=1;
    MyLinkList<Term>::NodePointer p = t_1.getElem(i);
    MyLinkList<Term>::NodePointer q = t_2.getElem(j);

    while(p || q)
    {
        if(p && q)
        {
            if (p->data.getCoef() == q->data.getCoef())
            {
                p->data.setExpn(p->data.getExpn() + q->data.getExpn());
                if (p->data.getExpn() == 0)
                {
                    t_1.removeElem(i--);
                }
                p = t_1.getElem(++i);
                q = t_2.getElem(++j);
            }
            else if (p->data.getCoef() < q->data.getCoef())
            {
                t_1.insert(i++, q->data);
                q = t_2.getElem(++j);
            }
            else
            {
                p = t_1.getElem(++i);
            }
        }
        else if (!p)
        {
            t_1.insert(i++, q->data);
            q = t_2.getElem(++j);
        }
        else
            break;
    }
}

void termSubTerm(MyLinkList<Term> & t_1, const MyLinkList<Term> & t_2)
{
    int i=1, j=1;
    MyLinkList<Term>::NodePointer p = t_1.getElem(i);
    MyLinkList<Term>::NodePointer q = t_2.getElem(j);

    while(p || q)
    {
        if(p && q)
        {
            if (q->data.getCoef()==p->data.getCoef())
            {
                q->data.setExpn(q->data.getExpn() - p->data.getExpn());
                if (q->data.getExpn() == 0)
                {
                    t_1.removeElem(i--);
                }
                q = t_1.getElem(++i);
                p = t_2.getElem(++j);
            }

            else if (q->data.getCoef() < p->data.getCoef())
            {
                t_1.insert(i++, p->data);
                p = t_2.getElem(++j);
            }
            else
            {
                q = t_1.getElem(++i);
            }
        }
        else if (!p)
        {
            t_1.insert(i++, q->data);
            q = t_2.getElem(++j);
        }
        else
        {
            q = t_1.getElem(++i);
        }
    }
}

void ex3_2_16_1(MyLinkList<Term> & termList, char & continueYesNo)
{
    cout << "\t*******************判断多项式是否为空******************" << endl << endl;

    if (!termList.isEmpty())
        cout << "\t\t当前非循环单链表为空" << endl << endl;
    else
        cout << "\t\t当前非循环单链表不为空" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_2(MyLinkList<Term> & termList, char & continueYesNo)
{
    default_random_engine engine;
    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    MyLinkList<Term> otherTermList;

    for (int i=4; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), i);

        otherTermList.insert(1, t);
    }
    otherTermList.rankLinkList();

    cout << "\t*******************把一个多项式赋值给另一个多项式******************" << endl << endl;

    termList = otherTermList;
    displayCurrentObject(termList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_3(MyLinkList<Term> & termList, char & continueYesNo)
{
    default_random_engine engine;
    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    MyLinkList<Term> otherTermList;

    for (int i=4; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), i);

        otherTermList.insert(1, t);
    }
    otherTermList.rankLinkList();

    cout << "\t*******************两个多项式的加法******************" << endl << endl;

    displayCurrentObject(otherTermList);

    termAddTerm(termList, otherTermList);

    displayCurrentObject(termList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_4(MyLinkList<Term> & termList, char & continueYesNo)
{
    default_random_engine engine;
    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    MyLinkList<Term> otherTermList;

    for (int i=4; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), i);

        otherTermList.insert(1, t);
    }
    otherTermList.rankLinkList();

    cout << "\t*******************两个多项式的减法******************" << endl << endl;

    displayCurrentObject(otherTermList);

    termSubTerm(termList, otherTermList);

    displayCurrentObject(termList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_5(MyLinkList<Term> & termList, char & continueYesNo)
{
    cout << "\t*******************设置多项式为空多项式******************" << endl << endl;

    termList.clear();
    cout << endl << "\t\t当前非循环单链表置空后，元素的个数为：" << termList.getLength() << endl << endl;

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_6(MyLinkList<Term> & termList, char & continueYesNo)
{
    default_random_engine engine;
    uniform_int_distribution<unsigned> uniform_expn(1, 100);

    cout << "\t*******************随机生成多项式******************" << endl << endl;

    termList.clear();

    for (int i=4; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), i);

        termList.insert(1, t);
    }
    termList.rankLinkList();

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_7(MyLinkList<Term> & termList, char & continueYesNo)
{
    MyLinkList<Term> otherTermList = MyLinkList<Term>(termList);

    cout << "\t*******************用已有的多项式初始化另一个多项式******************" << endl << endl;

    termList.clear();
    cout << endl << "\t\t当前非循环单链表置空后，元素的个数为：" << termList.getLength() << endl << endl;

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_8(MyLinkList<Term> & termList, char & continueYesNo)
{
    cout << "\t*******************输入多项式******************" << endl << endl;

    termList.clear();
    cout << endl << "\t\t当前非循环单链表置空后，元素的个数为：" << termList.getLength() << endl << endl;

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_MYTERM_LINKLIST_H
