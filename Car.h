#pragma once
#include <string>
#include <chrono>
class Car
{
public:
	enum Status {
		available,
		sold
	};
private:
	const std::string carModel;
	const std::uint16_t carYearOfRegistration;
	double carPrice;
	Status carStatus;
	std::chrono::time_point<std::chrono::system_clock> timePoint;
	
public:	
	Car(std::string carModel, std::uint16_t carYearOfRegistration, double carPrice);
	~Car() = default;

	std::string getCarModel() const;
	std::uint16_t getCarYearOfRegistration() const;
	double getCarPrice() const;
	Status getCarStatus() const;

	void setCarPrice(double price);
	void setCarStatus(Status status);
};