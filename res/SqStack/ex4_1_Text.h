//
// Created by lorry on 12/15/18.
//
#include <random>
#include <string>

#include "SqStack.h"
#include "Expression_SqStack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

#ifndef ALGORITHM_EX4_1_TEXT_H
#define ALGORITHM_EX4_1_TEXT_H

template <typename Object>
void displayCurrentObject(const SqStack<Object> & sqStack)
{
    int size = sqStack.size();
    typename SqStack<Object>::const_iterator iterator = sqStack.begin();

    cout << "\t\t";
    while(iterator!=sqStack.end())
        cout << *iterator++ << "\t";

    cout << endl << "\t\t↑";
    for(int i=1; i<size; ++i) cout << "\t";

    cout << "↑" << endl << "\t\tbase";
    for(int i=1; i<size; ++i) cout << "\t";
    cout << "top";
}

template <typename Object>
void displayMessage(const SqStack<Object> & sqStack,
                    const string & str = "当前顺序栈中的元素为",
                    const string & error = "当前顺序栈中为空")
{
    if (sqStack.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject(sqStack);
        cout << endl << endl;
    }
}

template <typename Object>
void ex4_1_1(SqStack<Object> & sqStack, char & continueYesNo)
{
    string str = "压入元素";
    Object object;

    cout << "\t*******************在栈顶压入元素e*******************" << endl << endl;

    cout << "\t\t请输入你要在栈顶压入的元素：";
    cin >> object;

    str += to_string(object);
    str += "后，新的顺序栈为：";

    sqStack.push_back(object);
    displayMessage(sqStack, str);

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_2(SqStack<Object> & sqStack, char & continueYesNo)
{
    string str = "弹出后顺序栈中的元素为：";

    cout << "\t*******************弹出栈顶的元素到e*******************" << endl << endl;

    if(sqStack.empty()) cout << "\t\t当前栈为空，无法弹出元素！" << endl << endl;
    else
    {
        Object object = sqStack.back();

        cout << "\t\t弹出的栈顶元素为：" << object << endl;

        sqStack.pop_back();
        displayMessage(sqStack, str);
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_3(SqStack<Object> & sqStack, char & continueYesNo)
{
    string str = "读栈顶元素的顺序栈中的元素为：";

    cout << "\t*******************读栈顶的元素*******************" << endl << endl;

    if(sqStack.empty()) cout << "\t\t当前栈为空！" << endl << endl;
    else
    {
        Object object = sqStack.back();
        cout << "\t\t读栈顶元素为：" << object << endl;
        displayMessage(sqStack, str);
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_4(SqStack<Object> & sqStack, char & continueYesNo)
{
    cout << "\t*******************判断顺序栈是否为空*******************" << endl << endl;

    if (sqStack.empty()) cout << "\t\t当前顺序栈为空" << endl << endl;
    else cout << "\t\t当前顺序栈不为空" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_5(SqStack<Object> & sqStack, char & continueYesNo)
{
    int size = sqStack.size();

    cout << "\t*******************求顺序栈中元素的个数*******************" << endl << endl;

    cout << "\t\t当前顺序栈在中的元素的个数为：" << size << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_6(SqStack<Object> & sqStack, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    SqStack<Object> otherSqStack;
    Object object;

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        otherSqStack.push_back(object);
    }

    cout << "\t*******************把一个顺序栈赋值给另一个顺序栈*******************" << endl << endl;

    sqStack = otherSqStack;
    displayMessage(sqStack, "另一个顺序栈赋值给当前顺序栈为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_7(SqStack<Object> & sqStack, char & continueYesNo)
{
    cout << "\t*******************把顺序栈置空*******************" << endl << endl;

    sqStack.clear();
    cout << "\t\t当前顺序栈置空后，元素的个数为：" << sqStack.size() << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_8(SqStack<Object> & sqStack, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    Object object;
    sqStack.clear();

    cout << "\t*******************随机生成顺序栈*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前顺序栈的元素：" << endl << endl << "\t\t";

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        cout << object << "\t";
        sqStack.push_back(object);
    }
    displayMessage(sqStack, "随机生成的顺序栈");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_1_9(SqStack<Object> & sqStack, char & continueYesNo)
{
    SqStack<Object> otherSqStack = SqStack<Object>(sqStack);

    cout << "\t*******************用已有的顺序栈初始化另一个顺序栈*******************" << endl << endl;

    displayMessage(otherSqStack, "当前顺序栈初始化另一个顺序栈为：");

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex4_1_10(char & continueYesNo)
{
    string expression;

    cout << "\t*******************表达式求解*******************" << endl << endl;

    int choose;

    while (true)
    {
        choose = 0;
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.中缀表达式转换为后缀表达式" << endl;
        cout << "\t\t2.后缀表达式的计算" << endl;
        cout << "\t\t3.输入中缀表达式" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage(expression);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-3）号码：";
        cin >> choose;

        if (choose > 0 && choose < 3)
        {
            system("clear");
            displayMessage(expression);
        }

        switch (choose)
        {
            case 1:
                ex4_1_10_1(expression, continueYesNo);
                break;
            case 2:
                ex4_1_10_2(expression, continueYesNo);
                break;
            case 3:
                ex4_1_10_3(expression, continueYesNo);
                break;
            default:
                cout << "" << endl << endl;
                continueYesNo = 'Y';
                return;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
        {
            continueYesNo = 'Y';
            return;
        }
    }
}

template <typename Object>
void ex4_1_11(SqStack<Object> & sqStack, char & continueYesNo)
{
    cout << "\t*******************迷宫求解*******************" << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_EX4_1_TEXT_H
