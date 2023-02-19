#pragma once
#include <list>
#include "Car.h"
#include <memory>

class Market
{
private:
	std::list<std::unique_ptr<Car>> carList;
public:
	Market();
	~Market();

	std::list<std::unique_ptr<Car>>& getCarList();

	void sellCar(unsigned int carIdx);
	void buyCar(std::unique_ptr<Car> car);
};

