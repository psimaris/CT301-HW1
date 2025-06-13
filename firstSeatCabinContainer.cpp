#include "firstSeatCabinContainer.h"


firstSeatCabinContainer::firstSeatCabinContainer
            (const vecVecSeatsPtr &cSeats)
             : baseSeatCabinContainer(cSeats)
{
   
}




void firstSeatCabinContainer::addRowSeats(const vecSeatsPtr & seats) 
{
    cabinVector.push_back(seats);
}
