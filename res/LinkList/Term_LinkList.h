//
// Created by lorry on 11/23/18.
//

#include "MyLinkList.h"
#include "../Models/Term.h"

#ifndef ALGORITHM_MYTERM_LINKLIST_H
#define ALGORITHM_MYTERM_LINKLIST_H

extern ostream & operator<< (ostream & out, const Term & term);

void displayCurrentObject(MyLinkList<Term> & termLinkList);

void displayMessage(MyLinkList<Term> & termLinkList);

void termAddTerm(MyLinkList<Term> & t_1, const MyLinkList<Term> & t_2);

void termSubTerm(MyLinkList<Term> & t_1, const MyLinkList<Term> & t_2);

void ex3_2_16_1(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_2(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_3(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_4(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_5(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_6(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_7(MyLinkList<Term> & termList, char & continueYesNo);

void ex3_2_16_8(MyLinkList<Term> & termList, char & continueYesNo);

#endif //ALGORITHM_MYTERM_LINKLIST_H
