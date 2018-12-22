//
// Created by lorry on 12/15/18.
//

#include <iostream>

#include "SqStack/ex4_1_Text.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    SqStack<int> sqStack;
    
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
        cout << "\t\t4.判断顺序栈是否为空" << endl;
        cout << "\t\t5.求顺序栈中元素的个数" << endl;
        cout << "\t\t6.把一个顺序栈赋值给另一个顺序栈" << endl;
        cout << "\t\t7.把顺序栈置空" << endl;
        cout << "\t\t8.随机生成顺序栈" << endl;
        cout << "\t\t9.用已有的顺序栈初始化另一个顺序栈" << endl;
        cout << "\t\t10.表达式求解" << endl;
        cout << "\t\t11.迷宫求解" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage(sqStack);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-11）号码：";
        cin >> choose;

        if (choose > 0 && choose < 11)
        {
            system("clear");
            displayMessage(sqStack);
        }

        switch (choose)
        {
            case 1:
                ex4_1_1(sqStack, continueYesNo);
                break;
            case 2:
                ex4_1_2(sqStack, continueYesNo);
                break;
            case 3:
                ex4_1_3(sqStack, continueYesNo);
                break;
            case 4:
                ex4_1_4(sqStack, continueYesNo);
                break;
            case 5:
                ex4_1_5(sqStack, continueYesNo);
                break;
            case 6:
                ex4_1_6(sqStack, continueYesNo);
                break;
            case 7:
                ex4_1_7(sqStack, continueYesNo);
                break;
            case 8:
                ex4_1_8(sqStack, continueYesNo);
                break;
            case 9:
                ex4_1_9(sqStack, continueYesNo);
                break;
            case 10:
                ex4_1_10(continueYesNo);
                break;
            case 11:
                ex4_1_11(sqStack, continueYesNo);
                break;
            default:
                cout << "退出程序..." << endl << endl;
                return 1;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n')
            break;
    }
    return 1;
}
