//
// Created by lorry on 12/26/18.
//

#include <random>

#include "../../include/myhead.h"
#include "Car.h"

using std::to_string;
using std::uniform_int_distribution;

const char Car::id[];

Car::Car()
{
    uniform_int_distribution<unsigned> uniform(0, 34);

    for(int i=0; i < 10; ++i)
    {
        carId+=id[uniform(engine)];
    }
}

Car::Car(const string & id): carId { id } { }

const string & Car::getCarId() const { return carId; }
