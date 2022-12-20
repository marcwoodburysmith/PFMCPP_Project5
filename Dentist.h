#pragma once 

#include "LeakedObjectDetector.h"
#include <iostream>

struct Dentist 
{
    Dentist() : numStaff(5)  { }
    ~Dentist()
    {
        std::cout << "Dentist destructor called" << std::endl;
    }
    std::string dentistName = "Mike";
    int patientsPerWeek = 40;
    int costDisposableEquipment = 200;
    int chargePerPatient = 800;
    int numStaff;

    struct Person
    {
        Person();
        ~Person()
        {
            std::cout << "Person destructor called" << std::endl;
        }
        std::string name;
        int age;
        std::string gender;
        
        std::string insuranceCompany = "No Insurance";
        int dateOfLastCheck = 112022;

        std::string getInsuranceCompany(std::string insurance); 
        int dateOfNextDentalAppointment(int lastCheck); 
        std::string getGender(); 
        void numberOfAppointments(int howOld);
        void printPersonMemberInfo();
    };

    int returnLastCheck(std::string name);
    float feeForService(const std::string& treatmentClassification);
    int payStaff(); 
    int costPerPatient(int num);
    void printDentistMemberInfo();

    Person newPatient;

    JUCE_LEAK_DETECTOR(Dentist)
};
