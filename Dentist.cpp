#include "Dentist.h"
#include <iostream>

Dentist::Dentist() : numStaff(5)  { }

Dentist::~Dentist()
{
    std::cout << "Dentist destructor called" << std::endl;
}

Dentist::Person::Person()
{
    name = "Mary ";
    age = 35;
    gender = "female";
}

Dentist::Person::~Person()
{
    std::cout << "Person destructor called" << std::endl;
}

std::string Dentist::Person::getInsuranceCompany(std::string insurance) 
{
    insuranceCompany = insurance;
    std::cout <<  name << ": Insurance Company: " << insuranceCompany << std::endl;
    return insuranceCompany;
}

int Dentist::Person::getDateOfNextDentalAppointment(int lastCheck)
{
    dateOfLastCheck = lastCheck;
    std::cout << name << ": Next routine appointment due " << lastCheck + 1 << std::endl;
    return dateOfLastCheck + 1;
}

std::string Dentist::Person::getGender() const
{
    std::cout << name << ": Gender: " << gender << std::endl;
    return gender;
}

void Dentist::Person::getNumberOfAppointments(int howOld)
{
    age = howOld;
    int appts = 0;
    for(int i = 0; i <= howOld; ++i)
    {
        appts += 1;   
    }
    std::cout << "Number of appointments: " << appts << std::endl;   
}

void Dentist::Person::printPersonMemberInfo() const
{
    std::cout << "Person's name " << this->name << " Person's gender: " << this->getGender() << std::endl;
}


int Dentist::returnLastCheck(std::string name)
{
    newPatient.name = name;
    std::cout << "Determining last dental appt for: " << name << std::endl;
    return newPatient.dateOfLastCheck;
}

float Dentist::getFeeForService(const std::string& treatmentClassification)
{
    if( treatmentClassification == "check up" )
    {
        std::cout << "Cost of work: £500" << std::endl;
        return 500;
    }
    std::cout << "Cost of work: £1000" << std::endl;
    return 1000;   
}

int Dentist::payStaff()
{
    int amountPerEmployee = ((patientsPerWeek * chargePerPatient) - costDisposableEquipment)/ numStaff;
    std::cout << "Employee salary: " << amountPerEmployee << std::endl;
    return ((patientsPerWeek * chargePerPatient) - costDisposableEquipment)/ numStaff; 
}

int Dentist::getCostPerPatient(int num)
{
    for(int i = 1; i <= num; i++)
    {
        std::cout << "Patient " << i << "cost " << chargePerPatient - costDisposableEquipment << std::endl;
    }
    int profitPerWeek = costDisposableEquipment * num * 4;
    return profitPerWeek;
}

void Dentist::printDentistMemberInfo()
{
    std::cout << "Dentist name: " << this->dentistName << " Fee for service (other): " << this->getFeeForService("other") << std::endl;
}
