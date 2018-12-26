//
// Created by lorry on 12/26/18.
//

#include "../Models/ParkingCar.h"
#include "CarQueue.h"

#ifndef ALGORITHM_PARKSYSTEM_H
#define ALGORITHM_PARKSYSTEM_H

class ParkSystem
{
public:
    ParkSystem();

public:
    void init();

    void startParkSystem();

    void exSetMaxCarNum();

    void exSetCharge();

    void randomParkingCar();

private:
    void displayMessage() const;

    void setMaxCarNum(unsigned m);

    void setCharge(unsigned c);

    void displayCurrentObject() const;

    void outCar();

    void inCar();

private:
    CarQueue carQueue;

    unsigned maxCarNum;
    unsigned charge;
    unsigned time;

    int choose;
    char continueYesNo;
};


#endif //ALGORITHM_PARKSYSTEM_H
