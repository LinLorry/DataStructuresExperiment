#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

#include "../include/Rectangle/ex2_1_Text.h"

int main()
{
    MyRectangle<int> rec;

    int choose;
    char continueYesNo = 'N';

    while (1)
    {
        choose = 0;
        system("clear");
        cout << endl;
        cout << "\t********************************" <<endl << endl;
        cout << "\t\t1.设置长方形的序号" << endl;
        cout << "\t\t2.设置长方形的长" << endl;
        cout << "\t\t3.重载赋值运算符的定义" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////" << endl;
        displayCurrentObject(rec);
        cout << "////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-3）号码：";
        cin >> choose;

        if (choose > 0 && choose <4)
        {
            system("clear");
            displayCurrentObject(rec);
        }

        switch (choose)
        {
            case 1:
                ex2_1_1(rec, continueYesNo);
                break;
            case 2:
                ex2_1_2(rec, continueYesNo);
                break;
            case 3:
                ex2_1_3(rec, continueYesNo);
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