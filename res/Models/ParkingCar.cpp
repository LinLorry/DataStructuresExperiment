//
// Created by lorry on 12/26/18.
//

#include "Car.h"
#include "ParkingCar.h"

ParkingCar::ParkingCar(unsigned t): car { Car() }, time { t } { }

ParkingCar::ParkingCar(const ParkingCar & rhs):
    car { Car(rhs.getCarId()) }, time { rhs.getParkingTime() } { }

const string& ParkingCar::getCarId() const { return car.getCarId(); }

const unsigned ParkingCar::getParkingTime() const { return time; }
