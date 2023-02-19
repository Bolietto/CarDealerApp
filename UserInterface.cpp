#include "UserInterface.h"
#include <stdlib.h>
#include <iostream>

UserInterface::UserInterface(std::unique_ptr<Market> market)
	: market(std::move(market))
{
}

void UserInterface::showOverview()
{
	system("CLS");
	std::cout << "All cars:\n";
	unsigned int idx = 1;
	for (auto& car : market->getCarList()) 
	{
		std::cout << "Id: " << idx << " | Car model: " << car->getCarModel() << " | First year registration: " << car->getCarYearOfRegistration() << " | Price: " << car->getCarPrice() << " | Status: ";
		if (car->getCarStatus() == Car::Status::available)
		{
			std::cout << "available";
		}
		else 
		{
			std::cout << "sold";
		}
		std::cout << std::endl;
		++idx;
	}
	std::cout << "Type any char and press enter to return to menu";
	char enter;
	std::cin >> enter;
	startMenu();
}

void UserInterface::startMenu()
{
	system("CLS");
	std::cout << "Application for an used car dealer\nMain menu\n";
	std::cout << "1. Sell a car\n2. Buy a car\n3. Stock overview\n4. Exit\n";
	unsigned int option;
	std::cin >> option;
	switch (option)
	{
	case 1:
		sellingMenu();
		break;
	case 2:
		buyingMenu();
		break;
	case 3:
		showOverview();
		break;
	case 4:
		break;
	default:
		break;
	}
}

void UserInterface::sellingMenu()
{
	system("CLS");
	std::cout << "All available cars:\n";
	unsigned int idx = 1;
	for (auto& car : market->getCarList())
	{		
		if (car->getCarStatus() == Car::Status::available)
		{
			std::cout << "Id: " << idx << " | Car model: " << car->getCarModel() << " | First year registration: " << car->getCarYearOfRegistration() << " | Price: " << car->getCarPrice();
			std::cout << std::endl;
		}		
		++idx;
	}
	std::cout << "Enter Car Id you want to sell or 0 to abort selling process\n";
	unsigned int option;
	std::cin >> option;
	if (option == 0)
	{
		startMenu();
	}
	else
	{
		--option;		
		market->sellCar(option);
		std::cout << "Congratulations! You sold a car!\n";
	}

	std::cout << "Type any char and press enter to return to menu";
	char enter;
	std::cin >> enter;
	startMenu();
}

void UserInterface::buyingMenu()
{
	system("CLS");
	std::string carModel;
	std::uint16_t carYearOfRegistration;
	double carPrice;
	std::cout << "Enter car data:\n";
	std::cout << "Enter car model:\n";
	std::cin >> carModel;
	std::cout << "Enter car's first year registration:\n";
	std::cin >> carYearOfRegistration;
	std::cout << "Enter car's price:\n";
	std::cin >> carPrice;
	auto car = std::make_unique<Car>(carModel, carYearOfRegistration, carPrice);
	market->buyCar(std::move(car));
	std::cout << "You bought a car with success!\n";
	std::cout << "Type any char and press enter to return to menu";
	char enter;
	std::cin >> enter;
	startMenu();
}
