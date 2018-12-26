//
// Created by lorry on 12/26/18.
//

#include <random>
#include <string>

#include "../../include/myhead.h"
#include "SqQueue.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::uniform_int_distribution;

#ifndef ALGORITHM_EX5_1_TEXT_H
#define ALGORITHM_EX5_1_TEXT_H

template <typename Object>
void displayCurrentObject(const SqQueue<Object> & sqQueue)
{

}

template <typename Object>
void displayMessage(const SqQueue<Object> & sqQueue,
                    const string & str = "当前链栈中的元素为",
                    const string & error = "当前链栈中为空")
{
    if (sqQueue.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject(sqQueue);
        cout << endl << endl;
    }
}

#endif //ALGORITHM_EX5_1_TEXT_H
