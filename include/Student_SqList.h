//
// Created by lorry on 11/9/18.
//
#include "Student.h"
#ifndef ALGORITHM_STUDENT_SQLIST_H
#define ALGORITHM_STUDENT_SQLIST_H

extern ostream & operator<< (ostream & out, const Student & stu);

void randStudent(Student & student)
{
    int i = rand()%10-1;
    char name[10][8] = {"lorry", "mike", "ccc", "aaa", "ddd", "eee", "fff", "ggg"};

    student.setID(rand()%99 - 1);
    student.setName(name[i]);
    student.setChinese(rand()%99);
    student.setEnglish(rand()%99);
    student.setMath(rand()%99);
    student.setAverage();
}

void displayCategoryMessage()
{
    cout << "\t\t学号\t姓名\t语文\t英语\t数学\t平均分\t总分" << endl;
}

void displayStudentList(MySqList<Student> & studentList)
{
    if (studentList.getLength() != 0)
    {
        Student stu;
        for (int i=1; i <= studentList.getLength(); ++i)
        {
            studentList.getElem(i, stu);
            cout << "\t\t" << stu << endl;
        }
    }
}

void displayMessage(MySqList<Student> & studentList)
{
    if (studentList.getLength() == 0)
        cout << endl <<  "\t\t当前学生表为空" << endl;
    else
    {
        cout << "\t\t当前学生表（采用顺序表存储）有" << studentList.getLength() << "个学生，分别为：" << endl << endl;
        displayCategoryMessage();
        displayStudentList(studentList);
    }
    cout << endl;

}

