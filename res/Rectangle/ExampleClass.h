#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

template <typename ElemType>
class Rectangle
{
public:
    class RectangleNo
    {
    public:
        int no;
    };

    Rectangle & operator= (Rectangle & rightR);
    Rectangle operator=(Rectangle && rightR);

    void setLength(ElemType l);
    void setWidth(ElemType w);

    void setNo(int i);

    Rectangle();
    Rectangle(const Rectangle<ElemType> & otherD);

    ~Rectangle();

protected:
    ElemType length;
    ElemType width;
    RectangleNo myNo;
};

template <typename ElemType>
Rectangle<ElemType> & Rectangle<ElemType>::operator=(Rectangle<ElemType> & rightR)
{
    if (this != &rightR)
    {
        this->length = rightR.length;
        this->width = rightR.width;
        this->myNo = rightR.myNo;

        cout << "\t赋值后，当前长方形为 (" << length << "," << width << ")" << endl;
    }

    return *this;
}

template <typename ElemType>
Rectangle<ElemType> Rectangle<ElemType>::operator=(Rectangle<ElemType> && rightR)
{
    return *this;
}

template <typename ElemType>
void Rectangle<ElemType>::setLength(ElemType l)
{
    length = l;
}

template <typename ElemType>
void Rectangle<ElemType>::setWidth(ElemType w){
    width = w;
}

template <typename ElemType>
void Rectangle<ElemType>::setNo(int i)
{
    myNo.no = i;
}

template <typename ElemType>
Rectangle<ElemType>::Rectangle()
{
    length = width = 0;
    cout << "\t自动调用构造函数" << endl;
}

template <typename ElemType>
Rectangle<ElemType>::Rectangle(const Rectangle<ElemType> & otherD)
{
    length = otherD.length;
    width = otherD.width;
    myNo = otherD.myNo;
    cout << "\t自动调用拷贝初始化构造函数初始化为 (";
    cout << length << "," << width << ")" << endl;
}

template <typename ElemType>
Rectangle<ElemType>::~Rectangle()
{
    cout << "\t第" << this->myNo.no << "个长方形对象 (";
    cout << length << "," << width << ")生存期结束"<< endl;
}

#endif