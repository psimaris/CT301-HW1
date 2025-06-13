#include "ct301Tester.h"
#include "flights.h"
void ct301Tester::inspectFlights(flights * allFlights)
{
  auto data = allFlights->vectorFlights;
  for (auto f : data)
  {
    inspectFlight(&f);
  }  
  //static class

}

void ct301Tester::inspectFlight(flight * f)
{
    auto data = f->flightPlane; 
}


