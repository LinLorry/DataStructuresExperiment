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

#ifndef ALGORITHM_EX3_4_TEXT_H
#define ALGORITHM_EX3_4_TEXT_H

template <typename Object>
void displayCurrentObject(const MyDoubleLinkList<Object> & myDoubleLinkList)
{
    typename MyDoubleLinkList<Object>::const_iterator iterator = myDoubleLinkList.begin();
    typename MyDoubleLinkList<Object>::const_iterator begin = myDoubleLinkList.begin();
    int i = 0, size = myDoubleLinkList.size();

    cout << "\t\t";
    for(; i<size; ++i)
        cout << "[" << i << "]\t\t";

    cout << endl << endl << "\t\t";

    do cout << *(iterator++) << "\t->\t";
    while (iterator != begin);

    cout << endl << "\t\t↑";
    for(i=0; i<size; ++i)
        cout << "__explicit ______";

    cout << "|";
}

template <typename Object>
void displayMessage(const MyDoubleLinkList<Object> & myDoubleLinkList,
                    const string & str,
                    const string & error = "当前循环单链表为空！！")
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
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_2(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_3(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_4(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_5(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_6(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_7(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_8(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex3_4_9(MyDoubleLinkList<Object> & myDoubleLinkList, char & continueYesNo)
{
    cout << "\t*******************判断循环单链表是否为空*******************" << endl << endl;

    if (myDoubleLinkList.empty()) cout << "\t\t当前循环单链表为空" << endl << endl;
    else cout << "\t\t当前循环单链表不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_EX3_4_TEXT_H
