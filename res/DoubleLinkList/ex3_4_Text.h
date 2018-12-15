//
// Created by lorry on 12/7/18.
//

#include <random>
#include <string>

#include "MyDoubleLinkList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

#ifndef ALGORITHM_EX3_4_TEXT_H
#define ALGORITHM_EX3_4_TEXT_H

template <typename Object>
void displayCurrentObject(const MyDoubleLinkList<Object> & myDoubleLinkList)
{
    typename MyDoubleLinkList<Object>::const_iterator iterator = myDoubleLinkList.begin();
    typename MyDoubleLinkList<Object>::const_iterator begin = myDoubleLinkList.begin();
    int i = 0, size = myDoubleLinkList.size();

    cout << "\t\t\t";
    for(; i<size; ++i)
        cout << "[" << i << "]\t\t";

    // Out put the head prev arrow.
    cout << endl << endl << "\t\t\t↓";
    for(i=0; i<size; ++i)
        cout << "--------";

    // Out put the objects and arrows
    cout << "|" << endl << "\t\t---\t";
    do cout << *(iterator++) << "\t->\t";
    while (iterator != begin);

    // Out put the prev arrows
    cout << endl << "\t\t|\t";
    for(i=0; i<size-1; ++i)
        cout << "↑______|";

    // Out put the end node next arrow
    cout << "↑" << endl << "\t\t|___";
    for(i=0; i<size-1; ++i)
        cout << "________";
    cout << "|";
}

template <typename Object>
void displayMessage(const MyDoubleLinkList<Object> & myDoubleLinkList,
                    const string & str = "当前循环单链表为：",
                    const string & error = "当前循环单链表为空！")
{
    if (myDoubleLinkList.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject(myDoubleLinkList);
        cout << endl << endl;
    }
}

