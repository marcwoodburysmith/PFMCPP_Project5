#pragma once

struct CoffeeMaker;
struct Dentist;
struct ATM;
struct Cafeteria;
struct DentalHospital;

struct CoffeeMakerWrapper
{
    CoffeeMakerWrapper(CoffeeMaker* ptr);
    ~CoffeeMakerWrapper();

    CoffeeMaker* ptrToCoffeeMaker = nullptr;
};

struct DentistWrapper
{
    DentistWrapper(Dentist* ptr);
    ~DentistWrapper();
    
    Dentist* ptrToDentist = nullptr;
};

struct ATMWrapper
{
    ATMWrapper(ATM* ptr);
    ~ATMWrapper();

    ATM* ptrToATM = nullptr;
};

struct CafeteriaWrapper
{
    CafeteriaWrapper(Cafeteria* ptr);
    ~CafeteriaWrapper();

    Cafeteria* ptrToCafeteria = nullptr;
};

struct DentalHospitalWrapper
{
    DentalHospitalWrapper(DentalHospital* ptr);
    ~DentalHospitalWrapper();
   
    DentalHospital* ptrToDentalHospital = nullptr;
};
