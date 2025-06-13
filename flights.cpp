#include "flights.h"
#include <iostream>
#include <ostream> 
#include "haversine.h" 

//student version, incomplete. 
std::ostream& operator<<(std::ostream& os, const flights& obj) {
   
  
    
    os << "*****Printing passegers from flights object" << std::endl;
    for (const auto & pair : *obj.mapPax)
    {
        os << "[Key in Map  = " << pair.first << " ] " << pair.second << std::endl;
    }
      
    os << "*****Printing passegers from flights object completed!" << std::endl;
    return os;
}

flight::flight(const std::vector<airport> &route, 
                const airplane & plane, 
                bool rTrip, flightStatus status)
                   //initializing the members
                : flightRoute(route), flightPlane(plane),
                   status(status), roundTrip(rTrip)
{
    
}

airplane flight::getPlane() {return flightPlane;}

flight::flightStatus flight::getFlightStatus()
{
    return status; 
}
void flight::setFlighStatus(flightStatus fStatus)
{
  status = fStatus;
}

void flight::fly(std::shared_ptr<mapPassengers>& mPaxPtr)
{
  
    if (flightRoute.size() < 2)
    {
        std::cerr << "Flight cannot be flown, not enough airports in route." << std::endl;
        
        return;
    }

    
    double distance = 0.0; 
    for (int i =0; i< flightRoute.size(); i++)
    {
        auto a = flightRoute[i];
        auto j = i+1; 
        if (j < flightRoute.size())
        {
            auto a = flightRoute[i];
            auto b = flightRoute[j];
            distance = haversine::calculate(a.latitute, a.longitude, 
                                                   b.latitute, b.longitude);
            std::cout << "Flight from " << a.airportName << " to "
                      << b.airportName << " is " << distance << " km." << std::endl;
        }
    }
    if (roundTrip)
        distance *= 2; //round trip, so double the distance

    //note this is incomplete because you have to calculate the criteria I provided in cabin
    //so fix this part below 
    double moneySpent = (distance < 40) ? 250.00 : std::ceil(distance * 2); 
    flightPlane.processAllPassengers(distance, moneySpent, mPaxPtr);
    
}


// flights (CLASS)

flights::flights(const std::vector<flight> & vFlights, const mapPassengers & mPax):
                 vectorFlights(vFlights), mapPax(std::make_shared<mapPassengers>(mPax))
{

}

std::unique_ptr<std::vector<flight>> flights::flyAll()
{
    //make everyone fly!
    
    for (auto flight : vectorFlights)
    {
        flight.fly(this->mapPax);

    }
    //returns a copy for grading purposes. 
    return std::make_unique<std::vector<flight>>(vectorFlights);
}

