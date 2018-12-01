//
// Created by lorry on 11/29/18.
//

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include "CircularLinkList/ex3_3_Text.h"

int main()
{
    MyCircularLinkList<int> myCircularLinkList;

    int choose;
    char continueYesNo = 'N';

    while (true)
    {
        choose = 0;
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.判断循环单链表是否为空" << endl;
        cout << "\t\t2.把循环单链表的头指针后移至第i个结点" << endl;
        cout << "\t\t3.删除第i个结点，头指针移至其后下一个结点" << endl;
        cout << "\t\t4.把一个循环单链表赋值给另一个循环单链表" << endl;
        cout << "\t\t5.把循环单链表置空" << endl;
        cout << "\t\t6.随机生成循环单链表" << endl;
        cout << "\t\t7.用已有的循环单链表初始化另一个循环单链表" << endl;
        cout << "\t\t8.输入非循环单链表" << endl;
        cout << "\t\t9.约瑟夫环（Josephus）出列" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage(myCircularLinkList, "当前循环单链表为：");
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-9）号码：";
        cin >> choose;

        if (choose > 0 && choose < 9)
        {
            system("clear");
            displayMessage(myCircularLinkList, "当前循环单链表为：");
        }

        switch (choose)
        {
            case 1:
                ex3_3_1(myCircularLinkList, continueYesNo);
                break;
            case 2:
                ex3_3_2(myCircularLinkList, continueYesNo);
                break;
            case 3:
                ex3_3_3(myCircularLinkList, continueYesNo);
                break;
            case 4:
                ex3_3_4(myCircularLinkList, continueYesNo);
                break;
            case 5:
                ex3_3_5(myCircularLinkList, continueYesNo);
                break;
            case 6:
                ex3_3_6(myCircularLinkList, continueYesNo);
                break;
            case 7:
                ex3_3_7(myCircularLinkList, continueYesNo);
                break;
            case 8:
                ex3_3_8(myCircularLinkList, continueYesNo);
                break;
            case 9:
                ex3_3_9(myCircularLinkList, continueYesNo);
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
