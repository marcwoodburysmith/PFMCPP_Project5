#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct CoffeeMaker
{   
    CoffeeMaker() : maxWaterTemp(75) 
    { 
        std::cout << "CoffeeMaker constructor called" << std::endl;
    }

    ~CoffeeMaker()
    {
        std::cout << "CoffeeMaker destructor called" << std::endl;
    }

    float maxWaterTemp;
    bool switchedOn = false;
    bool milkRequested = false;
    std::string typeOfCoffee = "espresso";
    float waterRemaining = 500;

    struct Cup
    {
        Cup();
        ~Cup()
        {
            std::cout << "Cup destructor called" << std::endl;
        }

        float volume = 250;
        bool cupFull;
        float height = 12;
        std::string colour = "black";
        bool clean;

        void setCupVolume(float vol);
        bool getCleanStatus(); 
        void setCupColour(std::string col);
        void printCupMemberInfo();

        bool fillingCup(const float& vol);
    };

    void heatWater();
    std::string coffeeType();
    void switchOff();
    float settingTemperature(float waterTemp);
    void printCoffeeMakerMemberInfo();

    Cup customerCup;

    JUCE_LEAK_DETECTOR(CoffeeMaker)

};
