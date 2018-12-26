//
// Created by lorry on 12/26/18.
//

#include <iostream>
#include <random>

#include "../../include/myhead.h"
#include "ParkSystem.h"

using std::cin;
using std::cout;
using std::endl;
using std::uniform_int_distribution;

ParkSystem::ParkSystem(): continueYesNo { 'Y' }, choose { 0 }, maxCarNum { 0 }, charge { 0 }
{
    uniform_int_distribution<unsigned> uniform(0, 100);
    time = uniform(engine);
}

void ParkSystem::init()
{
    while (true)
    {
        system("clear");
        cout << "\t*******************停车场管理*******************" << endl << endl;
        cout << "\t\t1.模拟车辆调度" << endl;
        cout << "\t\t2.设置停车场可停车辆的最大数目" << endl;
        cout << "\t\t3.设置单位时间的收费量" << endl;
        cout << "\t\t4.随机生成停车场的车辆" << endl;
        cout << "\t\t\t其他.结束" << endl << endl;
        cout << "////////////////////////////////////////////////////////" << endl;
        displayMessage();
        cout << "////////////////////////////////////////////////////////" << endl << endl;

        cout << "\t请输入你要操作的代码（1-4）号码：";
        cin >> choose;

        if (choose > 0 && choose < 5)
        {
            system("clear");
            displayMessage();
        }

        switch (choose)
        {
            case 1:
                startParkSystem();
                break;
            case 2:
                exSetMaxCarNum();
                break;
            case 3:
                exSetCharge();
                break;
            case 4:
                randomParkingCar();
                break;
            default:
                return;
        }

        if (continueYesNo == 'N' || continueYesNo == 'n') break;
    }
}

void ParkSystem::startParkSystem()
{
    int c=0;

    while (true)
    {
        system("clear");
        cout << "\t*******************模拟车辆调度*******************" << endl << endl;

        cout << "\t\t请选择调度方式：（1.离开 2.进入 0.结束）";
        cin >> c;

        switch (c)
        {
            case 0:
                return;
            case 1:
                outCar();
                break;
            case 2:
                inCar();
                break;
            default:
                return;
        }

        cout << "\t\t还要继续模拟停车场调度吗（Y.继续 N.结束）？";
        cin >> continueYesNo;

        if (continueYesNo == 'n' || continueYesNo == 'N')
            break;
    }
}

void ParkSystem::exSetMaxCarNum()
{
    unsigned n;
    cout << "\t*******************设置停车场可停车辆的最大数目*******************" << endl << endl;

    cout << "\t\t请输入最多可容纳的车辆数：";
    cin >> n;
    setMaxCarNum(n);
    cout << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ParkSystem::exSetCharge()
{
    unsigned c;
    cout << "\t*******************设置单位时间的收费量*******************" << endl << endl;

    cout << "\t\t请输入停车场单位时间的收费：";
    cin >> c;

    setCharge(c);
    cout << endl << "\t\t已经设置停车场单位时间的收费为：" << charge << endl << endl;

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ParkSystem::randomParkingCar()
{
    carQueue.clear();
    uniform_int_distribution<unsigned> nForm(0, 5);
    uniform_int_distribution<unsigned> tForm(1, 10);

    unsigned allCarNum = maxCarNum + nForm(engine);
    for(int i=0; i < allCarNum; ++i)
    {
        time = time+tForm(engine);
        ParkingCar parkingCar = ParkingCar(time);
        carQueue.push(parkingCar);
    }

    cout << "\t*******************随机生成停车场的车辆*******************" << endl << endl;

    displayMessage();

    cout << "\t**********************************************" << endl << endl;

    cout << "\t\t还继续吗（Y.继续 N.结束）？";
    cin >> continueYesNo;
}

void ParkSystem::displayMessage() const
{
    if (carQueue.empty())
        cout << endl << "\t\t停车场无任何车！" << endl << endl;
    else
        displayCurrentObject();
}

void ParkSystem::setMaxCarNum(unsigned m) { this->maxCarNum = m; }

void ParkSystem::setCharge(unsigned c) { this->charge = c; }

void ParkSystem::displayCurrentObject() const
{
    int i = 0;
    CarQueue::const_iterator itr = carQueue.begin();

    cout << "\t\t\t进入停车场内停车信息" << endl << endl << "\t\t\t车牌号\t\t进入的时间" << endl;
    for(; i<maxCarNum && i<carQueue.size(); ++i, ++itr)
    {
        cout << "\t\t[" << i << "]" << (*itr).getCarId() << "\t\t" << (*itr).getParkingTime() << endl;
    }

    cout << endl << "\t\t\t停车场外候车信息" << endl << endl;
    for(; i<carQueue.size(); ++i, ++itr)
    {
        cout << "\t\t\t\t" << (*itr).getCarId() << endl;
    }
    cout << endl;
}

void ParkSystem::outCar()
{
    if(carQueue.empty())
    {
        cout << "\t\t停车场内没有车！" << endl << endl;
        return;
    }
    unsigned i;
    uniform_int_distribution<unsigned> nForm(0, maxCarNum);
    unsigned outNum = nForm(engine);
    typename CarQueue::const_iterator itr = carQueue.begin();

    cout << "\t\t停放在停车场" << outNum << "号位的车辆准备离开。" << endl << endl;

    cout << "\t\t下列车牌号的车辆先退出让路：" << endl;
    for(i=1; i<outNum; ++i, ++itr);

    ParkingCar car = *itr;

    carQueue.erase(itr++);

    for(; i<maxCarNum; ++i, ++itr) cout << "\t\t\t\t" << (*itr).getCarId() << endl;

    cout << "\t\t停放在停车场" << outNum << "号位的车牌为" << car.getCarId()  << "的车辆离开。" <<
        endl << "\t\t停车时间为：" << time-car.getParkingTime() <<
        "\t\t应缴纳停车费为：" << charge*(time-car.getParkingTime()) << endl;

    cout << "\t\t先前退出的车辆再进入停车场。" << endl;
    if (carQueue.size()>maxCarNum)
        cout << "\t\t场外车牌为" << (*++itr).getCarId() << "的车辆现在入场。" << endl;

    cout << "\t\t此次调度后，停车场内外信息为：" << endl;
    displayMessage();
}

void ParkSystem::inCar()
{
    uniform_int_distribution<unsigned> tForm(1, 10);
    time += tForm(engine);
    auto *parkingCar = new ParkingCar(time);

    cout << "\t\t车牌为" << parkingCar->getCarId() << "的车辆准备进入停车场" << endl <<
            "\t\t此次调度后，停车场内外信息为：" << endl;

    if (carQueue.size() >= maxCarNum)
    {
        displayMessage();
        cout << "\t\t\t\t\t↑" << endl <<
            "\t\t\t\t" << parkingCar->getCarId() << endl;
        carQueue.push(*parkingCar);
    }
    else
    {
        carQueue.push(*parkingCar);
        displayMessage();
    }
}
