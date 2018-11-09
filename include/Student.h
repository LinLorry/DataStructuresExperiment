//
// Created by lorry on 11/9/18.
//

#include <iostream>
using namespace std;

#ifndef ALGORITHM_STUDENT_H
#define ALGORITHM_STUDENT_H

class Student
{
public:
    const int getID() const;
    void setID(int ID);
    void inID();

    const char* getName() const;
    void setName(char* name);
    void inName();

    const float getChinese() const;
    void setChinese(float chinese);
    void inChinese();

    const float getEnglish() const;
    void setEnglish(float english);
    void inEnglish();

    const float getMath() const;
    void setMath(float math);
    void inMath();

    const float getAverage() const;
    void setAverage();

    const float getSum() const;
    void setSum();

    void display(ostream & out = cout) const;

    bool operator==(const Student & stu);

    Student();
    Student(int ID, char* name, float chinese, float english, float math);
    ~Student();

private:
    int id;
    char name[8];
    float chinese;
    float english;
    float math;

    float average;
    float sum;
};

#endif //ALGORITHM_STUDENT_H
