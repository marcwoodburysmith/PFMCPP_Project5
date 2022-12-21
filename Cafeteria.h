#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>

struct Cafeteria
{
    Cafeteria();
    ~Cafeteria();
    
    CoffeeMaker coffeeMaker;
    CoffeeMaker::Cup cup1, cup2, cup3, cup4;

    void serveCustomer(std::string type, std::string col);
    float fillCoffeeMaker(); 
    void printCafeteriaInfo();

    JUCE_LEAK_DETECTOR(Cafeteria)
};
