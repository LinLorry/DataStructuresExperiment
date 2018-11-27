//
// Created by lorry on 11/9/18.
//

#include <iostream>
#include <cassert>
using namespace std;

#include "../include/LinkList/ex3_2_Text.h"

int main()
{
    MyLinkList<int> myLinkList;

    int choose;
    char continueYesNo = 'N';

    while (true)
    {
        choose = 0;
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.取非循环单链表的第i个结点" << endl;
        cout << "\t\t2.在第i个结点之前插入一个结点" << endl;
        cout << "\t\t3.判断非循环单链表是否为空" << endl;
        cout << "\t\t4.求非循环单链表中元素的个数" << endl;
        cout << "\t\t5.查找第i个与e满足compare（）关系的元素" << endl;
        cout << "\t\t6.返回某结点前驱的数据域" << endl;
        cout << "\t\t7.返回某结点后继的数据域" << endl;
        cout << "\t\t8.删除非循环单链表中数据域为e的第一个结点" << endl;
        cout << "\t\t9.删除非循环单链表中的重复结点" << endl;
        cout << "\t\t10.非循环单链表的逆置" << endl;
        cout << "\t\t11.把一个非循环单链表赋值给另一个非循环单链表" << endl;
        cout << "\t\t12.把当前非循环单链表置空" << endl;
        cout << "\t\t13.随机生成非循环单链表（元素值为0到99之间的整数）" << endl;
        cout << "\t\t14.用已有的非循环单链表初始化另一个非循环单链表" << endl;
        cout << "\t\t15.输入非循环单链表" << endl;
        cout << "\t\t16.多项式的运算（非循环单链表的应用）" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;
        displayMessage(myLinkList);
        cout << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-15）号码：";
        cin >> choose;

        if (choose > 0 && choose < 16)
        {
            system("clear");
            displayMessage(myLinkList);
            cout << endl << endl;
        }

        switch (choose)
        {
            case 1:
                ex3_2_1(myLinkList, continueYesNo);
                break;
            case 2:
                ex3_2_2(myLinkList, continueYesNo);
                break;
            case 3:
                ex3_2_3(myLinkList, continueYesNo);
                break;
            case 4:
                ex3_2_4(myLinkList, continueYesNo);
                break;
            case 5:
                ex3_2_5(myLinkList, continueYesNo);
                break;
            case 6:
                ex3_2_6(myLinkList, continueYesNo);
                break;
            case 7:
                ex3_2_7(myLinkList, continueYesNo);
                break;
            case 8:
                ex3_2_8(myLinkList, continueYesNo);
                break;
            case 9:
                ex3_2_9(myLinkList, continueYesNo);
                break;
            case 10:
                ex3_2_10(myLinkList, continueYesNo);
                break;
            case 11:
                ex3_2_11(myLinkList, continueYesNo);
                break;
            case 12:
                ex3_2_12(myLinkList, continueYesNo);
                break;
            case 13:
                ex3_2_13(myLinkList, continueYesNo);
                break;
            case 14:
                ex3_2_14(myLinkList, continueYesNo);
                break;
            case 15:
                ex3_2_15(myLinkList, continueYesNo);
                break;
            case 16:
                ex3_2_16(continueYesNo);
                break;
            default:
                cout << "" << endl << endl;
                return 1;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
            break;
    }

    return 1;
}