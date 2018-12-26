//
// Created by lorry on 12/26/18.
//

#include <iostream>

#include "LinkQueue/ex5_2_Text.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    LinkQueue<int> linkQueue;

    int choose;
    char continueYesNo = 'N';

    while (true)
    {
        choose = 0;
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
        displayMessage(linkQueue);
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-10）号码：";
        cin >> choose;

        if (choose > 0 && choose < 11)
        {
            system("clear");
            displayMessage(linkQueue);
        }

        switch (choose)
        {
            case 1:
                ex5_2_1(linkQueue, continueYesNo);
                break;
            case 2:
                ex5_2_2(linkQueue, continueYesNo);
                break;
            case 3:
                ex5_2_3(linkQueue, continueYesNo);
                break;
            case 4:
                ex5_2_4(linkQueue, continueYesNo);
                break;
            case 5:
                ex5_2_5(linkQueue, continueYesNo);
                break;
            case 6:
                ex5_2_6(linkQueue, continueYesNo);
                break;
            case 7:
                ex5_2_7(linkQueue, continueYesNo);
                break;
            case 8:
                ex5_2_8(linkQueue, continueYesNo);
                break;
            case 9:
                ex5_2_9(linkQueue, continueYesNo);
                break;
            case 10:
                ex5_2_10();
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
