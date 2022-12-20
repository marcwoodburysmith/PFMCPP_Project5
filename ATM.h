#pragma once 

#include "LeakedObjectDetector.h"
#include <iostream>

struct ATM
{
    ATM();
    ~ATM()
    {
        std::cout << "ATM destructor called" << std::endl;
    }
    double currentAmountAvailable;
    double maxAmountAvailable = 40000;
    int numCustomers = 200;
    int accountNumCurrentCustomer = 12345678;
    int pinNumCurrentCustomer = 1234;

    void dispenseCash();
    int displayBalance(int accountNum); 
    void dispenseReceipt(double amountWithdrawn);
    double dispensingCash(const double& amountWithdrawn);
    void printATMInfo();

    JUCE_LEAK_DETECTOR(ATM)
};
