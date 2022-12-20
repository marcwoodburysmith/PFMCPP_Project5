#pragma once

struct CoffeeMaker;
struct Dentist;
struct ATM;
struct Cafeteria;
struct DentalHospital;

struct CoffeeMakerWrapper
{
    CoffeeMakerWrapper(CoffeeMaker* ptr) : ptrToCoffeeMaker(ptr) { }
    ~CoffeeMakerWrapper()
    {
        delete ptrToCoffeeMaker;
    }

    CoffeeMaker* ptrToCoffeeMaker = nullptr;
};

struct DentistWrapper
{
    DentistWrapper(Dentist* ptr) : ptrToDentist(ptr) { }
    ~DentistWrapper()
    {
        delete ptrToDentist;
    }

    Dentist* ptrToDentist = nullptr;
};

struct ATMWrapper
{
    ATMWrapper(ATM* ptr) : ptrToATM(ptr) { }
    ~ATMWrapper()
    {
        delete ptrToATM;
    }

    ATM* ptrToATM = nullptr;
};

struct CafeteriaWrapper
{
    CafeteriaWrapper(Cafeteria* ptr) : ptrToCafeteria(ptr) { }
    ~CafeteriaWrapper()
    {
        delete ptrToCafeteria;
    }

    Cafeteria* ptrToCafeteria = nullptr;
};

struct DentalHospitalWrapper
{
    DentalHospitalWrapper(DentalHospital* ptr) : ptrToDentalHospital(ptr) { }
    ~DentalHospitalWrapper()
    {
        delete ptrToDentalHospital;
    }

    DentalHospital* ptrToDentalHospital = nullptr;
};
