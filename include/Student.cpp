//
// Created by lorry on 11/9/18.
//

#include <iostream>
#include <string.h>
using namespace std;

#include "Student.h"

const int Student::getID() const{ return this->id; }
void Student::setID(int ID) { this->id = ID; }
void Student::inID() { cin >> this->id; }

const char* Student::getName() const{ return this->name; }
void Student::setName(char *name)
{
    char* p = name;
    char* q = this->name;
    for(; *p; ++p, ++q)
        *q = *p;

}
void Student::inName() { cin >> this->name; }

const float Student::getChinese() const{ return this->chinese; }
void Student::setChinese(float chinese){ this->chinese = chinese; }
void Student::inChinese() { cin >> this->chinese; }

const float Student::getEnglish() const{ return this->english; }
void Student::setEnglish(float english){ this->english = english; }
void Student::inEnglish() { cin >> this->english; }

const float Student::getMath() const{ return this->math; }
void Student::setMath(float math){ this->math = math; }
void Student::inMath(){ cin >> this->math; }

const float Student::getAverage() const { return this->average; }
void Student::setAverage()
{
    this->setSum();
    this->average = this->sum / 3;
}

const float Student::getSum() const { return this->sum; }
void Student::setSum()
{
    this->sum = this->chinese +
            this->english +
            this->math;
}

void Student::display(ostream &out) const
{
    out << getID() << "\t"
        << getName() << "\t"
        << getChinese() << "\t"
        << getEnglish() << "\t"
        << getMath() << "\t"
        << getAverage() << "\t"
        << getSum() << "\t";
}


bool Student::operator==(const Student & stu)
{
    if (strcmp(getName(), stu.getName()))
        return false;
    else
        return true;
    /*int i;
    char const *p = this->getName(), *q = stu.getName();
    for(i = 0;*(p + i) || *(q + i);++i)
    {
        if (*(p + i) != *(q + i))
            return false;
    }
    if(*(p + i) && *(q + i))
        return true;
    else
        return false;*/
}

Student::Student() {}
Student::Student(int ID, char *name, float chinese, float english, float math)
{
    this->id = ID;
    strcpy(this->name, name);
    this->chinese = chinese;
    this->english = english;
    this->math = math;
    this->setAverage();
}

Student::~Student() {}

ostream & operator<< (ostream & out, const Student & stu)
{
    stu.display(out);
    return out;
}
