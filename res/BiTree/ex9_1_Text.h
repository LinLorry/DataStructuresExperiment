//
// Created by lorry on 12/26/18.
//

#include <cmath>
#include <random>
#include <string>
#include <iostream>

#include "../../include/myhead.h"
#include "MyBiTree.h"

using std::pow;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::uniform_int_distribution;

#ifndef ALGORITHM_EX9_1_TEXT_H
#define ALGORITHM_EX9_1_TEXT_H

template <typename Object>
void printVector(const vector<Object> & v)
{
    if (v.empty())
        return;
    cout << "\t\t";
    unsigned long  size = v.size();
    for (int i=0; i<size; ++i)
        cout << "[" << i << "]" << "\t";
    cout << endl << "\t\t";
    for (auto itr: v)
        cout << itr << "\t";
    cout << endl;
}

template <typename Object>
class BiTreeExperiment
{
public:
    BiTreeExperiment():
        biTree{ MyBiTree<Object>() }, continueYesNo { 'Y' }, choose { 0 } { }
public:
    void init()
    {
        while (true)
        {
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
            displayMessage();
            cout << "////////////////////////////////////////////////////////" << endl << endl;

            cout << "\t请输入你要操作的代码（1-20）号码：";
            cin >> choose;

            if (choose > 0 && choose < 21)
            {
                system("clear");
                displayMessage();
            }

            switch (choose)
            {
                case 1:
                    countBiTreeNode();
                    break;
                case 2:
                    countBiTreeLeaf();
                    break;
                case 3:
                    getBiTreeDepth();
                    break;
                case 4:
                    exchangeBiTreeLeftRight();
                    break;
                case 5:
                    preOrderTraverseBiTree();
                    break;
                case 6:
                    infixOrderTraverseBiTree();
                    break;
                case 7:
                    afterOrderTraverseBiTree();
                    break;
                case 8:
                    nonRecursiveInfixOrderTraverseBiTree();
                    break;
                case 9:
                    traverseBiTree();
                    break;
                case 10:
                    printBiTreeVector();
                    break;
                case 11:
                    transBiTreeVector();
                    break;
                case 12:
                    setBiTreeByVector();
                    break;
                case 13:
                    generateRandomBiTree();
                    break;
                case 14:
                    inputBiTree();
                    break;
                default:
                    cout << endl << "退出程序..." << endl << endl;
                    return;
            }

            if (continueYesNo == 'N' || continueYesNo == 'n')
                break;
        }
    }

private:
    void displayMessage(const string & str="当前非循环链队中的元素为",
            const string & error="当前非循环链队中为空") const
    {
        if (biTree.empty())
            cout << endl << "\t\t" << error << endl << endl;
        else
        {
            cout << endl << "\t\t" << str << endl;
            displayCurrentObject();
            cout << endl << endl;
        }
    }

    void displayCurrentObject() const
    {
        int depth = biTree.depth();
        int node = biTree.countNode();
        vector<Object> v = biTree.getVector();

        cout << "\t\t";
        for(int i=0; i<depth; ++i)
        {
            double x = i==depth-1?(node-pow(2, depth-1)-1):pow(2, i);
            double n = 2*(depth-i-1);
            double m = i==0?0:pow(2, i)-1;
            double h = pow(2, i+1)-1;

            if (i!=0)
            {
                for(double j=0; j < n; ++j)
                    cout << " ";

                for(double j=m; j<x && j<node; ++j)
                {
                    cout << " / \\ ";
                }
                cout << endl << "\t\t";
            }

            for(double j=0; j < n; ++j)
                cout << " ";
            for(double j=m; j<h && j<node; ++j)
            {
                cout << v[j] << "   ";
            }
            cout << endl << "\t\t";
        }

    }

    void countBiTreeNode()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        int node = biTree.countNode();
        cout << "\t\t当前二叉树的结点数为：" << node << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

    void countBiTreeLeaf()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        int leaf = biTree.countLeaf();
        cout << "\t\t当前二叉树的叶子数为：" << leaf << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

    void getBiTreeDepth()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        int depth = biTree.depth();
        cout << "\t\t当前二叉树的深度为：" << depth << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> continueYesNo;
    }

    void exchangeBiTreeLeftRight()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        biTree.exchangeLeftRight();

        displayMessage("交换二叉树中所有结点的左右子树：");

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> continueYesNo;
    }

    void preOrderTraverseBiTree()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        string str = biTree.preOrderTraverse();

        cout << "\t\t当前二叉树按前序递归遍历的结点序列为：" << str << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> continueYesNo;
    }

    void infixOrderTraverseBiTree()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        string str = biTree.infixOrderTraverse();

        cout << "\t\t当前二叉树按中序递归遍历的结点序列为：" << str << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> continueYesNo;
    }

    void afterOrderTraverseBiTree()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        string str = biTree.afterOrderTraverse();

        cout << "\t\t当前二叉树按后序递归遍历的结点序列为：" << str << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> continueYesNo;
    }

    void nonRecursiveInfixOrderTraverseBiTree()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        string str = biTree.nonRecursiveInfixOrderTraverse();

        cout << "\t\t非递归中序遍历当前二叉树的结点为：" << str << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> continueYesNo;
    }

    void traverseBiTree()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        string str = biTree.traverse();

        cout << "\t\t按层次顺序遍历当前二叉树中的结点为：" << str << endl << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

    void printBiTreeVector()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        cout << "\t\t" << endl;
        printVector(biTree.getVector());
        cout << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

    void transBiTreeVector()
    {
        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        cout << "\t\t" << endl;
        printVector(biTree.getVector());
        cout << endl;

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

    void setBiTreeByVector()
    {
        int num;
        Object object;
        vector<Object> v;

        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        cout << "\t\t" << endl;
        cin >> num;

        for (int i=0; i<num; ++i)
        {
            cin >> object;
            v.push_back(object);
        }

        biTree.setFromVector(v);

        printVector(v);
        displayMessage("");

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

    void generateRandomBiTree()
    {
        uniform_int_distribution<unsigned> uniform(5, 10);
        int n = uniform(engine);

        vector<Object> v;

        for(int i=0; i<n; ++i, ++id)
        {
            v.push_back(id);
        }

        biTree.clear();
        biTree.setFromVector(v);
    }

    void inputBiTree()
    {
        int num;
        Object object;
        vector<Object> v;

        cout << "\t*******************判断非循环链队是否为空*******************" << endl << endl;

        cout << "\t\t" << endl;
        cin >> num;

        for (int i=0; i<num; ++i)
        {
            cin >> object;
            v.push_back(object);
        }

        biTree.setFromVector(v);

        printVector(v);
        displayMessage("");

        cout << "\t**********************************************" << endl << endl;

        cout << "\t\t还继续吗（Y.继续 N.结束）？";
        cin >> this->continueYesNo;
    }

private:
    MyBiTree<Object> biTree;

    static char id;

    char continueYesNo;
    int choose;
};

template <typename Object>
char BiTreeExperiment<Object>::id = 65;

#endif //ALGORITHM_EX9_1_TEXT_H
