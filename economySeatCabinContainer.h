#ifndef _ECONOMY_SEAT_CABIN_CONTAINER_H
#define _ECONOMY_SEAT_CABIN_CONTAINER_H



#include <optional> 
#include <vector> 
#include <tuple> 
#include "passenger.h" 
#include "baseSeatCabinContainer.h"

class economySeatCabinContainer: public baseSeatCabinContainer
{
public:

  
    economySeatCabinContainer(const vecVecSeatsPtr &cSeats);
    
    
    void addRowSeats(const vecSeatsPtr& seats);
    

  

    //std::vector<seatLetter> getRowLetterAvailable(int row);
    //cabinTypes getCabinType(); 



};

#endif 