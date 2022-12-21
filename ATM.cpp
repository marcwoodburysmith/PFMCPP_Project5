
#include "Wrappers.h"
#include "ATM.h"
#include <iostream>

ATM::ATM()
{
    currentAmountAvailable = 20000;
}

ATM::~ATM()
{
    std::cout << "ATM destructor called" << std::endl;
}

void ATM::dispenseCash()
{
    std::cout << "Dispensing cash... " << std::endl;
}

int ATM::displayBalance(int accountNum)
{
    accountNumCurrentCustomer = accountNum;
    std::cout << "Displaying balance for accout: " << accountNumCurrentCustomer << std::endl;
    return accountNumCurrentCustomer;
}

void ATM::dispenseReceipt(double amountWithdrawn)
{
    currentAmountAvailable -= amountWithdrawn;
    std::cout << "Dispensing receipt... " << std::endl;
    std::cout << "Current amount available " << currentAmountAvailable << std::endl;
}

double ATM::dispensingCash(const double& amountWithdrawn)
{
    double amountDispensed = 0;
    while (amountDispensed < amountWithdrawn)
    {
        amountDispensed += 10;
    }
    std::cout << "Dispensing requested amount" << std::endl;
    maxAmountAvailable -= amountDispensed;
    return maxAmountAvailable;
}


void ATM::printATMInfo()
{
    std::cout << "Max amount available: " << this->maxAmountAvailable << " Number of customers: " << this->numCustomers << std::endl;
}