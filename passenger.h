#ifndef _PAX_H
#define _PAX_H


#include <string> 
#include <map>
#include <memory> 
#include <vector> 
#include <optional> 

enum class frequentFlyer 
{
    InviteOnly, //highest one
    Gold, 
    Silver, 
    Bronze,
    Regular  //lowest one, doesn't get anything, just accumulate miles. 
};

enum class seatTypePreference
{
    window,
    middle, 
    aisle, 
};


class passengerName
{
public:
    passengerName(std::string first, std::string last);
    std::string getPassengerFirstName() const; 
    std::string getPassengerLastName() const; 
    //for grading purposes 
    friend class ct301Tester;
    
private:
    std::string firstName;
    std::string lastName; 
};

class passenger
{
public: 
    passenger(passengerName paxName, unsigned short paxAge, seatTypePreference sp,
             frequentFlyer fFlyer = frequentFlyer::Regular, bool paxEmployee = false,
             bool paxBanned = false);
    passengerName getPassengerName() const; 
    void addMiles(const double m);
    void removeMiles(const double m);
    double getMiles(); 
    size_t displayMiles(); 
    void setFrequentFlyer(const frequentFlyer ff); 
    frequentFlyer getFrequentFlyer(); 
    seatTypePreference getSeatPreference();
    void setSeatTypePreference(const seatTypePreference p); 
    void setEmployee(const bool e); 
    void setBanned(const bool b);
    void setAge(const unsigned short a); 
    void AddMoneySpent(const double money) { moneySpent += money;}
    double getMoneySpent() { return moneySpent;}
    bool isEmployee(); 
    bool isBanned(); 
    unsigned short getAge(); 


    friend std::ostream& operator<<(std::ostream& os, const passenger& obj);
    //for grading purposes 
    friend class ct301Tester;
    
  
private:
    
    passengerName name;
    unsigned short age;
    double miles; 
    double moneySpent; 
    frequentFlyer freqFlyer;
    seatTypePreference seatPreference; 
    bool banned; 
    bool employee;
};

std::ostream& operator<<(std::ostream& os, const passenger& obj);

using mapPassengers = std::map<std::string, passenger>;
class passengers
{
public:
    passengers(const mapPassengers & mPax);
    passengers() = default;
    bool updatePassenger(const passenger & pax);
    bool addPassenger(const passenger & pax);
    bool removePassenger(const std::string & lastName);

    std::optional<passenger> getPassengerByLastName(std::string & lastName);
    std::vector<passenger> getPassengers() const;  

    bool updatePassengerData(const passenger & pax, const double moneySpent, const double miles);

    bool findPassengerInMap(const std::string & lastName);

    //for grading purposes 
    friend class ct301Tester;
    
    
private: 
    mapPassengers mapPax; //key is last name
   
  
}; 


#endif 
