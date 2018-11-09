//
// Created by lorry on 10/24/18.
//

#include <stdlib.h>
#include "MySetSqList.h"

#include "Student_SqList.h"

#ifndef ALGORITHM_EX3_1_TEXT_H
#define ALGORITHM_EX3_1_TEXT_H


template <typename ElemType>
void displayCurrentObject(MySqList<ElemType> mySqList)
{
    cout << endl;
    if (mySqList.getLength() == 0)
        cout << "\t\t当前顺序表为空。" << endl << endl;
    else
    {
        cout << "\t\t当前顺序表有" << mySqList.getLength() << "个元素，分别为：" << endl;
        cout << mySqList << endl;
    }
}

template <typename ElemType>
void ex3_1_1(MySqList<ElemType> & mySqList, char & continueYesNo)
{
    int i;
    cout << "\t*******************在第i个元素之前插入一个元素*******************" << endl << endl;

    ElemType e;
    cout << "\t\t插入到第几个：";
    cin >> i;
    cout << "\t\t要插入的数据：";
    cin >> e;
    if(mySqList.insert(i, e) == ERROR)
        cout << "\t\t插入元素失败！" << endl;
    else
    {
        cout << "\t\t你要在第" << i << "个元素前插入元素" << e << endl;
        cout << "\t\t插入后的顺序表为：" << endl << mySqList;
    }

    cout << endl << "\t************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_2(MySqList<ElemType> & mySqList, char & continueYesNo)
{
    cout << "\t*******************判断顺序表是否为空*******************" << endl << endl;
    if (!mySqList.isEmpty())
        cout << "\t\t当前顺序表为空" << endl;
    else
        cout << "\t\t当前顺序表不为空" << endl;

    cout << endl << "\t*****************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_3(MySqList<ElemType> & mySqList, char & continueYesNo)
{
    cout << "\t*******************求顺序表中元素的个数*******************" << endl << endl;
    cout << "\t\t顺序表元素的个数为：" << mySqList.getLength() << endl;

    cout << endl << "\t******************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_4(MySqList<ElemType> & mySqList, char & continueYesNo)
{
    int i;
    ElemType e;

    cout << "\t*******************取第i个元素*******************" << endl << endl;
    cout << "\t\t请输入你想要取的元素的序号（1--" <<  mySqList.getLength() << "）：";

    cin >> i;
    if (i > mySqList.getLength())
    {
        cout << "\t\t输入有误！" << endl;
    }
    else
    {
        mySqList.getElem(i, e);

        cout << "\t\t你想要取的第" << i << "个元素的值为：" << e << endl;
    }

    cout << endl << "\t**********************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_5(MySqList<ElemType> & mySqList, char & continueYesNo)
{
    int i;
    ElemType e;

    cout << "\t*******************查找第i个与e满足compare（）关系的元素*******************" << endl << endl;

    cout << "\t\t查找等于某个元素的操作" << endl;
    cout << "\t\t请输入你想要查找的元素：";
    cin >> e;
    if ((i = mySqList.locateElem(e, equal)) == 0)
        cout << "\t\t没有找到符合条件的元素！" << endl;
    else
        cout << "\t\t你想要查找第一个等于" << e << "的元素序号为：" << i << endl;

    cout << "\t\t查找大于某个元素的操作" << endl;
    cout << "\t\t请输入你想要查找的元素：";
    cin >> e;
    if ((i = mySqList.locateElem(e, bigger)) == 0)
        cout << "\t\t没有找到符合条件的元素！" << endl;
    else
        cout << "\t\t你想要查找第一个大于" << e << "的元素序号为：" << i << endl;


    cout << "\t\t查找小于某个元素的操作" << endl;
    cout << "\t\t请输入你想要查找的元素：";
    cin >> e;
    if ((i = mySqList.locateElem(e, smaller)) == 0)
        cout << "\t\t没有找到符合条件的元素！" << endl;
    else
    cout << "\t\t你想要查找第一个小于" << e << "的元素序号为：" << i << endl;

    cout << endl << "\t**********************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_6(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    ElemType i, j;

    cout << "\t*******************返回元素的前驱*******************" << endl << endl;

    cout << "\t\t请输入你想要查找其前驱的元素：";
    cin >> i;

    if (mySqList.priorElem(i, j) == ERROR)
        cout << "\t\t输入序号有误！" << endl;
    else
        cout << endl << "\t\t你想要查找的元素" << i << "的前驱为：" << j << endl;

    cout << endl << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_7(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    ElemType i, j;

    cout << "\t*******************返回元素的后继*******************" << endl << endl;

    cout << "\t\t请输入你想要查找其后继的元素：";
    cin >> i;

    if (mySqList.nextElem(i, j) == ERROR)
        cout << "\t\t输入序号有误！" << endl;
    else
        cout << endl << "\t\t你想要查找的元素" << i << "的后继为：" << j << endl;

    cout << endl << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_8(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    int i;
    ElemType e;

    cout << "\t*******************删除第i个元素*******************" << endl << endl;

    cout << "\t\t请输入你想要删除元素的序号（1--" << mySqList.getLength() << "）：";
    cin >> i;

    if (mySqList.deleteElem(i, e) == ERROR)
        cout << "\t\t输入的序号有误！" << endl;
    else
    {
        cout << "\t\t你想要删除的第" << i << "个元素的值为：" << e << endl;

        if (mySqList.getLength() == 0)
            cout << "\t\t删除后的顺序表为空" << endl;
        else
        {
            cout << "\t\t删除后的顺序表为" << endl;
            cout << mySqList;
        }
    }

    cout << endl << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_9(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    MySqList<ElemType> otherSqList;
    ElemType i, j;

    otherSqList.insert(1, 48);
    otherSqList.insert(1, 41);

    mySqList = otherSqList;

    cout << "\t*******************把一个顺序表赋值给另一个顺序表*******************" << endl << endl;

    cout << "\t\t另一个顺序表赋值给当前顺序表为：" << endl;
    cout << mySqList;

    cout << endl << "\t***************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_10(MySqList<ElemType> &mySqList, char & continueYesNo)
{

    cout << "\t*******************把当前顺序表置空******************" << endl << endl;

    mySqList.clear();
    cout << endl << "\t\t当前顺序表置空后，元素的个数为：" << mySqList.getLength() << endl << endl;

    cout << endl << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_11(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    ElemType e;
    mySqList.clear();

    cout << "\t*******************随机生成顺序表（元素值为0到99之间的整数）******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前顺序表的元素：" << endl << "\t";
    for (int i=0; i < 10; ++i)
    {
        e = rand()%99-1;
        cout << e << "\t";
        mySqList.insert(i+1, e);
    }

    cout << endl << "\t\t随机生成的顺序表为：" << endl << mySqList;

    cout << endl << "\t***********************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_12(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    cout << "\t*******************用已有的顺序表初始化另一个顺序表******************" << endl << endl;

    MySqList<ElemType> otherSqList = MySqList<ElemType>(mySqList);
    cout << "\t\t当前的顺序表初始化另一个顺序表为：" << endl << mySqList;

    cout << endl << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_13(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    int n;
    ElemType e;
    mySqList.clear();
    cout << "\t*******************输入顺序表******************" << endl << endl;

    cout << "\t\t请输入顺序表中的个数：";
    cin >> n;
    cout << "\t\t请输入顺序表中的元素：";
    for (int i=0; i < n; ++i)
    {
        cin >> e;
        mySqList.insert(i+1, e);
    }

    cout << "\t\t新输入的顺序表为" << endl << mySqList;

    cout << endl << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_14(MySqList<ElemType> &mySqList, char & continueYesNo)
{
    int number = rand()%10 + 5;
    ElemType e;
    MySqList<ElemType> otherSqList = MySqList<ElemType>();

    for (int i=0; i < number; ++i)
    {
        e = rand()%99-1;
        otherSqList.insert(i+1, e);
    }

    cout << "\t*******************两个顺序表的并交差运算******************" << endl << endl;

    cout << "\t\t" << endl << mySqList;
    cout << "\t\t" << endl << otherSqList;

    cout << "\t\t" << endl;

    cout << "\t\t" << endl << unionSet(mySqList, otherSqList);
    cout << "\t\t" << endl << insersetionSet(mySqList, otherSqList);
    cout << "\t\t" << endl << dirfferenceSet(mySqList, otherSqList);

    cout << endl << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}



void ex3_1_15(char & continueYesNo)
{
    int choose;
    MySqList<Student> studentList;
    while (true)
    {
        choose = 0;
        continueYesNo = 'N';
        system("clear");

        cout << endl;
        cout << "\t*******************学生信息管理（顺序表的应用）******************" << endl << endl;
        cout << "\t\t1.在第i个学生之前插入一个学生" << endl;
        cout << "\t\t2.判断学生表是否为空" << endl;
        cout << "\t\t3.求学生表中学生的个数" << endl;
        cout << "\t\t4.返回第i个学生" << endl;
        cout << "\t\t5.返回某个学生的前驱" << endl;
        cout << "\t\t6.返回某个学生的后继" << endl;
        cout << "\t\t7.删除第i个学生" << endl;
        cout << "\t\t8.把一个学生表赋值给另一个学生表" << endl;
        cout << "\t\t9.把当前学生表置空" << endl;
        cout << "\t\t10.随机生成学生表" << endl;
        cout << "\t\t11.用已有的学生表初始化另一个学生表" << endl;
        cout << "\t\t12.输入学生表" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;
        displayMessage(studentList);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-12）号码：";
        cin >> choose;

        if (choose > 0 && choose < 13)
        {
            system("clear");
            cout << endl;
            displayMessage(studentList);
            cout << endl;
        }

        switch (choose)
        {
            case 1:
                ex3_1_15_1(studentList, continueYesNo);
                break;
            case 2:
                ex3_1_15_2(studentList, continueYesNo);
                break;
            case 3:
                ex3_1_15_3(studentList, continueYesNo);
                break;
            case 4:
                ex3_1_15_4(studentList, continueYesNo);
                break;
            case 5:
                ex3_1_15_5(studentList, continueYesNo);
                break;
            case 6:
                ex3_1_15_6(studentList, continueYesNo);
                break;
            case 7:
                ex3_1_15_7(studentList, continueYesNo);
                break;
            case 8:
                ex3_1_15_8(studentList, continueYesNo);
                break;
            case 9:
                ex3_1_15_9(studentList, continueYesNo);
                break;
            case 10:
                ex3_1_15_10(studentList, continueYesNo);
                break;
            case 11:
                ex3_1_15_11(studentList, continueYesNo);
                break;
            case 12:
                ex3_1_15_12(studentList, continueYesNo);
            default:
                cout << "" << endl << endl;
                break;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
        {
            continueYesNo = 'Y';
            break;
        }
    }
}

#endif //ALGORITHM_EX3_1_TEXT_H
