//
// Created by lorry on 12/26/18.
//

#include <string>

using std::string;

#ifndef ALGORITHM_CAR_H
#define ALGORITHM_CAR_H


class Car
{
public:
    Car();

    explicit Car(const string & id);

public:
    const string & getCarId() const;

private:
    static constexpr char id[36] = "123456789ABCDEFGHIZKLMNOPQRSTUVWXYZ";
    string carId;
};


#endif //ALGORITHM_CAR_H
