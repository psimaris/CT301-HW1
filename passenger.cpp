#include "passenger.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <ostream>

/// @brief  overload of << ostream operator
/// @param os  osstream (reference0)
/// @param obj actual class, in this case passenger reference
/// @return note that the return is the same ostream that was passed 
/// and this is why this works
std::ostream& operator<<(std::ostream& os, const passenger& obj) {
   

    os << "[Passenger = " << obj.name.getPassengerLastName() << ", "  
                           << obj.name.getPassengerLastName() << "; banned = "
                           << obj.banned << "; employee = " << obj.employee << "; moneySpent = "
                           << obj.moneySpent << "; miles = " << obj.miles << "]";
      
    return os;
}

/// @brief Constructor for passengerName
/// @param first std::string of first Name
/// @param last  std::string of last name 
passengerName::passengerName(std::string first, std::string last): 
                                        firstName(first), lastName(last)
{
   // object was constructed. 
}

/// @brief get first name
/// @return std::string (first name)
std::string passengerName::getPassengerFirstName() const
{
    return firstName;
}

/// @brief get last name
/// @return std::string (last name)
std::string passengerName::getPassengerLastName() const
{
    return lastName;
}
//while I prefer to have one class per file, I think for this HW is easier to keep both here. 

//Class passenger below

/// @brief constructor of passenger
/// @param paxName passengerName object (it is being passed as a copy), while a reference
///                would be better, I wanted you to see how you pass by value. 
///                depends what we do in hw3, we will have time to optimize. 
/// @param paxAge  unsigned short of passenger age. Note that modifying to const unsigned short paxAge would
///                have been better. However, I'm trying to give you different flavors. 
/// @param sp      enum seatTypePreference (can also pass by reference), and not they all should be passed 
///                by reference and const
/// @param fFlyer  enum frequentyFlyer
/// @param paxEmployee is passanger an employee? True/False?
/// @param paxBanned  is this passenger banned? 
passenger::passenger(passengerName paxName, unsigned short paxAge, seatTypePreference sp,
                     frequentFlyer fFlyer, bool paxEmployee,
                     bool paxBanned):
                       name(paxName), age(paxAge), seatPreference(sp), 
                       freqFlyer(fFlyer), employee(paxEmployee), banned(paxBanned),
                       miles(0L), moneySpent(0.0)
{

}



passengerName passenger::getPassengerName() const 
{
    return name;
}

void passenger::addMiles(const double m)
{
   
}

void passenger::removeMiles(const double m)
{
   
}

/// @brief display miles by using std:: floor, that way we display 934 and not 934.23
///        We rundown so we can give less to the customer :) 
/// @return size_t std::floor(miles)
size_t passenger::displayMiles()
{
    return std::floor(miles);
}

double passenger::getMiles()
{
    
} 

void passenger::setFrequentFlyer(const frequentFlyer ff)
{
     
}
frequentFlyer passenger::getFrequentFlyer()
{
    return freqFlyer;
}

seatTypePreference passenger::getSeatPreference()
{
    return seatPreference;
}

void passenger::setSeatTypePreference(const seatTypePreference p)
{
    
}

void passenger::setEmployee(const bool e)
{
    
}
void passenger::setBanned(bool b)
{
    
}

void passenger::setAge(const unsigned short a)
{
    
}
bool passenger::isEmployee()
{
    return employee;
} 
bool passenger::isBanned()
{
    return banned; 
}
unsigned short passenger::getAge()
{
    return age; 
}

// PASSENGERS CLASS ********

/// @brief in reality, a passangerIdentifier class would had been better, yet this is not what we did in this design
///        passengers is design to keep a database all passengers for each instance of Flights. 
/// @param m 
passengers::passengers(const mapPassengers & m): mapPax(m)
{
    // object was constructed. 
}

/// @brief return std::vector<passenger> -- how would you do this
/// @return std::vector<passenger>
std::vector<passenger> passengers::getPassengers() const
{
    std::vector<passenger> v;
    //what's missing here in the middle?
    return v;
}



std::optional<passenger> passengers::getPassengerByLastName(std::string & lastName)  
{
    if (findPassengerInMap(lastName))
    {
        auto ret = std::optional<passenger>(mapPax.at(lastName));
        return std::optional<passenger>(ret);
    }
    else 
    {
        return std::nullopt; // Passenger not found
    }
    
}




bool passengers::addPassenger(const passenger & pax)
{
    // Check if the passenger already exists
    // if it does, we will ignore the addition
    auto p = pax; 
    auto pName = p.getPassengerName();
    const auto lastName = pName.getPassengerLastName(); 
    if(!findPassengerInMap(lastName))
        return false; // Passenger already exists, do not add again


    mapPax.emplace(lastName, pax);
    return true; 
}


bool passengers::findPassengerInMap(const std::string & lastName)
{
     return false; // you need to implement it. 
}


bool passengers::updatePassenger(const passenger & pax)
{
    auto const pName = pax.getPassengerName();
    auto const lastName = pName.getPassengerLastName();
    try {
         //not, I get a reference so I can modify it
         auto & p = mapPax.at(lastName);
         mapPax.at(lastName) = pax; 
       } catch (const std::out_of_range& e) {
           std::cerr << "Error: Key not found." << std::endl;
           return false;
       }
    
    return true; 
    
}

bool passengers::updatePassengerData(const passenger & pax, const double moneySpent, const double miles)
{
    auto const pName = pax.getPassengerName();
    auto const lastName = pName.getPassengerLastName();
    

    try {
         auto & p = mapPax.at(lastName);
         //add moneySpent and miles to p -- how ? 
         mapPax.at(lastName) = p; 
       } catch (const std::out_of_range& e) {
           std::cerr << "Error: Key not found." << std::endl;
           return false; 
       }

   
    
    return true; 
    
}


bool passengers::removePassenger(const std::string & lastName)
{
    auto count = mapPax.erase(lastName);
    if (count == 0)
        return false;
    else 
        return true; 
}
