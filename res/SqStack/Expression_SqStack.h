//
// Created by lorry on 12/20/18.
//

#include <string>

using std::string;

#ifndef ALGORITHM_EXPRESSION_SQSTACK_H
#define ALGORITHM_EXPRESSION_SQSTACK_H

void displayMessage(const string & expression,
                    const string & str = "当前中缀表达式为:",
                    const string & error = "当前中缀表达式为空!");

void ex4_1_10_1(const string & expression, char & continueYesNo);

void ex4_1_10_2(const string & expression, char & continueYesNo);

void ex4_1_10_3(string & expression, char & continueYesNo);

#endif //ALGORITHM_EXPRESSION_SQSTACK_H
