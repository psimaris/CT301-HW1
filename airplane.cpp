
#include "airplane.h"



airplane::airplane(size_t id, airlineName aline, cabin cab):
                   planeId(id), airline(aline),
                   planeCabin(cab)
{

}

cabin airplane::getPlaneCabin() { return planeCabin;} 

size_t airplane::getCapacity()
{
    return 0;
}

size_t airplane::getPlaneId()
{
    return planeId; 
}

bool airplane::autoAssignedPassengersToCabin(std::vector<passenger> & vPax, bool useCriteria)
{
    planeCabin.autoAssignPassengers(vPax,useCriteria);
    
    return true;
}

bool airplane::processAllPassengers(const size_t theMiles, const double money, std::shared_ptr<mapPassengers> & mPaxPtr)
{
    return planeCabin.processAllPassengers(theMiles,money, mPaxPtr);
}