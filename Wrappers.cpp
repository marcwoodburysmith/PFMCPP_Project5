#include "Wrappers.h"
#include "CoffeeMaker.h"
#include "Dentist.h"
#include "ATM.h"
#include "Cafeteria.h"
#include "DentalHospital.h"

CoffeeMakerWrapper::CoffeeMakerWrapper(CoffeeMaker* ptr) : ptrToCoffeeMaker(ptr) { }
  
CoffeeMakerWrapper::~CoffeeMakerWrapper()
{
    delete ptrToCoffeeMaker;
}

DentistWrapper::DentistWrapper(Dentist* ptr) : ptrToDentist(ptr) { }

DentistWrapper::~DentistWrapper()
{
    delete ptrToDentist;
}


ATMWrapper::ATMWrapper(ATM* ptr) : ptrToATM(ptr) { }

ATMWrapper::~ATMWrapper()
{
    delete ptrToATM;
}


CafeteriaWrapper::CafeteriaWrapper(Cafeteria* ptr) : ptrToCafeteria(ptr) { }

CafeteriaWrapper::~CafeteriaWrapper()
{
    delete ptrToCafeteria;
}

   
DentalHospitalWrapper::DentalHospitalWrapper(DentalHospital* ptr) : ptrToDentalHospital(ptr) { }

DentalHospitalWrapper::~DentalHospitalWrapper()
{
    delete ptrToDentalHospital;
}
