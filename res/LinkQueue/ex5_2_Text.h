//
// Created by lorry on 12/26/18.
//

#include <random>
#include <string>

#include "../../include/myhead.h"
#include "LinkQueue.h"
#include "ParkSystem.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

#ifndef ALGORITHM_EX5_2_TEXT_H
#define ALGORITHM_EX5_2_TEXT_H

template <typename Object>
void displayCurrentObject(const LinkQueue<Object> & linkQueue)
{
    int size = linkQueue.size();
    typename LinkQueue<Object>::const_iterator itr = linkQueue.begin();

    cout << "\t\t";
    do
    {
        cout << *itr++ << "\t";
    }
    while (itr!=linkQueue.end());

    cout << *itr << endl << "\t\t↑";
    for(int i=1; i < size; ++i)
        cout << "\t";
    cout << "↑" << endl << "\t\tfront";
    for(int i=1; i < size; ++i)
        cout << "\t";
    cout << "rear";

}

template <typename Object>
void displayMessage(const LinkQueue<Object> & linkQueue,
                    const string & str = "当前非循环链队中的元素为",
                    const string & error = "当前非循环链队中为空")
{
    if (linkQueue.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject(linkQueue);
        cout << endl << endl;
    }
}

template <typename Object>
void ex5_2_1(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    string str = "压入元素";
    Object object;
    
    cout << "\t*******************进队列*******************" << endl << endl;

    cout << "\t\t请输入你要进队列的数据：";
    cin >> object;

    str += to_string(object);
    str += "后，新的非循环链队为：";

    linkQueue.push(object);
    displayMessage(linkQueue, str);

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_2(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    string str = "弹出后非循环链队中的元素为：";
    
    cout << "\t*******************出队列*******************" << endl << endl;

    if(linkQueue.empty()) cout << "\t\t当前队列为空，无法弹出元素！" << endl << endl;
    else
    {
        Object object = linkQueue.pop_front();

        cout << "\t\t弹出的队列头元素为：" << object << endl;

        displayMessage(linkQueue, str);
    }
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_3(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    string str = "读队列头元素的非循环链队中的元素为：";

    cout << "\t*******************读非循环链队头结点的数据域*******************" << endl << endl;

    if(linkQueue.empty()) cout << "\t\t当前队列为空！" << endl << endl;
    else
    {
        Object object = linkQueue.getFornt();
        cout << "\t\t读队列头元素为：" << object << endl;
        displayMessage(linkQueue, str);
    }
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_4(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

    if (linkQueue.empty()) cout << "\t\t当前非循环链队为空" << endl << endl;
    else cout << "\t\t当前非循环链队不为空" << endl << endl;
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_5(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    int size = linkQueue.size();
    
    cout << "\t*******************求非循环链队中元素的个数*******************" << endl << endl;

    cout << "\t\t当前非循环链队在中的元素的个数为：" << size << endl << endl;
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_6(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    LinkQueue<Object> otherSqStack;
    Object object;

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        otherSqStack.push(object);
    }
    
    cout << "\t*******************把一个非循环链队赋值给另一个非循环链队*******************" << endl << endl;

    linkQueue = otherSqStack;
    displayMessage(linkQueue, "另一个非循环链队赋值给当前非循环链队为：");
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_7(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    cout << "\t*******************把非循环链队置空*******************" << endl << endl;

    linkQueue.clear();
    cout << "\t\t当前非循环链队置空后，元素的个数为：" << linkQueue.size() << endl << endl;
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_8(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    Object object;
    linkQueue.clear();
    
    cout << "\t*******************随机生成非循环链队*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前非循环链队的元素：" << endl << endl << "\t\t";

    for(int i=0; i<10; ++i)
    {
        object = uniform(engine);
        cout << object << "\t";
        linkQueue.push(object);
    }
    displayMessage(linkQueue, "随机生成的非循环链队");
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename Object>
void ex5_2_9(LinkQueue<Object> & linkQueue, char & continueYesNo)
{
    LinkQueue<Object> otherSqStack = LinkQueue<Object>(linkQueue);
    
    cout << "\t*******************用已有的非循环链队初始化另一个非循环链队*******************" << endl << endl;

    displayMessage(otherSqStack, "当前非循环链队初始化另一个非循环链队为：");
    
    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex5_2_10()
{
    ParkSystem parkSystem;
    parkSystem.init();
}

#endif //ALGORITHM_EX5_2_TEXT_H
