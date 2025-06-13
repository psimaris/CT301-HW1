
#ifndef _CABIN_H
#define _CABIN_H



#include <optional> 
#include <vector> 
#include <tuple> 
#include <memory> 
#include "passenger.h" 
#include "baseSeatCabinContainer.h"



class cabin
{
public:
    cabin(const vecVecSeatsPtr & cSeats); 
    using optTupleSeatPax = std::optional<std::tuple<passenger,iSeatPtr>>;
    size_t getCabinCapacity(); 
    size_t getCabinRows(); 
    size_t getCabinOpenSeats(); 
    bool clearAllPassengers(); 
    optTupleSeatPax findPassenger(const passenger & pax);
    iSeatPtr  getSeat(const unsigned int row, seatLetter letter);
    vecSeatsPtr getRow(const unsigned int row);
    bool autoAssignPassengers(std::vector<passenger> & vPax, bool useCriteria=false ); 
    bool processAllPassengers(const double miles, const double money, std::shared_ptr<mapPassengers> & mPaxPtr); 
    bool processAllPassengers(const std::vector<std::tuple<double,double>> & vData, std::shared_ptr<mapPassengers> & mPaxPtr); 
    //rule of five... really not need it but here so you can see it
    // Copy constructor -- just using default
    cabin(const cabin& other) = default;

    // Move constructor
    cabin(cabin&& other) noexcept = default;

    // Copy assignment operator
    cabin& operator=(const cabin& other) = default;

    // Move assignment operator
    cabin& operator=(cabin&& other) noexcept = default;

    // Destructor
    ~cabin() = default;

    friend class ct301Tester; 
private: 
   std::tuple<double, double> processPassengerValues(const double miles, const double money,  passenger & pax); 
   void autoAssignPassengersRandom(std::vector<passenger> & vPax); 
   void autoAssignPassengersCriteria(std::vector<passenger> & vPax);   
   vecVecSeatsPtr cabSeats; 
   size_t cabinCapacity; 
   size_t cabinRows; 
   
};




#endif 