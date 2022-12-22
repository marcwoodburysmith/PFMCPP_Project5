#pragma once

#include "LeakedObjectDetector.h"
#include "Dentist.h"
#include <iostream>


struct DentalHospital
{
    DentalHospital();
    ~DentalHospital();

    Dentist dentist1, dentist2;
    Dentist::Person patient1, patient2, patient3, patient4;

    void allocatePatientToDentist(std::string nme); 
    void returnProfitByDentist(const int& numPatients1, const int& numPatients2);
    void printDentalHospitalInfo() const;

    JUCE_LEAK_DETECTOR(DentalHospital)
    
};
