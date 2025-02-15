#pragma once 

#include "LeakedObjectDetector.h"
#include <iostream>

struct Dentist 
{
    Dentist();
    ~Dentist();
   
    std::string dentistName = "Mike";
    int patientsPerWeek = 40;
    int costDisposableEquipment = 200;
    int chargePerPatient = 800;
    int numStaff;

    struct Person
    {
        Person();
        ~Person();
       
        std::string name;
        int age;
        std::string gender;
        
        std::string insuranceCompany = "No Insurance";
        int dateOfLastCheck = 112022;

        std::string getInsuranceCompany(std::string insurance); 
        int getDateOfNextDentalAppointment(int lastCheck); 
        std::string getGender() const; 
        void getNumberOfAppointments(int howOld);
        void printPersonMemberInfo() const;
    };

    int returnLastCheck(std::string name);
    float getFeeForService(const std::string& treatmentClassification);
    int payStaff(); 
    int getCostPerPatient(int num);
    void printDentistMemberInfo();

    Person newPatient;

    JUCE_LEAK_DETECTOR(Dentist)
};
