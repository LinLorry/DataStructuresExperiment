//
// Created by lorry on 12/22/18.
//
#include <random>
#include <string>

#include "../../include/myhead.h"
#include "LinkStack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

#ifndef ALGORITHM_EX4_2_TEXT_H
#define ALGORITHM_EX4_2_TEXT_H

template <typename Object>
void displayCurrentObject(const LinkStack<Object> & linkStack)
{
    typename LinkStack<Object>::const_iterator itr = linkStack.begin();
    typename LinkStack<Object>::const_iterator end = linkStack.end();

    cout << "\t\t";
    while(itr!=end)
    {
        cout << *itr++ << "\t";
    }
    cout << *itr << endl << "\t\t↑" << endl << "\t\ttop";

}

template <typename Object>
void displayMessage(const LinkStack<Object> & linkStack,
                    const string & str = "当前链栈中的元素为",
                    const string & error = "当前链栈中为空")
{
    if (linkStack.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject(linkStack);
        cout << endl << endl;
    }
}

template <typename Object>
void ex4_2_1(LinkStack<Object> & linkStack, char & continueYesNo)
{
    string str = "压入元素";
    Object object;
    
    cout << "\t*******************在栈顶压入元素e*******************" << endl << endl;

    cout << "\t\t请输入你要在栈顶压入的元素：";
    cin >> object;

    str += to_string(object);
    str += "后，新的链栈为：";

    linkStack.push(object);
    displayMessage(linkStack, str);
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_2(LinkStack<Object> & linkStack, char & continueYesNo)
{
    string str = "弹出后链栈中的元素为：";

    cout << "\t*******************弹出栈顶的元素到e*******************" << endl << endl;
    
    if(linkStack.empty()) cout << "\t\t当前栈为空，无法弹出元素！" << endl << endl;
    else
    {
        Object object = linkStack.pop_back();

        cout << "\t\t弹出的栈顶元素为：" << object << endl;
        
        displayMessage(linkStack, str);
    }
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_3(LinkStack<Object> & linkStack, char & continueYesNo)
{
    string str = "读栈顶元素的链栈中的元素为：";

    cout << "\t*******************读栈顶的元素*******************" << endl << endl;
    
    if(linkStack.empty()) cout << "\t\t当前栈为空！" << endl << endl;
    else
    {
        Object object = linkStack.back();
        cout << "\t\t读栈顶元素为：" << object << endl;
        displayMessage(linkStack, str);
    }

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_4(LinkStack<Object> & linkStack, char & continueYesNo)
{
    cout << "\t*******************判断链栈是否为空*******************" << endl << endl;

    if (linkStack.empty()) cout << "\t\t当前链栈为空" << endl << endl;
    else cout << "\t\t当前链栈不为空" << endl << endl;
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_5(LinkStack<Object> & linkStack, char & continueYesNo)
{
    int size = linkStack.size();
    
    cout << "\t*******************求链栈中元素的个数*******************" << endl << endl;

    cout << "\t\t当前链栈在中的元素的个数为：" << size << endl << endl;
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_6(LinkStack<Object> & linkStack, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    LinkStack<Object> otherSqStack;
    Object object;

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        otherSqStack.push(object);
    }
    
    cout << "\t*******************把一个链栈赋值给另一个链栈*******************" << endl << endl;

    linkStack = otherSqStack;
    displayMessage(linkStack, "另一个链栈赋值给当前链栈为：");
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_7(LinkStack<Object> & linkStack, char & continueYesNo)
{
    cout << "\t*******************把链栈置空*******************" << endl << endl;

    linkStack.clear();
    cout << "\t\t当前链栈置空后，元素的个数为：" << linkStack.size() << endl << endl;
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_8(LinkStack<Object> & linkStack, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    Object object;
    linkStack.clear();
    
    cout << "\t*******************随机生成链栈*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前链栈的元素：" << endl << endl << "\t\t";

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        cout << object << "\t";
        linkStack.push(object);
    }
    displayMessage(linkStack, "随机生成的链栈");
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex4_2_9(LinkStack<Object> & linkStack, char & continueYesNo)
{
    LinkStack<Object> otherSqStack = LinkStack<Object>(linkStack);
    
    cout << "\t*******************用已有的链栈初始化另一个链栈*******************" << endl << endl;

    displayMessage(otherSqStack, "当前链栈初始化另一个链栈为：");
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_EX4_2_TEXT_H
