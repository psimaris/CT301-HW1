#include "economySeatCabinContainer.h"


economySeatCabinContainer::economySeatCabinContainer(
                            const vecVecSeatsPtr &cSeats)
                           :baseSeatCabinContainer(cSeats) 
{
   
}




void economySeatCabinContainer::addRowSeats(const vecSeatsPtr & seats) 
{
    cabinVector.push_back(seats);
}
