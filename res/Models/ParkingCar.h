//
// Created by lorry on 12/26/18.
//

#include <string>

#include "Car.h"

using std::string;

#ifndef ALGORITHM_PARKINGCAR_H
#define ALGORITHM_PARKINGCAR_H


class ParkingCar
{
public:
    ParkingCar()= default;

    explicit ParkingCar(unsigned t);

    ParkingCar(const ParkingCar & rhs);

public:
    const string & getCarId() const;

    const unsigned getParkingTime() const;

private:
    Car car;
    unsigned time;
};


#endif //ALGORITHM_PARKINGCAR_H
