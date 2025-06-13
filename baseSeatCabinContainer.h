#ifndef _BASE_SEAT_CABIN_CONTAINER_H
#define _BASE_SEAT_CABIN_CONTAINER_H



#include <optional> 
#include <vector> 
#include <tuple> 
#include <memory>
#include "passenger.h" 
#include "iSeat.h"

//forward declator so you see how it works
//but somewhat redundant with modules



class baseSeatCabinContainer
{
public:

    
    baseSeatCabinContainer(const vecVecSeatsPtr& v);
    
    virtual vecSeatsPtr
                 getRowSeats(const int row); 
    virtual std::vector<seatLetter> getRowLetterAvailable(int row) final;
    virtual size_t getRowCount() final; 
    virtual  cabinTypes getCabinType(); 
  
    virtual ~baseSeatCabinContainer() = default;
    
    //it creates a copy
    vecVecSeatsPtr getCabinVector()
    {
        return cabinVector; 
          
    }
   
protected: 
    vecVecSeatsPtr  cabinVector; 

};




#endif