//
// Created by lorry on 12/27/18.
//

#include <vector>
#include <list>
#include <string>

#include "../../include/myhead.h"

using std::vector;
using std::list;
using std::string;

#ifndef ALGORITHM_SORTINGEXPERIMENT_H
#define ALGORITHM_SORTINGEXPERIMENT_H


class SortingExperiment
{
public:
    SortingExperiment();

public:
    void init();

private:

    void displayMessage(const string & str="当前非循环链队中的元素为",
                        const string & error="当前非循环链队中为空") const;

    void displayCurrentObject() const;

    void insertSort();

    void binaryInsertSort();

    void staticListInsertSort();

    void shellSort();

    void bubbleSort();

    void quickSort();

    void selectSort();

    void heapSort();

    void mergeSort();

    void radixSort();

    void randomGenerateVector();

    void randomGenerateList();

    void inputVector();

private:
    vector<double> v;
    list<double> l;

    char continueYesNo;
    int choose;
};


#endif //ALGORITHM_SORTINGEXPERIMENT_H
