#include "Market.h"

Market::Market()
{
}

Market::~Market()
{
}

std::list<std::unique_ptr<Car>>& Market::getCarList()
{
    return carList;
}

void Market::sellCar(unsigned int carIdx)
{
    auto it = carList.begin();
    std::advance(it, carIdx);
    (*it)->setCarStatus(Car::Status::sold);
}

void Market::buyCar(std::unique_ptr<Car> car)
{
    carList.push_back(std::move(car));
}
