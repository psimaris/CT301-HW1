#include "baseSeatCabinContainer.h"
#include "seat.h"
#include <typeinfo>

baseSeatCabinContainer::baseSeatCabinContainer(
                            const vecVecSeatsPtr& v)
    : cabinVector(v)
{

}



//returns a copy of the vector of seats in the row.
vecSeatsPtr  baseSeatCabinContainer::getRowSeats(const int row)
{ 
    return  cabinVector[row];
}

//returns a copy of the letters for a given row. 
std::vector<seatLetter> baseSeatCabinContainer::getRowLetterAvailable(int row)
{
    std::vector<seatLetter> letterVector; 
    auto v = cabinVector[row];
    for (auto & s: v)
    {
        if (s == nullptr)
            continue; //skip this seat, it is not available. 
        
            
        letterVector.emplace_back(s->getLetter());
    }
    
    return letterVector;

}

cabinTypes baseSeatCabinContainer::getCabinType()
{

    const std::type_info& current = typeid(*this); 
    const std::string name = std::string(current.name()); 

    if (name == "firstSeatCabinContainer")
        return cabinTypes::first;
    else if (name == "businessSeatCabinContainer")
        return cabinTypes::business;
    else if (name == "premiunEconomySeatCabinContainer")
        return cabinTypes::premiumEconomy;
    else if (name == "economySeatCabinContainer")
        return cabinTypes::economy;
    else if (name == "basicEconomyCabinContainer")
        return cabinTypes::basicEconomy;
    else 
        return cabinTypes::unknown;

}

size_t baseSeatCabinContainer::getRowCount()
{
    return cabinVector.size(); 
}