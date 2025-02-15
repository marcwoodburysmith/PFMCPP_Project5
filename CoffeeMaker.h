#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct CoffeeMaker
{   
    CoffeeMaker();
    ~CoffeeMaker();
   
    float maxWaterTemp;
    bool switchedOn = false;
    bool milkRequested = false;
    std::string typeOfCoffee = "espresso";
    float waterRemaining = 500;

    struct Cup
    {
        Cup();
        ~Cup();
        

        float volume = 250;
        bool cupFull;
        float height = 12;
        std::string colour = "black";
        bool clean;

        void setCupVolume(float vol);
        bool getCleanStatus() const; 
        void setCupColour(std::string col);
        void printCupMemberInfo() const;

        void fillCup(const float& vol);
    };

    void heatWater();
    std::string getCoffeeType() const;
    void switchOff();
    float setTemperature(float waterTemp);
    void printCoffeeMakerMemberInfo() const;

    Cup customerCup;

    JUCE_LEAK_DETECTOR(CoffeeMaker)

};