template <typename Object>
void ex3_4_1(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int i;
    typename MyDoubleLinkList<Object>::const_iterator iterator = myDoubleLinkList.begin();

    cout << "\t*******************取循环双链表第i个结点的数据域*******************" << endl << endl;

    cout << "\t\t请输入你想要取的结点的序号：";
    cin >> i;
    if (i > myDoubleLinkList.size())
        cout << "\t\t输入有误！" << endl << endl;
    else
    {
        for (; i>0; --i) ++iterator;

        cout << "\t\t你想要取的第" << i << "个结点的值为："<< *iterator << endl << endl;
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_2(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int i;
    Object object;
    string str;

    cout << "\t*******************在第i个结点之前插入一个数据域为e的结点*******************" << endl << endl;

    cout << "\t\t插入到第几个：";
    cin >> i;
    if (i>myDoubleLinkList.size())
    {
        cout << "\t\t输入有误！" << endl << endl;
    }
    else
    {
        cout << "\t\t要插入的数据：";
        cin >> object;

        myDoubleLinkList.insert(i, object);

        str = "你已经在第";
        str += to_string(i);
        str += "个结点之前插入数据域为";
        str += to_string(object);
        str += "的结点";

        displayMessage(myDoubleLinkList, str);
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_3(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环双链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_4(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************求循环双链表中结点的个数*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空!" << endl << endl;
    else cout << "\t\t循环双链表元素的个数为：" << myDoubleLinkList.size() << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_5(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int i;
    int size = myDoubleLinkList.size();
    typename MyDoubleLinkList<Object>::const_iterator iterator = myDoubleLinkList.begin();
    Object object;

    cout << "\t*******************返回循环双链表中数据域为e的第一个结点的指针*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "当前循环单链表为空！" << endl << endl;
    else
    {
        cout << "\t\t请输入你想要查找结点的数据域：";
        cin >> object;

        for (i=0; i<size && *iterator!=object; ++i, ++iterator);

        if (iterator==myDoubleLinkList.begin() && *iterator!=object)
            cout << "\t\t没有找到！" << endl;
        else
            cout << "\t\t你想要查找的第一个数据域为" << object << "位置在：" << i << endl << endl;
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_6(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int i;
    int size = myDoubleLinkList.size();

    cout << "\t*******************返回某结点前驱的数据域*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "当前循环单链表为空！" << endl << endl;
    else
    {
        typename MyDoubleLinkList<Object>::const_iterator iterator = myDoubleLinkList.end();

        cout << "\t\t请输入你想要查找结点的位置：";
        cin >> i;

        if (i > size)
            cout << "\t\t输入有误！" << endl;
        else
        {
            for(int j=0; j < i; ++j, ++iterator);
            cout << "\t\t你想要查找的第" << i << "个数据的前驱的数据域为：" <<  *iterator << endl;
        }
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_7(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int i;
    int size = myDoubleLinkList.size();

    cout << "\t*******************返回某结点后继的数据域*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "当前循环单链表为空！" << endl << endl;
    else
    {
        typename MyDoubleLinkList<Object>::const_iterator iterator = myDoubleLinkList.begin();

        cout << "\t\t请输入你想要查找结点的位置：";
        cin >> i;

        if (i > size)
            cout << "\t\t输入有误！" << endl;
        else
        {
            for(int j=0; j < i; ++j, ++iterator);
            cout << "\t\t你想要查找的第" << i << "个数据的后继的数据域为：" << *(++iterator) << endl;
        }
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_8(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int size = myDoubleLinkList.size();
    typename MyDoubleLinkList<Object>::iterator iterator = myDoubleLinkList.begin();
    Object object;

    cout << "\t*******************删除循环双链表中数据域为e的第一个结点*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "当前循环单链表为空！" << endl << endl;
    else
    {
        cout << "\t\t请输入你想要删除结点的数据域：";
        cin >> object;

        for (int i = 0; i<size && *iterator!=object; ++i, ++iterator);

        if (iterator==myDoubleLinkList.begin() && *iterator!=object)
            cout << "\t\t没有找到！" << endl;
        else
        {
            myDoubleLinkList.erase(iterator);
            displayMessage(myDoubleLinkList, "删除后的循环双链表为：");
        }
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_9(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    MyDoubleLinkList<Object> otherDoubleLinkList;
    Object object;

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        otherDoubleLinkList.insert(i, object);
    }

    cout << "\t*******************把一个循环双链表赋值给另一个循环双链表*******************" << endl;

    myDoubleLinkList = otherDoubleLinkList;
    displayMessage(myDoubleLinkList, "另一个循环双链表赋值给当前循环双链表为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_10(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    string str;
    int size;

    cout << "\t*******************把循环双链表置空*******************" << endl << endl;

    myDoubleLinkList.clear();
    size = myDoubleLinkList.size();
    str = "当前循环双链表置空后，数据元素的个数为：";
    str += to_string(size);
    displayMessage(myDoubleLinkList, "", str);

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_11(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    Object object;
    myDoubleLinkList.clear();

    cout << "\t*******************随机生成循环双链表*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前循环双链表的元素：" << endl << endl << "\t\t\t";

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        cout << object << "\t\t";
        myDoubleLinkList.insert(i, object);
    }
    displayMessage(myDoubleLinkList, "随机生成的循环双链表");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_12(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    MyDoubleLinkList<Object> otherDoubleLinkList = MyDoubleLinkList<Object>(myDoubleLinkList);

    cout << "\t*******************用已有的循环双链表初始化另一个循环双链表*******************" << endl << endl;

    displayMessage(otherDoubleLinkList, "当前循环双链表初始化另一个循环双链表为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_13(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    int n;
    Object object;
    myDoubleLinkList.clear();

    cout << "\t*******************输入循环双链表*******************" << endl << endl;

    cout << "\t\t请输入循环双链表中的个数：";
    cin >> n;
    cout << "\t\t请输入循环双链表中的元素：";
    for (int i=0; i < n; ++i)
    {
        cin >> object;
        myDoubleLinkList.insert(i, object);
    }

    displayMessage(myDoubleLinkList, "输入的循环双链表为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}
#endif //ALGORITHM_EX3_4_TEXT_H
