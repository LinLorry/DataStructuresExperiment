//
// Created by lorry on 12/20/18.
//

#include <iostream>
#include <string>

#include "Expression_SqStack.h"
#include "SqStack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

void displayMessage(const string & expression,
                    const string & str,
                    const string & error)
{
    if (expression.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
        cout << endl << "\t\t" << str << expression << endl << endl;
}

const string & generateSuffixExpression(const string & expression)
{
    SqStack<char> sqStack;
    auto *suffixExpression = new char[expression.length()+1];
    char *p = suffixExpression;

    string::const_iterator itr = expression.begin();

    while (itr!=expression.end())
    {
        if (*itr=='+' || *itr=='-')
        {

            while(!sqStack.empty() && sqStack.back()!='(')
            {
                *p++ = sqStack.back();
                sqStack.pop_back();
            }
            sqStack.push_back(*itr++);

        }
        else if (*itr=='*' || *itr=='/' || *itr =='(')
        {
            sqStack.push_back(*itr++);
        }
        else if (*itr==')')
        {
            while (sqStack.back()!='(')
            {
                *p++ = sqStack.back();
                sqStack.pop_back();
            }
            sqStack.pop_back();
            itr++;

        }
        else if (*itr == ' ') { }
        else
        {
            while(*itr!='+' && *itr!='-' &&
                    *itr!='*' && *itr!='/' &&
                    *itr!='(' && *itr!=')' &&
                    *itr!=' ' && itr!=expression.end())
                *p++=*itr++;
            *p++ = ' ';

        }
    }

    while (!sqStack.empty())
    {
        *p++ = sqStack.back();
        sqStack.pop_back();
    }

    *p = '\0';
    return *(new string(suffixExpression));
}


float calculateSuffixExpression(const string & suffixExpression)
{
    char *num_end;
    float right, left;
    SqStack<float> sqStack;
    string::const_iterator itr = suffixExpression.begin();

    while(itr!=suffixExpression.end())
    {
        if (*itr == '+' || *itr == '-' ||
            *itr == '*' || *itr == '/')
        {
            right = sqStack.back();
            sqStack.pop_back();
            left = sqStack.back();
            sqStack.pop_back();

            switch (*itr)
            {
                case '+':
                    sqStack.push_back(left + right);
                    break;
                case '-':
                    sqStack.push_back(left - right);
                    break;
                case '*':
                    sqStack.push_back(left * right);
                    break;
                case '/':
                    sqStack.push_back(left / right);
                    break;
                default:
                    break;
            }
            itr++;
        }
        else if (*itr==' ') itr++;
        else
        {
            sqStack.push_back(strtof(itr.base(), &num_end));
            itr = string::const_iterator(num_end);
        }

    }

    return sqStack.back();
}

void ex4_1_10_1(const string & expression, char & continueYesNo)
{
    cout << "\t*******************中缀表达式转换为后缀表达式*******************" << endl << endl;

    if (expression.empty()) cout << "当前中缀表达式为空!" << endl << endl;
    else cout << "\t\t当前中缀表达式对应的后缀表达式为" << endl <<
            "\t\t\t" << generateSuffixExpression(expression) << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex4_1_10_2(const string & expression, char & continueYesNo)
{
    const string & suffixExpression = generateSuffixExpression(expression);

    cout << "\t*******************后缀表达式的计算*******************" << endl << endl;

    if (expression.empty()) cout << "当前中缀表达式为空!" << endl << endl;
    else cout << "\t\t当前后缀表达式" << suffixExpression << "的计算结果为：" <<
            calculateSuffixExpression(suffixExpression) << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex4_1_10_3(string & expression, char & continueYesNo)
{
    cout << "\t*******************输入中缀表达式*******************" << endl << endl;

    cout << "\t\t请输入一个中缀表达式";
    cin >> expression;
    cout << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}
