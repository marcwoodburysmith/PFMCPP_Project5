
#include "Wrappers.h"
#include "DentalHospital.h"
#include <iostream>

DentalHospital::DentalHospital()
{
    dentist1.dentistName = "Mike";
    dentist2.dentistName = "Vanessa";
}

DentalHospital::~DentalHospital() 
{
    std::cout << "Dentist closed" << std::endl;
}


void DentalHospital::allocatePatientToDentist(std::string nme)
{
    patient1.name = nme;
    //dentist1.dentistName = "Mike";
    std::cout << "Hello " << patient1.name << ". Your dentist is called: " << dentist1.dentistName << std::endl;
}

void DentalHospital::profitByDentist(const int& numPatients1, const int& numPatients2)
{
    dentist1.patientsPerWeek = numPatients1;
    dentist2.patientsPerWeek = numPatients2;
    int dentist1Profit = ((dentist1.patientsPerWeek * dentist1.chargePerPatient) - dentist1.costDisposableEquipment);
    std::cout << "Dentist 1 profit: " << dentist1Profit << std::endl;
    int dentist2Profit = ((dentist2.patientsPerWeek * dentist2.chargePerPatient) - dentist2.costDisposableEquipment);
    std::cout << "Dentist 2 profit: " << dentist2Profit << std::endl;
}

void DentalHospital::printDentalHospitalInfo() const
{
    std::cout << "Dentist names: " << this->dentist1.dentistName << " " << this->dentist2.dentistName << std::endl;
}

//Wrappers


