//
// Created by lorry on 12/27/18.
//

#include <vector>
#include <list>
#include <iostream>
#include <random>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::uniform_int_distribution;

#include "SortingExperiment.h"

SortingExperiment::SortingExperiment():
    v { *(new vector<double>()) }, l { *(new list<double>()) },
    choose { 0 }, continueYesNo { 'Y' } { }

void SortingExperiment::init()
{
    while (true)
    {
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.进队列" << endl;
        cout << "\t\t2.出队列" << endl;
        cout << "\t\t3.读非循环链队头结点的数据域" << endl;
        cout << "\t\t4.判断非循环链队是否为空" << endl;
        cout << "\t\t5.求非循环链队中元素的个数" << endl;
        cout << "\t\t6.把一个非循环链队赋值给另一个非循环链队" << endl;
        cout << "\t\t7.把非循环链队置空" << endl;
        cout << "\t\t8.随机生成非循环链队" << endl;
        cout << "\t\t9.用已有的非循环链队初始化另一个非循环链队" << endl;
        cout << "\t\t10.停车场管理" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage();
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-20）号码：";
        cin >> choose;

        if (choose > 0 && choose < 14)
        {
            system("clear");
            displayMessage();
        }

        switch (choose)
        {
            case 1:
                insertSort();
                break;
            case 2:
                binaryInsertSort();
                break;
            case 3:
                staticListInsertSort();
                break;
            case 4:
                shellSort();
                break;
            case 5:
                bubbleSort();
                break;
            case 6:
                quickSort();
                break;
            case 7:
                selectSort();
                break;
            case 8:
                heapSort();
                break;
            case 9:
                mergeSort();
                break;
            case 10:
                radixSort();
                break;
            case 11:
                randomGenerateVector();
                break;
            case 12:
                randomGenerateList();
                break;
            case 13:
                inputVector();
                break;
            default:
                cout << endl << "退出程序..." << endl << endl;
                return;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
            break;
    }
}

void SortingExperiment::displayMessage(const string &str, const string &error) const
{
    if (v.empty())
        cout << endl << "\t\t" << error << endl << endl;
    else
    {
        cout << endl << "\t\t" << str << endl;
        displayCurrentObject();
        cout << endl << endl;
    }
}

void SortingExperiment::displayCurrentObject() const
{
    unsigned long size = v.size();

    cout << "\t\t";
    for (long i = 0; i<size; ++i)
        cout << "[" << i << "]\t";

    cout << endl << "\t\t";
    for (auto itr: v)
        cout << itr << "\t";
    cout << endl;
}

void SortingExperiment::insertSort()
{

}

void SortingExperiment::binaryInsertSort()
{

}

void SortingExperiment::staticListInsertSort()
{

}

void SortingExperiment::shellSort()
{

}

void SortingExperiment::bubbleSort()
{

}

void SortingExperiment::quickSort()
{

}

void SortingExperiment::selectSort()
{

}

void SortingExperiment::heapSort()
{

}

void SortingExperiment::mergeSort()
{

}

void SortingExperiment::radixSort()
{

}

void SortingExperiment::randomGenerateVector()
{
    uniform_int_distribution<unsigned> uniform(1, 500);
    double num;

    cout << "\t*******************在第i个元素之前插入一个元素*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前非循环单链表的元素：" << endl << "\t\t";

    for (int i=0; i < 10; ++i)
    {
        num = uniform(engine);
        cout << num << "\t";
        v.push_back(num);
    }

    cout << endl << "\t************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;

}

void SortingExperiment::randomGenerateList()
{
    uniform_int_distribution<unsigned> uniform(1, 500);
    double num;

    cout << "\t*******************在第i个元素之前插入一个元素*******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前非循环单链表的元素：" << endl << "\t\t";

    for (int i=0; i < 10; ++i)
    {
        num = uniform(engine);
        cout << num << "\t";
        l.push_back(num);
    }

    cout << endl << "\t************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void SortingExperiment::inputVector()
{
    int n;
    double num;

    cout << "\t*******************在第i个元素之前插入一个元素*******************" << endl << endl;

    cout << "\t\t请输入非循环单链表中的个数：";
    cin >> n;
    cout << "\t\t请输入非循环单链表中的元素：";
    for (int i=0; i < n; ++i)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << endl << "\t************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}
