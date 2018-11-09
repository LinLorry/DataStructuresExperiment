//
// Created by lorry on 10/24/18.
//

#include "MyExampleClass.h"

#ifndef ALGORITHM_EX2_1_TEXT_H
#define ALGORITHM_EX2_1_TEXT_H

template <typename ElemType>
void displayCurrentObject(MyRectangle<ElemType> & rec)
{
    cout << endl;
    cout << rec;
    cout << endl;
}

template <typename ElemType>
void ex2_1_1(MyRectangle<ElemType> & rec, char & continueYesNo)
{
    int no;
    cout << "\t******************* 设置长方形的序号 ************" << endl << endl;
    cout << "\t\t请输入当前长方形对象的序号：";
    cin >> no;
    rec.setNo(no);
    cout << rec << endl;

    cout << "\t**********************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex2_1_2(MyRectangle<ElemType> & rec, char & continueYesNo)
{
    int aL;
    cout << "\t******************* 设置长方形的长 **************" << endl << endl;
    cout << "\t\t请输入当前长方形对象的长：";
    cin >> aL;
    rec.setLength(aL);
    cout << rec << endl;

    cout << "\t**********************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex2_1_3(MyRectangle<ElemType> & rec, char & continueYesNo)
{
    MyRectangle<ElemType> recOther;
    cout << "\t******************* 重载赋值运算符的定义 ********" << endl << endl;
    cout << "\t\t把当前长方形对象赋值给另一个长方形对象" << endl;
    recOther = rec;
    cout << endl << "\t\t赋值后，另一个长方形对象为：" <<endl;
    cout << recOther;

    cout << "\t**********************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_EX2_1_TEXT_H
