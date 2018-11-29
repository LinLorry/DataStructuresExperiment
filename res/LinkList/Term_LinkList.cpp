//
// Created by lorry on 11/29/18.
//

#include <random>

#include "Term_LinkList.h"
#include "../Models/Term.h"

void displayCurrentObject(MyLinkList<Term> & termLinkList)
{
    cout << "\t\t";
    MyLinkList<Term>::NodePointer pointer = termLinkList.getHead();
    while(pointer)
    {
        cout << pointer->data;
        pointer = pointer->next;
        if (pointer&&pointer->data.getExpn()>=0)
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
            if (p->data.getCoef() == q->data.getCoef())
            {
                p->data.setExpn(p->data.getExpn() - q->data.getExpn());
                if (p->data.getExpn() == 0)
                {
                    t_1.removeElem(i--);
                }
                p = t_1.getElem(++i);
                q = t_2.getElem(++j);
            }
            else if (p->data.getCoef() < q->data.getCoef())
            {
                t_1.insert(i, q->data);
                p = t_1.getElem(i);
                p->data.setExpn(-p->data.getExpn());
                p = p->next;
                ++i;
                q = t_2.getElem(++j);
            }
            else
            {
                p = t_1.getElem(++i);
            }
        }
        else if (!p)
        {
            t_1.insert(i, q->data);
            p = t_1.getElem(i);
            p->data.setExpn(-p->data.getExpn());
            p = p->next;
            ++i;
            q = t_2.getElem(++j);
        }
        else
            break;
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
    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    uniform_int_distribution<unsigned> uniform_coef(1, 10);
    MyLinkList<Term> otherTermList;

    for (int i=6; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), uniform_coef(engine));

        otherTermList.insert(1, t);
    }
    otherTermList.mergeRepeat();

    cout << "\t*******************把一个多项式赋值给另一个多项式******************" << endl << endl;

    termList = otherTermList;
    cout << "\t\t另一个多项式赋值给当前多项式为：" << endl;
    displayCurrentObject(termList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_3(MyLinkList<Term> & termList, char & continueYesNo)
{

    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    uniform_int_distribution<unsigned> uniform_coef(1, 10);
    MyLinkList<Term> otherTermList;

    for (int i=6; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), uniform_coef(engine));

        otherTermList.insert(1, t);
    }
    otherTermList.mergeRepeat();

    cout << "\t*******************两个多项式的加法******************" << endl << endl;

    cout << "\t\t另一个多项式为：" << endl;
    displayCurrentObject(otherTermList);

    termAddTerm(termList, otherTermList);

    cout << endl << "\t\t以上两个多项式相加，和为：" << endl;
    displayCurrentObject(termList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_4(MyLinkList<Term> & termList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    uniform_int_distribution<unsigned> uniform_coef(1, 10);
    MyLinkList<Term> otherTermList;

    for (int i=6; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), uniform_coef(engine));

        otherTermList.insert(1, t);
    }
    otherTermList.mergeRepeat();

    cout << "\t*******************两个多项式的减法******************" << endl << endl;

    cout << "\t\t另一个多项式为：" << endl;
    displayCurrentObject(otherTermList);

    termSubTerm(termList, otherTermList);

    cout << endl << "\t\t以上两个多项式相减，差为：" << endl;
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
    uniform_int_distribution<unsigned> uniform_expn(1, 100);
    uniform_int_distribution<unsigned> uniform_coef(1, 10);

    int i = uniform_coef(engine);

    cout << "\t*******************随机生成多项式******************" << endl << endl;

    termList.clear();

    cout << "\t\t依次生成多项式如下" << i << "个项" << endl << "\t\t";
    for (; i>0; --i)
    {
        Term t = Term(uniform_expn(engine), uniform_coef(engine));
        cout << t << "\t";

        termList.insert(1, t);
    }
    cout << endl << endl << "\t\t随机生成多项式为：" << endl;
    termList.mergeRepeat();

    displayCurrentObject(termList);
    cout << endl;
    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_7(MyLinkList<Term> & termList, char & continueYesNo)
{
    MyLinkList<Term> otherTermList = MyLinkList<Term>(termList);

    cout << "\t*******************用已有的多项式初始化另一个多项式******************" << endl << endl;

    cout << "\t\t用当前多项式初始化另一个多项式为：" << endl;
    displayCurrentObject(otherTermList);
    cout << endl;

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16_8(MyLinkList<Term> & termList, char & continueYesNo)
{
    int num=0, expn, coef;
    Term t;
    cout << "\t*******************输入多项式******************" << endl << endl;

    cout << "\t\t请输入多项式的项数：";
    cin >> num;
    cout << "\t\t请输入多项式中的项：" << endl;
    for(int i=1; i<=num; ++i)
    {
        cout << "\t\t\t第" << i << "项系数：";
        cin >> expn;
        cout << "\t\t\t\t指数：";
        cin >> coef;

        t.setExpn(expn);
        t.setCoef(coef);

        termList.insert(i, t);
    }

    termList.mergeRepeat();
    cout << "\t\t当前循环单链表为：" << endl;
    displayCurrentObject(termList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}
