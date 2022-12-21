#pragma once

#include "LeakedObjectDetector.h"
#include <iostream>


struct DentalHospital
{
    DentalHospital();
    ~DentalHospital();

    Dentist dentist1, dentist2;
    Dentist::Person patient1, patient2, patient3, patient4;

    void allocatePatientToDentist(std::string nme); 
    void profitByDentist(int numPatients1, int numPatients2);
    void printDentalHospitalInfo();

    JUCE_LEAK_DETECTOR(DentalHospital)
    
};
