#include <iostream>
#include "UserInterface.h"

int main()
{
    UserInterface UI(std::move(std::make_unique<Market>()));
    UI.startMenu();
    return 0;
}