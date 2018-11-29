//
// Created by lorry on 11/9/18.
//

#include <random>
#include "MyLinkList.h"
#include "Term_LinkList.h"

#ifndef ALGORITHM_EX3_2_TEXT_H
#define ALGORITHM_EX3_2_TEXT_H

template <typename ElemType>
void displayCurrentObject(MyLinkList<ElemType> & myLinkList)
{
    typename  LinkList<ElemType>::NodePointer pointer = myLinkList.getHead();

    cout << "\t\t";
    for(int i = 1; i <= myLinkList.getLength(); ++i)
        cout << "[" << i << "]\t";

    cout << endl << "\t\t";

    while(pointer)
    {
        cout << pointer->data;
        pointer = pointer->next;
        if (pointer)
            cout << "  ->\t";
        else
            cout << "^";
    }
}

template <typename ElemType>
void displayMessage(MyLinkList<ElemType> & myLinkList)
{
    if (myLinkList.getLength() == 0)
        cout << "\t\t当前循环单链表为空。" << endl;
    else
        displayCurrentObject(myLinkList);
}

template <typename ElemType>
void ex3_2_1(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    int i;
    ElemType e;

    cout << "\t*******************取非循环单链表的第i个结点*******************" << endl << endl;
    cout << "\t\t请输入你想要取的元素的序号（1--" <<  myLinkList.getLength() << "）：";

    cin >> i;
    if (i > myLinkList.getLength())
    {
        cout << "\t\t输入有误！" << endl << endl;
    }
    else
    {
        myLinkList.getElem(i, e);

        cout << "\t\t你想要取的第" << i << "个元素的值为：" << e << endl << endl;
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_2(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{

    int i;
    cout << "\t*******************在第i个结点之前插入一个结点*******************" << endl << endl;

    ElemType e;
    cout << "\t\t插入到第几个：";
    cin >> i;
    cout << "\t\t要插入的数据：";
    cin >> e;
    if(myLinkList.insert(i, e) == ERROR)
        cout << "\t\t插入元素失败！" << endl << endl;
    else
    {
        cout << "\t\t你要在第" << i << "个元素前插入元素" << e << endl;
        cout << "\t\t插入后的非循环单链表为：" << endl;
        displayCurrentObject(myLinkList);
        cout << endl;
    }

    cout << "\t************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_3(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    cout << "\t*******************判断非循环单链表是否为空*******************" << endl << endl;
    if (!myLinkList.isEmpty())
        cout << "\t\t当前非循环单链表为空" << endl << endl;
    else
        cout << "\t\t当前非循环单链表不为空" << endl << endl;

    cout << "\t*****************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_4(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    cout << "\t*******************求非循环单链表中元素的个数*******************" << endl << endl;
    cout << "\t\t非循环单链表元素的个数为：" << myLinkList.getLength() << endl << endl;

    cout << "\t******************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_5(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    int i;
    ElemType e;

    cout << "\t*******************查找第i个与e满足compare（）关系的元素*******************" << endl << endl;

    cout << "\t\t查找等于某个结点的操作" << endl;
    cout << "\t\t请输入你想要查找的结点：";
    cin >> e;
    if ((myLinkList.locateElem(e, equal, i)))
        cout << "\t\t你想要查找第一个等于" << e << "的结点为：" << i << endl << endl;
    else
        cout << "\t\t没有找到符合条件的结点！" << endl << endl;


    cout << "\t\t查找大于某个结点的操作" << endl;
    cout << "\t\t请输入你想要查找的结点：";
    cin >> e;
    if ((myLinkList.locateElem(e, bigger, i)))
        cout << "\t\t你想要查找第一个大于" << e << "的结点为：" << i << endl << endl;
    else
        cout << "\t\t没有找到符合条件的结点！" << endl << endl;


    cout << "\t\t查找小于某个结点的操作" << endl;
    cout << "\t\t请输入你想要查找的结点：";
    cin >> e;
    if ((myLinkList.locateElem(e, smaller, i)))
        cout << "\t\t你想要查找第一个小于" << e << "的结点为：" << i << endl << endl;
    else
        cout << "\t\t没有找到符合条件的结点！" << endl << endl;

    cout << endl << "\t**********************************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}


template <typename ElemType>
void ex3_2_6(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    ElemType i, j;

    cout << "\t*******************返回某结点前驱的数据域*******************" << endl << endl;

    cout << "\t\t请输入你想要查找其前驱的元素：";
    cin >> i;

    if (myLinkList.priorElem(i, j) == ERROR)
        cout << "\t\t输入序号有误！" << endl << endl;
    else
        cout << endl << "\t\t你想要查找的元素" << i << "的前驱为：" << j << endl << endl;

    cout << "\t*************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_7(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    ElemType i, j;

    cout << "\t*******************返回某结点后继的数据域*******************" << endl << endl;

    cout << "\t\t请输入你想要查找其后继的元素：";
    cin >> i;

    if (myLinkList.nextElem(i, j) == ERROR)
        cout << "\t\t输入序号有误！" << endl << endl;
    else
        cout << endl << "\t\t你想要查找的元素" << i << "的后继为：" << j << endl << endl;

    cout << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_8(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    ElemType e;

    cout << "\t*******************删除非循环单链表中数据域为e的第一个结点*******************" << endl << endl;

    cout << "\t\t请输入你想要删除元素的数据域：";
    cin >> e;

    if (myLinkList.deleteElem(e) == ERROR)
        cout << "\t\t输入的数据有误！" << endl;
    else
    {
        if (myLinkList.getLength() == 0)
            cout << "\t\t删除后的非循环单链表为空" << endl;
        else
        {
            cout << "\t\t删除后的非循环单链表为" << endl;
            displayCurrentObject(myLinkList);
        }
    }
    cout << endl << "\t*************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_9(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    cout << "\t*******************删除非循环单链表中的重复结点*******************" << endl << endl;

    myLinkList.deleteRepeat();
    if (myLinkList.getLength() == 0)
        cout << "\t\t此循环单链表为空！";
    else
    {
        cout << "\t\t删除重复元素后的循环单链表为：" << endl;
        displayCurrentObject(myLinkList);
    }

    cout << endl << "\t*************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_10(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    cout << "\t*******************非循环单链表的逆置*******************" << endl << endl;

    if (myLinkList.getLength() == 0)
        cout << "\t\t此循环单链表为空！";
    else
    {
        myLinkList.adverse();

        cout << "\t\t逆置此循环单链表后：" << endl;
        displayCurrentObject(myLinkList);
    }

    cout << endl << "\t*************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_11(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    MyLinkList<ElemType> otherLinkList;

    for (int i = 0; i < 10; ++i)
        otherLinkList.insert(1, uniform(engine));

    cout << "\t*******************把一个非循环单链表赋值给另一个非循环单链表*******************" << endl << endl;

    myLinkList = otherLinkList;
    displayCurrentObject(myLinkList);

    cout << endl << "\t*************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_12(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    cout << "\t*******************把当前非循环单链表置空******************" << endl << endl;

    myLinkList.clear();
    cout << endl << "\t\t当前非循环单链表置空后，元素的个数为：" << myLinkList.getLength() << endl << endl;

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_13(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    ElemType e;
    myLinkList.clear();

    cout << "\t*******************随机生成非循环单链表（元素值为0到99之间的整数）******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前非循环单链表的元素：" << endl << "\t\t";
    for (int i=0; i < 10; ++i)
    {
        e = uniform(engine);
        cout << e << "\t";
        myLinkList.insert(i+1, e);
    }

    cout << endl << "\t\t随机生成的非循环单链表为：" << endl;
    displayCurrentObject(myLinkList);

    cout << endl << "\t***********************************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_14(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    MyLinkList<ElemType> otherLinkList = MyLinkList<ElemType>(myLinkList);

    cout << "\t*******************用已有的非循环单链表初始化另一个非循环单链表*******************" << endl << endl;

    if (otherLinkList.getLength() == 0)
        cout << "\t\t此循环单链表为空" << endl;
    else
    {
        cout << "\t\t当前非循环单链表初始化另一个非循环单链表为：" << endl;
        displayCurrentObject(otherLinkList);
    }

    cout << endl << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_15(MyLinkList<ElemType> & myLinkList, char & continueYesNo)
{
    int n;
    ElemType e;
    myLinkList.clear();
    cout << "\t*******************输入非循环单链表******************" << endl << endl;

    cout << "\t\t请输入非循环单链表中的个数：";
    cin >> n;
    cout << "\t\t请输入非循环单链表中的元素：";
    for (int i=0; i < n; ++i)
    {
        cin >> e;
        myLinkList.insert(i+1, e);
    }

    cout << "\t\t新输入的非循环单链表为" << endl;
    displayCurrentObject(myLinkList);

    cout << endl << "\t**************************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_2_16(char & continueYesNo)
{
    int choose;
    MyLinkList<Term> termLinkList;

    while (true)
    {
        choose = 0;
        continueYesNo = 'N';
        system("clear");

        cout << endl;
        cout << "\t*******************多项式的运算（非循环单链表的应用）******************" << endl << endl;
        cout << "\t\t1.判断多项式是否为空" << endl;
        cout << "\t\t2.把一个多项式赋值给另一个多项式" << endl;
        cout << "\t\t3.两个多项式的加法" << endl;
        cout << "\t\t4.两个多项式的减法" << endl;
        cout << "\t\t5.设置多项式为空多项式" << endl;
        cout << "\t\t6.随机生成多项式" << endl;
        cout << "\t\t7.用已有的多项式初始化另一个多项式" << endl;
        cout << "\t\t8.输入多项式" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;
        displayMessage(termLinkList);
        cout << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-8）号码：";
        cin >> choose;

        if (choose > 0 && choose < 13)
        {
            system("clear");
            cout << endl;
            displayMessage(termLinkList);
            cout << endl << endl;
        }

        switch (choose)
        {
            case 1:
                ex3_2_16_1(termLinkList, continueYesNo);
                break;
            case 2:
                ex3_2_16_2(termLinkList, continueYesNo);
                break;
            case 3:
                ex3_2_16_3(termLinkList, continueYesNo);
                break;
            case 4:
                ex3_2_16_4(termLinkList, continueYesNo);
                break;
            case 5:
                ex3_2_16_5(termLinkList, continueYesNo);
                break;
            case 6:
                ex3_2_16_6(termLinkList, continueYesNo);
                break;
            case 7:
                ex3_2_16_7(termLinkList, continueYesNo);
                break;
            case 8:
                ex3_2_16_8(termLinkList, continueYesNo);
                break;
            default:
                cout << "" << endl << endl;
                break;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
        {
            continueYesNo = 'Y';
            break;
        }
    }
}


#endif //ALGORITHM_EX3_2_TEXT_H
