#ifndef _FIRST_SEAT_CABIN_CONTAINER_H
#define _FIRST_SEAT_CABIN_CONTAINER_H


#include <optional> 
#include <vector> 
#include <tuple> 
#include "passenger.h" 
#include "baseSeatCabinContainer.h"


class firstSeatCabinContainer: public baseSeatCabinContainer
{
public:

    firstSeatCabinContainer(const vecVecSeatsPtr &cSeats);
  
   
   
    void addRowSeats(const vecSeatsPtr & seats);
 

};

#endif 