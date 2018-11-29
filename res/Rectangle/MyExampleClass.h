#include "ExampleClass.h"

#ifndef MYEXAMPLECLASS_H
#define MYEXAMPLECLASS_H

template <typename ElemType>
class MyRectangle :public Rectangle<ElemType>
{
public:
	void read(istream & in);
	
	void display(ostream & out) const;
};

template <typename ElemType>
void MyRectangle<ElemType>::read(istream & in)
{
	cout << "\t请输入第" << this->myNo.no << "个长方形对象" << endl;
	cout << "\t\t长方形的长 ： ";
	in >> this->length;
	cout << "\t\t长方形的宽 ： ";
	in >> this->width;
}

template <typename ElemType>
istream & operator>>(istream & in, MyRectangle<ElemType> & iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyRectangle<ElemType>::display(ostream & out) const
{
	out << "\t\t第" << this->myNo.no << "个长方形" << endl;
	out << "\t\t\t的长 ： " << this->length << endl;
	out << "\t\t\t的宽 ： " << this->width << endl;
}

template <typename ElemType>
ostream& operator<<(ostream & out, const MyRectangle<ElemType> & oD)
{
	oD.display(out);
	return out;
}
#endif