/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */

#include <iostream>

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

        bool fillingCup(float vol);
    };

    void heatWater();
    std::string coffeeType();
    void switchOff();
    float settingTemperature(float waterTemp);

    Cup customerCup;

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

bool CoffeeMaker::Cup::fillingCup(float vol)
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
    };

    int returnLastCheck(std::string name);
    float feeForService(std::string treatmentClassification);
    int payStaff(); 
    int costPerPatient(int num);

    Person newPatient;
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


int Dentist::returnLastCheck(std::string name)
{
    newPatient.name = name;
    std::cout << "Determining last dental appt for: " << name << std::endl;
    return newPatient.dateOfLastCheck;
}

float Dentist::feeForService(std::string treatmentClassification)
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
    double dispensingCash(double amountWithdrawn);
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

double ATM::dispensingCash(double amountWithdrawn)
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

/*
 new UDT 4:
 with 2 member functions
 */

struct Cafeteria
{
    Cafeteria()
    {
        coffeeMaker.switchedOn = true;
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
    CoffeeMaker coffeemaker;
    coffeemaker.heatWater();
    coffeemaker.coffeeType();
    coffeemaker.switchedOn = true;
    coffeemaker.switchOff();
    coffeemaker.settingTemperature(60);

    CoffeeMaker::Cup cup;
    cup.setCupVolume(250);
    cup.getCleanStatus();
    cup.setCupColour("Green");
    cup.fillingCup(200);

    Dentist dentist;
    dentist.returnLastCheck("Mary");
    dentist.feeForService("bridge work");
    dentist.payStaff();
    dentist.costPerPatient(4);

    Dentist::Person person;
    person.name = "Mary";
    person.getInsuranceCompany("Axis");
    person.dateOfNextDentalAppointment(112022);
    person.getGender();
    person.numberOfAppointments(24);
    
    ATM atm;
    atm.dispenseCash();
    atm.displayBalance(12345678);
    atm.dispenseReceipt(250);
    atm.dispensingCash(200);

    DentalHospital centervilleHospital;
    centervilleHospital.allocatePatientToDentist("Amanda");
    centervilleHospital.profitByDentist(16, 32);


    Cafeteria centervilleCafe;
    centervilleCafe.serveCustomer("frothy", "blue");
    centervilleCafe.fillCoffeeMaker();
    
    std::cout << "good to go!" << std::endl;
}
