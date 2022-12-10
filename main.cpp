/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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
        void printCupMemberInfo();

        bool fillingCup(float vol);
    };

    void heatWater();
    std::string coffeeType();
    void switchOff();
    float settingTemperature(float waterTemp);
    void printCoffeeMakerMemberInfo();

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
    float feeForService(std::string treatmentClassification);
    int payStaff(); 
    int costPerPatient(int num);
    void printDentistMemberInfo();

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
    double dispensingCash(double amountWithdrawn);
    void printATMInfo();
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
    
    
    std::cout << "Switched on status: " << coffeemaker.switchedOn << " Coffee type: " << coffeemaker.coffeeType() << std::endl;
    coffeemaker.printCoffeeMakerMemberInfo();

    CoffeeMaker::Cup cup;
    cup.setCupVolume(250);
    cup.getCleanStatus();
    cup.setCupColour("Green");
    cup.fillingCup(200);
    
   
    std::cout << "Cup volume " << cup.volume << " Clean status: " << cup.getCleanStatus() << std::endl;
    cup.printCupMemberInfo();

    Dentist dentist;
    dentist.returnLastCheck("Mary");
    dentist.feeForService("bridge work");
    dentist.payStaff();
    dentist.costPerPatient(4);
    
    
    std::cout << "Dentist name: " << dentist.dentistName << " Fee for service (other): " << dentist.feeForService("other") << std::endl;
    dentist.printDentistMemberInfo();

    Dentist::Person person;
    person.name = "Mary";
    person.getInsuranceCompany("Axis");
    person.dateOfNextDentalAppointment(112022);
    person.getGender();
    person.numberOfAppointments(24);
    
   
    std::cout << "Person's name: " << person.name << " Person's gender " << person.getGender() << std::endl;
    person.printPersonMemberInfo();
    
    ATM atm;
    atm.dispenseCash();
    atm.displayBalance(12345678);
    atm.dispenseReceipt(250);
    atm.dispensingCash(200);
    
    
    std::cout << "Max amount available: " << atm.maxAmountAvailable << " Number of customers: " << atm.numCustomers << std::endl;
    atm.printATMInfo();
    

    DentalHospital centervilleHospital;
    centervilleHospital.allocatePatientToDentist("Amanda");
    centervilleHospital.profitByDentist(16, 32);

    std::cout << "Dentist names: " << centervilleHospital.dentist1.dentistName << " " << centervilleHospital.dentist2.dentistName  << std::endl;
    centervilleHospital.printDentalHospitalInfo();


    Cafeteria centervilleCafe;
    centervilleCafe.serveCustomer("frothy", "blue");
    centervilleCafe.fillCoffeeMaker();

    std::cout << "On/off status " << centervilleCafe.coffeeMaker.switchedOn << " Cup 1 colour " << centervilleCafe.cup1.colour << std::endl;
    centervilleCafe.printCafeteriaInfo();
    
    std::cout << "good to go!" << std::endl;
}
