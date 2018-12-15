//
// Created by lorry on 12/7/18.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "DoubleLinkList/ex3_4_Text.h"

int main()
{
    MyDoubleLinkList<int> myDoubleLinkList;

    int choose;
    char continueYesNo = 'N';

    while (true)
    {
        choose = 0;
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.取循环双链表第i个结点的数据域" << endl;
        cout << "\t\t2.在第i个结点之前插入一个数据域为e的结点" << endl;
        cout << "\t\t3.判断循环双链表是否为空" << endl;
        cout << "\t\t4.求循环双链表中结点的个数" << endl;
        cout << "\t\t5.返回循环双链表中数据域为e的第一个结点的指针" << endl;
        cout << "\t\t6.返回某结点前驱的数据域" << endl;
        cout << "\t\t7.返回某结点后继的数据域" << endl;
        cout << "\t\t8.删除循环双链表中数据域为e的第一个结点" << endl;
        cout << "\t\t9.把一个循环双链表赋值给另一个循环双链表" << endl;
        cout << "\t\t10.把循环双链表置空" << endl;
        cout << "\t\t11.随机生成循环双链表" << endl;
        cout << "\t\t12.用已有的循环双链表初始化另一个循环双链表" << endl;
        cout << "\t\t13.输入非循环双链表" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage(myDoubleLinkList);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-13）号码：";
        cin >> choose;

        if (choose > 0 && choose < 13)
        {
            system("clear");
            displayMessage(myDoubleLinkList);
        }

        switch (choose)
        {
            case 1:
                ex3_4_1(myDoubleLinkList, continueYesNo);
                break;
            case 2:
                ex3_4_2(myDoubleLinkList, continueYesNo);
                break;
            case 3:
                ex3_4_3(myDoubleLinkList, continueYesNo);
                break;
            case 4:
                ex3_4_4(myDoubleLinkList, continueYesNo);
                break;
            case 5:
                ex3_4_5(myDoubleLinkList, continueYesNo);
                break;
            case 6:
                ex3_4_6(myDoubleLinkList, continueYesNo);
                break;
            case 7:
                ex3_4_7(myDoubleLinkList, continueYesNo);
                break;
            case 8:
                ex3_4_8(myDoubleLinkList, continueYesNo);
                break;
            case 9:
                ex3_4_9(myDoubleLinkList, continueYesNo);
                break;
            case 10:
                ex3_4_10(myDoubleLinkList, continueYesNo);
                break;
            case 11:
                ex3_4_11(myDoubleLinkList, continueYesNo);
                break;
            case 12:
                ex3_4_12(myDoubleLinkList, continueYesNo);
                break;
            case 13:
                ex3_4_13(myDoubleLinkList, continueYesNo);
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
