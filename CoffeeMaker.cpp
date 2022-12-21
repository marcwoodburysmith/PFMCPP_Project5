
#include "Wrappers.h"
#include "CoffeeMaker.h"
#include <iostream>

CoffeeMaker::CoffeeMaker() : maxWaterTemp(75) 
{ 
    std::cout << "CoffeeMaker constructor called" << std::endl;
}

CoffeeMaker::~CoffeeMaker()
{
    std::cout << "CoffeeMaker destructor called" << std::endl;
}

CoffeeMaker::Cup::Cup()
{
    std::cout << "Cup being constructed!" << std::endl;
    clean = true;
    cupFull = false;
}

CoffeeMaker::Cup:: ~Cup()
{
    std::cout << "Cup destructor called" << std::endl;
}

void CoffeeMaker::Cup::setCupVolume(float vol)
{
    volume = vol;
    std::cout << "Cup volume set: " << volume << std::endl;
}

bool CoffeeMaker::Cup::getCleanStatus()
{
    std::cout << "Clean status: " << clean << std::endl;
    return clean;  
}

void CoffeeMaker::Cup::setCupColour(std::string col)
{
    colour = col;
    std::cout << "Colour set as: " << colour << std::endl;
}

bool CoffeeMaker::Cup::fillingCup(const float& vol)
{
    float level = 0;
    while(level < vol)
    {
        std::cout << "Filling at level: " << level << std::endl;
        level += 50;
    }
    cupFull = true;
    std::cout << "Cup full" << std::endl;
    return cupFull;
}

void CoffeeMaker::Cup::printCupMemberInfo()
{
    std::cout << "Cup volume: " << this->volume << " Clean status: " << this->getCleanStatus() << std::endl;
}

void CoffeeMaker::heatWater()
{
    switchedOn = true;
    std::cout << "Water heating..." << switchedOn << " Up to temp: " << maxWaterTemp << std::endl;
}

std::string CoffeeMaker::coffeeType()
{
    std::cout << "Type of coffee: " << typeOfCoffee << std::endl;
    return typeOfCoffee;
}

void CoffeeMaker::switchOff()
{
    std::cout << "Power: " << switchedOn << std::endl;
}

float CoffeeMaker::settingTemperature(float waterTemp)
{
    float currentTemp = 0;
    maxWaterTemp = waterTemp;
    while (currentTemp < maxWaterTemp)
    {
        currentTemp += 10;
    }
    std::cout << "Temperature reached" << std::endl;
    return maxWaterTemp;
}

void CoffeeMaker::printCoffeeMakerMemberInfo()
{
    std::cout << "Switched on status: " << this->switchedOn << " Coffee type: " << this->coffeeType() << std::endl;
}
