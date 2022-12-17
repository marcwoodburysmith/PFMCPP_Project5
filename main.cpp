/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */




/*
 copied UDT 1:
 */

#include <iostream>
#include "LeakedObjectDetector.h"

struct CoffeeMaker
{   
    CoffeeMaker() : maxWaterTemp(75) 
    { 
        std::cout << "CoffeeMaker constructor called" << std::endl;
    }

    ~CoffeeMaker()
    {
        std::cout << "CoffeeMaker destructor called" << std::endl;
    }

    float maxWaterTemp;
    bool switchedOn = false;
    bool milkRequested = false;
    std::string typeOfCoffee = "espresso";
    float waterRemaining = 500;

    struct Cup
    {
        Cup();
        ~Cup()
        {
            std::cout << "Cup destructor called" << std::endl;
        }

        float volume = 250;
        bool cupFull;
        float height = 12;
        std::string colour = "black";
        bool clean;

        void setCupVolume(float vol);
        bool getCleanStatus(); 
        void setCupColour(std::string col);
        void printCupMemberInfo();

        bool fillingCup(const float& vol);
    };

    void heatWater();
    std::string coffeeType();
    void switchOff();
    float settingTemperature(float waterTemp);
    void printCoffeeMakerMemberInfo();

    Cup customerCup;

    JUCE_LEAK_DETECTOR(CoffeeMaker)

};


CoffeeMaker::Cup::Cup()
{
    std::cout << "Cup being constructed!" << std::endl;
    clean = true;
    cupFull = false;
}

void CoffeeMaker::Cup::setCupVolume(float vol)
{
    volume = vol;
    std::cout << "Cup volume set: " << volume << std::endl;
}

bool CoffeeMaker::Cup::getCleanStatus()
{
    std::cout << "Clean status: " << clean << std::endl;
    return clean;  
}

void CoffeeMaker::Cup::setCupColour(std::string col)
{
    colour = col;
    std::cout << "Colour set as: " << colour << std::endl;
}

bool CoffeeMaker::Cup::fillingCup(const float& vol)
{
    float level = 0;
    while(level < vol)
    {
        std::cout << "Filling at level: " << level << std::endl;
        level += 50;
    }
    cupFull = true;
    std::cout << "Cup full" << std::endl;
    return cupFull;
}

void CoffeeMaker::Cup::printCupMemberInfo()
{
    std::cout << "Cup volume: " << this->volume << " Clean status: " << this->getCleanStatus() << std::endl;
}

void CoffeeMaker::heatWater()
{
    switchedOn = true;
    std::cout << "Water heating..." << switchedOn << " Up to temp: " << maxWaterTemp << std::endl;
}

std::string CoffeeMaker::coffeeType()
{
    std::cout << "Type of coffee: " << typeOfCoffee << std::endl;
    return typeOfCoffee;
}

void CoffeeMaker::switchOff()
{
    std::cout << "Power: " << switchedOn << std::endl;
}

float CoffeeMaker::settingTemperature(float waterTemp)
{
    float currentTemp = 0;
    maxWaterTemp = waterTemp;
    while (currentTemp < maxWaterTemp)
    {
        currentTemp += 10;
    }
    std::cout << "Temperature reached" << std::endl;
    return maxWaterTemp;
}

void CoffeeMaker::printCoffeeMakerMemberInfo()
{
    std::cout << "Switched on status: " << this->switchedOn << " Coffee type: " << this->coffeeType() << std::endl;
}

/*
 copied UDT 2:
 */

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


Dentist::Person::Person()
{
    name = "Mary ";
    age = 35;
    gender = "female";
}

std::string Dentist::Person::getInsuranceCompany(std::string insurance)
{
    insuranceCompany = insurance;
    std::cout <<  name << ": Insurance Company: " << insuranceCompany << std::endl;
    return insuranceCompany;
}

int Dentist::Person::dateOfNextDentalAppointment(int lastCheck)
{
    dateOfLastCheck = lastCheck;
    std::cout << name << ": Next routine appointment due " << lastCheck + 1 << std::endl;
    return dateOfLastCheck + 1;
}

std::string Dentist::Person::getGender()
{
    std::cout << name << ": Gender: " << gender << std::endl;
    return gender;
}

void Dentist::Person::numberOfAppointments(int howOld)
{
    age = howOld;
    int appts = 0;
    for(int i = 0; i <= howOld; ++i)
    {
        appts += 1;   
    }
    std::cout << "Number of appointments: " << appts << std::endl;   
}

