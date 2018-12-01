//
// Created by lorry on 11/29/18.
//

#include <string>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

#include "MyCircularLinkList.h"

#ifndef ALGORITHM_EX3_3_TEXT_H
#define ALGORITHM_EX3_3_TEXT_H

template <typename Object>
void displayCurrentObject(const MyCircularLinkList<Object> & myCircularLinkList)
{
    typename MyCircularLinkList<Object>::const_iterator iterator = myCircularLinkList.begin();
    typename MyCircularLinkList<Object>::const_iterator begin = myCircularLinkList.begin();
    int i = 0, size = myCircularLinkList.size();

    cout << "\t\t";
    for(; i<size; ++i)
        cout << "[" << i << "]\t\t";

    cout << endl << "\t\t";

    do cout << *(iterator++) << "\t->\t";
    while (iterator != begin);

    cout << endl << "\t\t↑";
    for(i=0; i<size; ++i)
        cout << "________";

    cout << "|";
}

template <typename Object>
void displayMessage(const MyCircularLinkList<Object> & myCircularLinkList,
        const string & str,
        const string & error = "当前循环单链表为空！！")
{
    if (myCircularLinkList.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject(myCircularLinkList);
        cout << endl << endl;
    }
}

template <typename Object>
void Josephus(const MyCircularLinkList<Object> & myCircularLinkList, int start, int i)
{
    int j, n = start-1;
    string str;
    Object object;

    i--;

    MyCircularLinkList<Object> otherLnkList = MyCircularLinkList<Object>(myCircularLinkList);

    for (j=1; !otherLnkList.empty(); ++j)
    {
        str = "第";
        str += to_string(j);
        str += "次出列的结点为";
        n += i;
        n %= otherLnkList.size();

        otherLnkList.erase(n, object);

        str += to_string(object);
        if (otherLnkList.empty())
        {
            str += "，出列后约瑟夫环为空。";
            displayMessage(otherLnkList, "" , str);
        }
        else
        {
            str += "，出列后约瑟夫环为：";
            displayMessage(otherLnkList, str);
        }
    }
}

template <typename Object>
void ex3_3_1(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myCircularLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_2(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    int i=0;
    Object object;
    cout << "\t*******************把循环单链表的头指针后移至第i个结点*******************" << endl << endl;

    if(myCircularLinkList.empty())
        cout << "\t\t当前循环单链表为空！！无法移动头指针！！" << endl << endl;
    else
    {
        cout << "\t\t请输入头指针后移的结点序号：";
        cin >> i;

        if (myCircularLinkList.moveHead(i) == ERROR)
            cout << endl << "\t\t输入有误！请检查输入！" << endl << endl;
        else
            cout << endl << "\t\t移动后，头指针所指结点的数据域为：" << *(myCircularLinkList.begin()) << endl << endl;
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_3(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    int i;
    Object object;
    string str;

    cout << "\t*******************删除第i个结点，头指针移至其后下一个结点*******************" << endl << endl;

    if (myCircularLinkList.empty())
    {
        cout << "\t\t当前循环单链表为空，无法移动头指针！！" << endl << endl;
    }
    else
    {
        cout << "\t\t请输入欲删除的结点序号：";
        cin >> i;

        if (myCircularLinkList.erase(i, object) == ERROR)
            cout << "\t\t删除失败，请检查输入！！" << endl << endl;
        else
        {
            myCircularLinkList.moveHead(i);

            str = "删除第";
            str += to_string(i);
            str += "个结点";
            str += to_string(object);
            str += "后，循环单链表为：";
            displayMessage(myCircularLinkList, str);

        }
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_4(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    Object object;
    MyCircularLinkList<Object> otherLinkList;

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        otherLinkList.insert(i, object);
    }

    cout << "\t*******************把一个循环单链表赋值给另一个循环单链表*******************" << endl << endl;

    myCircularLinkList = otherLinkList;
    displayMessage(myCircularLinkList, "另一个循环单链表赋值给当前循环单链表为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_5(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    cout << "\t*******************把循环单链表置空*******************" << endl << endl;

    myCircularLinkList.clear();
    cout << "\t\t当前循环单链表已置空！" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_6(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    Object object;
    myCircularLinkList.clear();

    cout << "\t*******************随机生成循环单链表*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前非循环单链表的元素：" << endl << "\t\t";
    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        cout << object << "\t";
        myCircularLinkList.insert(i, object);
    }

    displayMessage(myCircularLinkList, "随机生成的循环单链表为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_7(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    MyCircularLinkList<Object> otherList = MyCircularLinkList<Object>(myCircularLinkList);

    cout << "\t*******************用已有的循环单链表初始化另一个循环单链表*******************" << endl << endl;

    displayMessage(otherList,
            "当前循环单链表初始化另一个循环单链表为：",
            "当前循环单链表为空，初始化另一个循环单链表为空！");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_8(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    int n;
    Object object;
    myCircularLinkList.clear();

    cout << "\t*******************输入非循环单链表*******************" << endl << endl;

    cout << "\t\t请输入循环单链表中的个数：";
    cin >> n;
    cout << "\t\t请输入循环单链表中的元素：";
    for (int i=0; i < n; ++i)
    {
        cin >> object;
        myCircularLinkList.insert(i, object);
    }

    cout << "\t\t已经在循环单链表中输入了" << myCircularLinkList.size() << "个结点" << endl << endl;

    displayMessage(myCircularLinkList, "新输入的循环单链表为", "未输入元素！");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_3_9(MyCircularLinkList<Object> & myCircularLinkList, char & continueYesNo)
{
    int start, i;
    cout << "\t*******************约瑟夫环（Josephus）出列*******************" << endl << endl;

    if (myCircularLinkList.empty())
        cout << "\t\t当前约瑟夫环为空！" << endl << endl;
    else
    {
        displayMessage(myCircularLinkList, "当前约瑟夫环为：");
        cout << "\t\t请输入起始结点号：";
        cin >> start;
        cout << "\t\t\t间隔结点号：";
        cin >> i;

        Josephus(myCircularLinkList, start, i);
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_EX3_3_TEXT_H
