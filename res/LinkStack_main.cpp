//
// Created by lorry on 12/22/18.
//

#include <iostream>

#include "LinkStack/ex4_2_Text.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    LinkStack<int> linkStack;

    int choose;
    char continueYesNo = 'N';

    while (true)
    {
        choose = 0;
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.在栈顶压入元素e" << endl;
        cout << "\t\t2.弹出栈顶的元素到e" << endl;
        cout << "\t\t3.读栈顶的元素" << endl;
        cout << "\t\t4.判断链栈是否为空" << endl;
        cout << "\t\t5.求链栈中元素的个数" << endl;
        cout << "\t\t6.把一个链栈赋值给另一个链栈" << endl;
        cout << "\t\t7.把链栈置空" << endl;
        cout << "\t\t8.随机生成链栈" << endl;
        cout << "\t\t9.用已有的链栈初始化另一个链栈" << endl;

        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage(linkStack);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-9）号码：";
        cin >> choose;

        if (choose > 0 && choose < 10)
        {
            system("clear");
            displayMessage(linkStack);
        }

        switch (choose)
        {
            case 1:
                ex4_2_1(linkStack, continueYesNo);
                break;
            case 2:
                ex4_2_2(linkStack, continueYesNo);
                break;
            case 3:
                ex4_2_3(linkStack, continueYesNo);
                break;
            case 4:
                ex4_2_4(linkStack, continueYesNo);
                break;
            case 5:
                ex4_2_5(linkStack, continueYesNo);
                break;
            case 6:
                ex4_2_6(linkStack, continueYesNo);
                break;
            case 7:
                ex4_2_7(linkStack, continueYesNo);
                break;
            case 8:
                ex4_2_8(linkStack, continueYesNo);
                break;
            case 9:
                ex4_2_9(linkStack, continueYesNo);
                break;
            default:
                cout << endl << "退出程序..." << endl << endl;
                return 1;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
            break;
    }
    return 1;
}