void Dentist::Person::printPersonMemberInfo()
{
    std::cout << "Person's name " << this->name << " Person's gender: " << this->getGender() << std::endl;
}


int Dentist::returnLastCheck(std::string name)
{
    newPatient.name = name;
    std::cout << "Determining last dental appt for: " << name << std::endl;
    return newPatient.dateOfLastCheck;
}

float Dentist::feeForService(const std::string& treatmentClassification)
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

int Dentist::costPerPatient(int num)
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
    std::cout << "Dentist name: " << this->dentistName << " Fee for service (other): " << this->feeForService("other") << std::endl;
}

/*
 copied UDT 3:
 */

struct ATM
{
    ATM();
    ~ATM()
    {
        std::cout << "ATM destructor called" << std::endl;
    }
    double currentAmountAvailable;
    double maxAmountAvailable = 40000;
    int numCustomers = 200;
    int accountNumCurrentCustomer = 12345678;
    int pinNumCurrentCustomer = 1234;

    void dispenseCash();
    int displayBalance(int accountNum); 
    void dispenseReceipt(double amountWithdrawn);
    double dispensingCash(const double& amountWithdrawn);
    void printATMInfo();

    JUCE_LEAK_DETECTOR(ATM)
};


ATM::ATM()
{
    currentAmountAvailable = 20000;
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

/*
 new UDT 4:
 with 2 member functions
 */

struct Cafeteria
{
    Cafeteria()
    {
        coffeeMaker.switchedOn = true;
        cup1.colour = "blue";
        std::cout << "Cafeteria constructor called" << std::endl;
    }
    ~Cafeteria() 
    { 
        coffeeMaker.switchedOn = false;
        std::cout << "Cafeteria destructor called" << std::endl;
    } 

    CoffeeMaker coffeeMaker;
    CoffeeMaker::Cup cup1, cup2, cup3, cup4;

    void serveCustomer(std::string type, std::string col);
    float fillCoffeeMaker(); 
    void printCafeteriaInfo();

    JUCE_LEAK_DETECTOR(Cafeteria)
};


void Cafeteria::serveCustomer(std::string type, std::string col)
{
    cup1.colour = col;
    coffeeMaker.typeOfCoffee = type;
    std::cout << "Customer will receive " << coffeeMaker.typeOfCoffee << " in a " << cup1.colour  << " cup" << std::endl;
}

float Cafeteria::fillCoffeeMaker()
{
    if(coffeeMaker.waterRemaining < 250)
    {
        std::cout << "Filling reservoir " << std::endl;
        coffeeMaker.waterRemaining = 1000;
        return coffeeMaker.waterRemaining;
    }
    
    std::cout << "Reservoir does not need filling " << std::endl;
    return coffeeMaker.waterRemaining;    
}

void Cafeteria::printCafeteriaInfo()
{ 
    std::cout << "On/off status " << this->coffeeMaker.switchedOn << std::endl;
    std::cout << "Cup 1 colour " << this->cup1.colour << std::endl;
    //std::cout << "Serve customer " << this->serveCustomer("latte", "blue") << std::endl;
}


/*
 new UDT 5:
 with 2 member functions
 */
struct DentalHospital
{
    DentalHospital()
    {
        dentist1.dentistName = "Mike";
        dentist2.dentistName = "Vanessa";
    }

    ~DentalHospital() 
    {
        std::cout << "Dentist closed" << std::endl;
    }

    Dentist dentist1, dentist2;
    Dentist::Person patient1, patient2, patient3, patient4;

    void allocatePatientToDentist(std::string nme); 
    void profitByDentist(int numPatients1, int numPatients2);
    void printDentalHospitalInfo();

    JUCE_LEAK_DETECTOR(DentalHospital)
    
};


void DentalHospital::allocatePatientToDentist(std::string nme)
{
    patient1.name = nme;
    //dentist1.dentistName = "Mike";
    std::cout << "Hello " << patient1.name << ". Your dentist is called: " << dentist1.dentistName << std::endl;
}

void DentalHospital::profitByDentist(int numPatients1, int numPatients2)
{
    dentist1.patientsPerWeek = numPatients1;
    dentist2.patientsPerWeek = numPatients2;
    int dentist1Profit = ((dentist1.patientsPerWeek * dentist1.chargePerPatient) - dentist1.costDisposableEquipment);
    std::cout << "Dentist 1 profit: " << dentist1Profit << std::endl;
    int dentist2Profit = ((dentist2.patientsPerWeek * dentist2.chargePerPatient) - dentist2.costDisposableEquipment);
    std::cout << "Dentist 2 profit: " << dentist2Profit << std::endl;
}

void DentalHospital::printDentalHospitalInfo()
{
    std::cout << "Dentist names: " << this->dentist1.dentistName << " " << this->dentist2.dentistName << std::endl;
}

//Wrappers

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



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
   
    CoffeeMakerWrapper coffeeMakerWrapper(new CoffeeMaker() );
    coffeeMakerWrapper.ptrToCoffeeMaker->heatWater();
    coffeeMakerWrapper.ptrToCoffeeMaker->coffeeType();
    coffeeMakerWrapper.ptrToCoffeeMaker->switchedOn = true;
    coffeeMakerWrapper.ptrToCoffeeMaker->switchOff();
    coffeeMakerWrapper.ptrToCoffeeMaker->settingTemperature(60);

    std::cout << "Switched on status: " << coffeeMakerWrapper.ptrToCoffeeMaker->switchedOn << " Coffee type: " <<    coffeeMakerWrapper.ptrToCoffeeMaker->coffeeType() << std::endl;
    coffeeMakerWrapper.ptrToCoffeeMaker->printCoffeeMakerMemberInfo();

    CoffeeMaker::Cup cup;
    cup.setCupVolume(250);
    cup.getCleanStatus();
    cup.setCupColour("Green");
    cup.fillingCup(200);
    
   
    std::cout << "Cup volume " << cup.volume << " Clean status: " << cup.getCleanStatus() << std::endl;
    cup.printCupMemberInfo();

    DentistWrapper dentistWrapper(new Dentist() );
    dentistWrapper.ptrToDentist->returnLastCheck("Mary");
    dentistWrapper.ptrToDentist->feeForService("bridge work");
    dentistWrapper.ptrToDentist->payStaff();
    dentistWrapper.ptrToDentist->costPerPatient(4);
    
    
    std::cout << "Dentist name: " << dentistWrapper.ptrToDentist->dentistName << " Fee for service (other): " << dentistWrapper.ptrToDentist->feeForService("other") << std::endl;
    dentistWrapper.ptrToDentist->printDentistMemberInfo();

    Dentist::Person person;
    person.name = "Mary";
    person.getInsuranceCompany("Axis");
    person.dateOfNextDentalAppointment(112022);
    person.getGender();
    person.numberOfAppointments(24);
    
   
    std::cout << "Person's name: " << person.name << " Person's gender " << person.getGender() << std::endl;
    person.printPersonMemberInfo();
    

    ATMWrapper atmWrapper(new ATM() );
    atmWrapper.ptrToATM->dispenseCash();
    atmWrapper.ptrToATM->displayBalance(12345678);
    atmWrapper.ptrToATM->dispenseReceipt(250);
    atmWrapper.ptrToATM->dispensingCash(200);
    
    
    std::cout << "Max amount available: " << atmWrapper.ptrToATM->maxAmountAvailable << " Number of customers: " << atmWrapper.ptrToATM->numCustomers << std::endl;
    atmWrapper.ptrToATM->printATMInfo();
    

    DentalHospitalWrapper dentalHospitalWrapper(new DentalHospital() );
    dentalHospitalWrapper.ptrToDentalHospital->allocatePatientToDentist("Amanda");
    dentalHospitalWrapper.ptrToDentalHospital->profitByDentist(16, 32);

    std::cout << "Dentist names: " << dentalHospitalWrapper.ptrToDentalHospital->dentist1.dentistName << " " << dentalHospitalWrapper.ptrToDentalHospital->dentist2.dentistName  << std::endl;
    dentalHospitalWrapper.ptrToDentalHospital->printDentalHospitalInfo();
    

    CafeteriaWrapper cafeteriaWrapper(new Cafeteria() );
    cafeteriaWrapper.ptrToCafeteria->serveCustomer("frothy", "blue");
    cafeteriaWrapper.ptrToCafeteria->fillCoffeeMaker();

    std::cout << "On/off status " << cafeteriaWrapper.ptrToCafeteria->coffeeMaker.switchedOn << " Cup 1 colour " << cafeteriaWrapper.ptrToCafeteria->cup1.colour << std::endl;
    cafeteriaWrapper.ptrToCafeteria->printCafeteriaInfo();
    
    std::cout << "good to go!" << std::endl;
}
