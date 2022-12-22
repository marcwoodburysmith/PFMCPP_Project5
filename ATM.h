#pragma once 

#include "LeakedObjectDetector.h"
#include <iostream>

struct ATM
{
    ATM();
    ~ATM();
    
    double currentAmountAvailable;
    double maxAmountAvailable = 40000;
    int numCustomers = 200;
    int accountNumCurrentCustomer = 12345678;
    int pinNumCurrentCustomer = 1234;

    void dispenseCash() const;
    int displayBalance(const int accountNum); 
    void dispenseReceipt(const double& amountWithdrawn);
    double dispensingCash(const double& amountWithdrawn);
    void printATMInfo() const;

    JUCE_LEAK_DETECTOR(ATM)
};
