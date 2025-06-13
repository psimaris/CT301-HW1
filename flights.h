#ifndef _FLIGHTS_H
#define _FLIGHTS_H
#include <string> 
#include <vector>
#include <map>
#include <memory>  
#include <iostream>
#include "airport.h"
#include "airplane.h"

class flight 
{
public: 
    enum class flightStatus
    {
        flown,
        cancelled, 
        idle
    };
    flight(const std::vector<airport> &route, const airplane & plane, 
                                      bool rTrip = false, 
                                      flightStatus fStatus = flightStatus::idle); 
        
    flightStatus getFlightStatus(); 
    void setFlighStatus(flightStatus fStatus);
    airplane getPlane(); 
    void fly(std::shared_ptr<mapPassengers> & mPaxPtr); 
    friend class ct301Tester;
   
private: 
    
    std::vector<airport> flightRoute;
    airplane flightPlane;
    bool roundTrip;
    flightStatus status; 

};

class flights
{
public:
    flights(const std::vector<flight> & vFlights, const mapPassengers & mPax);
    std::unique_ptr<std::vector<flight>> flyAll();
    void clearAllFlights() { /* clear all data from vectorFlights and from mapPax */}
    //for grading purposes only
    friend class ct301Tester;
    friend std::ostream& operator<<(std::ostream& os, const flights& obj);
private: 
    std::vector<flight> vectorFlights; 
    std::shared_ptr<mapPassengers> mapPax; 
};

std::ostream& operator<<(std::ostream& os, const flights& obj);

#endif 