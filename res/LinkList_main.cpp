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
        cout << "\t\t1.在第i个元素之前插入一个元素" << endl;
        cout << "\t\t2.判断顺序表是否为空" << endl;
        cout << "\t\t3.求顺序表中元素的个数" << endl;
        cout << "\t\t4.取第i个元素" << endl;
        cout << "\t\t5.查找第i个与e满足compare（）关系的元素" << endl;
        cout << "\t\t6.返回元素的前驱" << endl;
        cout << "\t\t7.返回元素的后继" << endl;
        cout << "\t\t8.删除第i个元素" << endl;
        cout << "\t\t9.把一个顺序表赋值给另一个顺序表" << endl;
        cout << "\t\t10.把当前顺序表置空" << endl;
        cout << "\t\t11.随机生成顺序表（元素值为0到99之间的整数）" << endl;
        cout << "\t\t12.用已有的顺序表初始化另一个顺序表" << endl;
        cout << "\t\t13.输入顺序表" << endl;
        cout << "\t\t14.两个顺序表的并交差运算" << endl;
        cout << "\t\t15.学生信息管理（顺序表的应用）" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl << endl;
        displayCurrentObject(myLinkList);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-15）号码：";
        cin >> choose;

        if (choose > 0 && choose < 16)
        {
            system("clear");
            displayCurrentObject(myLinkList);
        }

        /*switch (choose)
        {
            case 1:
                ex3_1_1(myLinkList, continueYesNo);
                break;
            case 2:
                ex3_1_2(myLinkList, continueYesNo);
                break;
            case 3:
                ex3_1_3(myLinkList, continueYesNo);
                break;
            case 4:
                ex3_1_4(myLinkList, continueYesNo);
                break;
            case 5:
                ex3_1_5(myLinkList, continueYesNo);
                break;
            case 6:
                ex3_1_6(myLinkList, continueYesNo);
                break;
            case 7:
                ex3_1_7(myLinkList, continueYesNo);
                break;
            case 8:
                ex3_1_8(myLinkList, continueYesNo);
                break;
            case 9:
                ex3_1_9(myLinkList, continueYesNo);
                break;
            case 10:
                ex3_1_10(myLinkList, continueYesNo);
                break;
            case 11:
                ex3_1_11(myLinkList, continueYesNo);
                break;
            case 12:
                ex3_1_12(myLinkList, continueYesNo);
                break;
            case 13:
                ex3_1_13(myLinkList, continueYesNo);
                break;
            case 14:
                ex3_1_14(myLinkList, continueYesNo);
                break;
            case 15:
                ex3_1_15(continueYesNo);
                break;
            default:
                cout << "" << endl << endl;
                return 1;
        }*/

        if (continueYesNo == 'N' || continueYesNo == 'n')
            break;
    }

    return 1;
}