void ex3_1_15_1(MySqList<Student> & studentList, char & continueYesNo)
{
    int i;
    cout << "\t*******************在第i个学生之前插入一个学生*******************" << endl << endl;

    Student stu;
    cout << "\t\t请输入你要在第几个学生之前插入新学生：：";
    cin >> i;
    cout << "\t\t请输入你要插入的新学生的信息：" << endl;

    cout << "\t\t学号：";
    stu.inID();

    cout << "\t\t姓名：";
    stu.inName();

    cout << "\t\t语文成绩：";
    stu.inChinese();

    cout << "\t\t英语成绩：";
    stu.inEnglish();

    cout << "\t\t数学成绩：";
    stu.inMath();

    stu.setAverage();

    if(studentList.insert(i, stu) == ERROR)
        cout << "\t\t插入学生失败！" << endl;
    else
    {
        cout << "\t\t你要在第" << i << "个学生前插入新学生" << endl;
        displayCategoryMessage();
        cout << "\t\t" << stu << endl;
        cout << endl << "\t\t插入后的学生表为：" << endl << endl;
        displayCategoryMessage();
        displayStudentList(studentList);
    }

    cout << endl << "\t************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_1_15_2(MySqList<Student> & studentList, char & continueYesNo)
{
    cout << "\t*******************判断学生表是否为空*******************" << endl << endl;
    if (!studentList.isEmpty())
        cout << "\t\t当前学生表为空" << endl << endl;
    else
        cout << "\t\t当前学生表不为空" << endl << endl;

    cout << "\t*****************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_1_15_3(MySqList<Student> & studentList, char & continueYesNo)
{
    cout << "\t*******************求学生表中学生的个数*******************" << endl << endl;

    cout << "\t\t学生表学生的个数为：" << studentList.getLength() << endl << endl;

    cout << "\t******************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_1_15_4(MySqList<Student> & studentList, char & continueYesNo)
{
    int i;
    Student stu;

    cout << "\t*******************返回第i个学生*******************" << endl << endl;
    cout << "\t\t请输入你想要取的学生的序号（1--" <<  studentList.getLength() << "）：";

    cin >> i;
    if (i > studentList.getLength())
    {
        cout << "\t\t输入有误！" << endl << endl;
    }
    else
    {
        studentList.getElem(i, stu);

        cout << "\t\t你想要取的第" << i << "个学生的信息为：" << endl;
        displayCategoryMessage();
        cout << "\t\t" << stu << endl << endl;
    }

    cout << "\t************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_1_15_5(MySqList<Student> &studentList, char & continueYesNo)
{
    Student stu, stu_prior;

    cout << "\t*******************返回某个学生的前驱*******************" << endl << endl;

    cout << "\t\t请输入你想要查找其前驱的学生的姓名：";
    stu.inName();

    if (studentList.priorElem(stu, stu_prior) == ERROR)
        cout << "\t\t输入名字有误！" << endl;
    else
    {
        cout << endl << "\t\t你想要查找姓名为" << stu.getName() << "的前驱为：" << endl;
        displayCategoryMessage();
        cout << "\t\t" << stu_prior << endl << endl;
    }


    cout << endl << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ex3_1_15_6(MySqList<Student> &studentList, char & continueYesNo)
{
    Student stu, stu_next;

    cout << "\t*******************返回某个学生的后继*******************" << endl << endl;

    cout << "\t\t请输入你想要查找其后继的学生的姓名：";
    stu.inName();

    if (studentList.nextElem(stu, stu_next) == ERROR)
        cout << "\t\t输入名字有误！" << endl << endl;
    else
    {
        cout << endl << "\t\t你想要查找姓名为" << stu.getName() << "的后继为：" << endl;
        displayCategoryMessage();
        cout << "\t\t" << stu_next << endl << endl;

    }
    cout << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;

}

void ex3_1_15_7(MySqList<Student> &studentList, char & continueYesNo)
{
    int i;
    Student stu;

    cout << "\t*******************删除第i个学生*******************" << endl << endl;

    cout << "\t\t请输入你想要删除学生的序号（1--" << studentList.getLength() << "）：";
    cin >> i;

    if (studentList.deleteElem(i, stu) == ERROR)
        cout << "\t\t输入的名字有误！" << endl;
    else
    {
        cout << "\t\t你想要删除的第" << i << "个学生的信息为：" << endl;
        displayCategoryMessage();
        cout << "\t\t" << stu << endl << endl;

        if (studentList.getLength() == 0)
            cout << "\t\t删除后的学生表为空" << endl << endl;
        else
        {
            cout << "\t\t删除后的学生表为" << endl;
            displayCategoryMessage();
            displayStudentList(studentList);
            cout << endl;
        }
    }

    cout << "\t*************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}


void ex3_1_15_8(MySqList<Student> &studentList, char & continueYesNo)
{
    MySqList<Student> otherSqList;
    char name_1[8] = "123";
    char name_2[8] = "123";
    Student stu_1 = Student(1, name_1, 90, 78, 100);
    Student stu_2 = Student(2, name_2, 99, 99, 60);

    otherSqList.insert(1, stu_1);
    otherSqList.insert(1, stu_2);

    studentList = otherSqList;

    cout << "\t*******************把一个学生表赋值给另一个学生表*******************" << endl << endl;

    cout << "\t\t另一个学生表赋值给当前学生表为：" << endl;
    displayCategoryMessage();
    displayStudentList(studentList);
    cout << endl;

    cout << "\t***************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}


void ex3_1_15_9(MySqList<Student> &studentList, char & continueYesNo)
{

    cout << "\t*******************把当前学生表置空******************" << endl << endl;

    studentList.clear();
    cout << endl << "\t\t当前学生表置空后，学生的个数为：" << studentList.getLength() << endl << endl;

    cout << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}


void ex3_1_15_10(MySqList<Student> &studentList, char & continueYesNo)
{
    int i = rand()%10-1;
    char name[10][8] = {"lorry", "mike", "ccc", "aaa", "ddd", "eee", "fff", "ggg"};

    studentList.clear();

    cout << "\t*******************随机生成学生表******************" << endl << endl;

    cout << "\t\t用以下随机数作为当前学生表的学生：" << endl << endl;
    displayCategoryMessage();
    for (int i=0; i < 2; ++i)
    {
        Student stu = Student(
                            rand()%99,
                            name[i],
                            rand()%99,
                            rand()%99,
                            rand()%99);
        cout << "\t\t" << stu << endl;
        studentList.insert(i+1, stu);
    }

    cout << endl << "\t\t随机生成的学生表为：" << endl;
    displayCategoryMessage();
    displayStudentList(studentList);
    cout << endl;

    cout << "\t***********************************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}


void ex3_1_15_11(MySqList<Student> &studentList, char & continueYesNo)
{
    cout << "\t*******************用已有的学生表初始化另一个学生表******************" << endl << endl;

    MySqList<Student> otherSqList = MySqList<Student>(studentList);
    cout << "\t\t当前的学生表初始化另一个学生表为：" << endl << endl;
    displayCategoryMessage();
    displayStudentList(studentList);
    cout << endl << endl;

    cout << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}


void ex3_1_15_12(MySqList<Student> &studentList, char & continueYesNo)
{
    int n;
    Student stu;
    studentList.clear();
    cout << "\t*******************输入学生表******************" << endl << endl;

    cout << "\t\t请输入学生表中的个数：";
    cin >> n;
    for (int i=1; i <= n; ++i)
    {
        system("clear");
        displayMessage(studentList);
        cout << endl << "\t**************************************************" << endl << endl;
        cout << "\t\t请输入学生表第" << i << "个学生信息：" << endl << endl;

        cout << "\t\t学号：";
        stu.inID();

        cout << "\t\t姓名：";
        stu.inName();

        cout << "\t\t语文成绩：";
        stu.inChinese();

        cout << "\t\t英语成绩：";
        stu.inEnglish();

        cout << "\t\t数学成绩：";
        stu.inMath();

        stu.setAverage();

        studentList.insert(i, stu);
    }

    system("clear");
    cout << "\t\t*******************重新输入一个学生表******************" << endl << endl;

    displayMessage(studentList);

    cout << endl << endl << "\t**************************************************" << endl << endl;
    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

#endif //ALGORITHM_STUDENT_SQLIST_H
