
#include "Wrappers.h"
#include "Cafeteria.h"
#include <iostream>

void Cafeteria::serveCustomer(std::string type, std::string col)
{
    cup1.colour = col;
    coffeeMaker.typeOfCoffee = type;
    std::cout << "Customer will receive " << coffeeMaker.typeOfCoffee << " in a " << cup1.colour  << " cup" << std::endl;
}

float Cafeteria::fillCoffeeMaker()
{
    if(coffeeMaker.waterRemaining < 250)
    {
        std::cout << "Filling reservoir " << std::endl;
        coffeeMaker.waterRemaining = 1000;
        return coffeeMaker.waterRemaining;
    }
    
    std::cout << "Reservoir does not need filling " << std::endl;
    return coffeeMaker.waterRemaining;    
}

void Cafeteria::printCafeteriaInfo()
{ 
    std::cout << "On/off status " << this->coffeeMaker.switchedOn << std::endl;
    std::cout << "Cup 1 colour " << this->cup1.colour << std::endl;
    //std::cout << "Serve customer " << this->serveCustomer("latte", "blue") << std::endl;
}
