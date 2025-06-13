#include "seat.h"


seat::seat(seatLetter lt, bool o, std::optional<passenger> oPax):
         letter(lt), occupied(o), optPax(oPax)
{

}

bool seat::isOccupied()
{
    return occupied;
}

std::optional<passenger> seat::getPassenger()
{
    return optPax;
}

seatLetter seat::getLetter()
{
    return letter; 
} 



bool seat::removePassenger()
{
    if (!optPax.has_value())
        return false; 

    optPax = std::nullopt; 
    return true; 
}

bool seat::setPassenger(const std::optional<passenger> & pax)
{
    if (optPax.has_value())
        return false; 
    
    optPax = pax; 
    return true; 

}
std::optional<passenger> seat::replacePassenger(const std::optional<passenger> & pax)
{
    auto p = optPax;
    optPax = pax; 
    return p;  
}

bool seat::getEmergencySeat()
{
    return false; //not implemented in this class
}

void seat::setEmergencySeat(bool emergency)
{
    return; //not implemented in this class
} 