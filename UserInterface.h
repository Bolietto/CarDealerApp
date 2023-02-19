#pragma once
#include <memory>
#include "Market.h"

class UserInterface
{
private:
	std::unique_ptr<Market> market;
public:
	UserInterface(std::unique_ptr<Market> market);
	~UserInterface() = default;

	void showOverview();
	void startMenu();
	void sellingMenu();
	void buyingMenu();
	

};

