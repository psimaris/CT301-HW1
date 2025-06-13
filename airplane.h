#ifndef _AIR_PLANE_H
#define _AIR_PLANE_H

#include <string> 
#include "cabin.h"

enum class airlineName
{
  Taco_Airline, 
  Ram_Airline, 
  Cheap_Boulder_Airline, 
  Miami_Airline,
  Bielsa_Airline
};

class airplane {

public: 

   
   airplane(size_t id, airlineName aline, cabin cab); 


   size_t getCapacity();
   size_t getPlaneId();
   airlineName getCompanyName(){ return airline;};
   bool autoAssignedPassengersToCabin(std::vector<passenger> & pax, bool useCriteria=false);
   bool processAllPassengers(const size_t theMiles, const double money, std::shared_ptr<mapPassengers> & mPaxPtr);
   cabin getPlaneCabin(); 
   //for grading purposes 
    friend class ct301Tester;
private:

  size_t planeId;
  airlineName airline; 
  cabin planeCabin;  
  int capacity; 
  
  
 
};

#endif 


//197247