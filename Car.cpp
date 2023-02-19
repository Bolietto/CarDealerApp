#include "Car.h"
#include <cmath>

Car::Car(std::string carModel, std::uint16_t carYearOfRegistration, double carPrice)
	: carModel(carModel), carYearOfRegistration(carYearOfRegistration), carPrice(carPrice), carStatus(Car::Status::available), timePoint(std::chrono::system_clock::now())
{
}

std::string Car::getCarModel() const
{
	return carModel;
}

std::uint16_t Car::getCarYearOfRegistration() const
{
	return carYearOfRegistration;
}

double Car::getCarPrice() const
{
	int timeDiff = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - timePoint).count();
	if (timeDiff >= 30)
	{
		return (carPrice * std::pow(0.99, ((timeDiff - 30) / 10) + 1)) > (carPrice * 0.8) ? (carPrice * std::pow(0.99, ((timeDiff - 30) / 10) + 1)) : (carPrice * 0.8);
	}
	return carPrice;
}

Car::Status Car::getCarStatus() const
{
	return carStatus;
}

void Car::setCarPrice(double price)
{
	carPrice = price;
}

void Car::setCarStatus(Status status)
{
	carStatus = status;
}
