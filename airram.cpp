//we will use include for HW1 and mostlyu imports for HW2 and beyond. 
#include <print>
#include <vector>
#include <map>
#include <string>
#include <iostream> 
#include <array> 
#include <memory>
#include <numeric>
#include <algorithm>
#include <random> 
#include <ranges> 
#include "readUtil.h"
#include "passenger.h"
#include "cabin.h"
#include "iSeat.h"
#include "seat.h"
#include "helper.h"
#include "airplane.h"
#include "flights.h"

#include "economySeatCabinContainer.h"
#include "firstSeatCabinContainer.h"

//main file. I will use my own to execute your program 
//We are making a simple toy airline passanger system 


//main function
//usage: airram ... int argc, char *array 



std::vector<flight> createFlights(const std::vector<passenger> & vecPax,
                  const std::map<std::string,airport> & mapAirportsInUSA,
                  const std::vector<airplane> & planes, size_t howManyPlanes)
{
    std::vector<passenger> vPax(vecPax); //creates a copy  
    std::vector<flight> vFlights;
    std::vector<std::string> vAirportsInUSA = 
            mapKeysToVector<std::string,std::string,airport>(mapAirportsInUSA);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vAirportsInUSA.begin(), vAirportsInUSA.end(), g);
    size_t wrap = vAirportsInUSA.size(); 
    for (size_t i =0, j=0; i<howManyPlanes; i++)
    {
        std::vector<airport> vAirportRoutes; 
        auto k1 = vAirportsInUSA[j%wrap];
        auto p1 = mapAirportsInUSA.at(k1); //because it is read only
        j++;
        auto k2 = vAirportsInUSA[j%wrap];
        auto p2 = mapAirportsInUSA.at(k2); //you should always check with contains
        airport aport1(p1);
        airport aport2(p2);
        vAirportRoutes.emplace_back(p1);
        vAirportRoutes.emplace_back(p2);
        
        auto myplane = planes[i];
        myplane.autoAssignedPassengersToCabin(vPax);
        flight f(vAirportRoutes,myplane,true);
        
        vFlights.emplace_back(f); 
    }
    return vFlights;
}

size_t createPlanes(std::vector<airplane> & planes,
                 const std::vector<cabin> & cabins)
{
    size_t howMany = 10000; 
    for (size_t i = 0; i< howMany; i++ )
    {
        airlineName air = (i % 5 == 0) ? airlineName::Bielsa_Airline :
                          (i % 5 == 1) ? airlineName::Cheap_Boulder_Airline:
                          (i % 5 == 2) ? airlineName::Taco_Airline :
                          (i % 5 == 3) ? airlineName::Ram_Airline :
                                         airlineName::Taco_Airline; 
        cabin c = (i % 2 == 0) ? cabins[0] :cabins[1]; 
        airplane p(i,air,c);
        planes.emplace_back(p);
    }

    return howMany; 
}

void createCabins(std::vector<cabin> & cabins)
{
    //cabin 1
    vecVecSeatsPtr vectorCabinSeats1; 
    for (int i = 1; i < 11; i++)
    {
        //iSeatPtr s; 
        vecSeatsPtr v;
        seat s1(seatLetter::A,false); 
        seat s2(seatLetter::B,false);
        seat s3(seatLetter::D,false);
        seat s4(seatLetter::E,false);
        v.emplace_back(std::make_shared<seat>(s1));
        v.emplace_back(std::make_shared<seat>(s2));
        v.emplace_back(std::make_shared<seat>(s3));
        v.emplace_back(std::make_shared<seat>(s4));  
        vectorCabinSeats1.push_back(v); 
        //vectorCabinSeats1.emplace_back(std::move(v)); 
        //vectorCabinSeats1.emplace_back(std::make_shared<iSeat>(v));       
    }
    firstSeatCabinContainer f1(vectorCabinSeats1);

    vecVecSeatsPtr vectorCabinSeats2;  
    for (int i = 11; i < 61; i++)
    {
        vecSeatsPtr v;
        seat s1(seatLetter::A,false); 
        seat s2(seatLetter::B,false);
        seat s3(seatLetter::C,false);
        seat s4(seatLetter::D,false);
        seat s5(seatLetter::E,false);
        seat s6(seatLetter::F,false);
        v.emplace_back(std::make_shared<seat>(s1));
        v.emplace_back(std::make_shared<seat>(s2));
        v.emplace_back(std::make_shared<seat>(s3));
        v.emplace_back(std::make_shared<seat>(s4)); 
        v.emplace_back(std::make_shared<seat>(s5));
        v.emplace_back(std::make_shared<seat>(s6)); 
        vectorCabinSeats2.push_back(v);           
    }

    economySeatCabinContainer e1(vectorCabinSeats2);
    std::vector<baseSeatCabinContainer> combinedCabins; 
    //combinedCabins.push_back(f1);
    //combinedCabins.push_back(e1);
 
    auto vf1 = f1.getCabinVector();
    auto ve1 = e1.getCabinVector(); 
    auto vectorAppended = vf1 + ve1; 
    cabin c1(vectorAppended);

    cabins.emplace_back(c1);
    
    //cabin 3
    vecVecSeatsPtr vectorCabinSeats3; 
    for (int i = 1; i < 9; i++)
    {
        vecSeatsPtr v;
        seat s1(seatLetter::A,false); 
        seat s2(seatLetter::B,false);
        seat s3(seatLetter::D,false);
        seat s4(seatLetter::E,false);
        v.emplace_back(std::make_shared<seat>(s1));
        v.emplace_back(std::make_shared<seat>(s2));
        v.emplace_back(std::make_shared<seat>(s3));
        v.emplace_back(std::make_shared<seat>(s4));  
        vectorCabinSeats3.push_back(v);     
    }
    firstSeatCabinContainer f2(vectorCabinSeats3);

    vecVecSeatsPtr vectorCabinSeats4;  
    for (int i = 11; i < 61; i++)
    {
        vecSeatsPtr v;
        seat s1(seatLetter::A,false); 
        seat s2(seatLetter::B,false);
       
        seat s5(seatLetter::E,false);
        seat s6(seatLetter::F,false);
        v.emplace_back(std::make_shared<seat>(s1));
        v.emplace_back(std::make_shared<seat>(s2));

        //this cabin has two seats removed 
        if (i != 23) 
        {
            seat s3(seatLetter::C,false);
            seat s4(seatLetter::D,false);
            v.emplace_back(std::make_shared<seat>(s3));
            v.emplace_back(std::make_shared<seat>(s4)); 
        }
        
        v.emplace_back(std::make_shared<seat>(s5));
        v.emplace_back(std::make_shared<seat>(s6)); 
        vectorCabinSeats4.push_back(v);           
    }

    economySeatCabinContainer e2(vectorCabinSeats4);
   // std::vector<baseSeatCabinContainer> combinedCabins2; 
    //combinedCabins2.push_back(f2);
    //combinedCabins2.push_back(e2);
 
    auto vf2 = f2.getCabinVector();
    auto ve2 = e2.getCabinVector(); 
    auto vectorAppended2 = vf2 + ve2; 
    cabin c2(vectorAppended2);
    cabins.emplace_back(c2);

}


void createPassengers(const std::array<std::string,getFileFixedSize()> & nameArr,
                      const std::array<int,getFileFixedSize()> numShuffleArr,                  
                      std::map<std::string,passenger> & px,
                      std::vector<passenger> & vecPax)
{
    size_t i = 0L; 
    unsigned short age = 18U;  
    for (auto last: nameArr)
    {
        std::string first = nameArr[numShuffleArr[i]];
        passengerName paxName(first, last); 
        seatTypePreference sp = (i % 5 == 0) ? seatTypePreference::window : 
                                (i % 5 == 1) ? seatTypePreference::aisle : 
                                (i % 5 == 2) ? seatTypePreference::middle : 
                                (i % 5 == 3) ? seatTypePreference::window : 
                                               seatTypePreference::aisle; 
                                
        bool employee = (i % 399 == 0) ? true: false; 
        bool banned = (i % 1222 == 0) ? true: false;
        frequentFlyer freqFlyer = (i % 100 == 0)    ?   frequentFlyer::Bronze : 
                                  (i % 312 == 0)    ?   frequentFlyer::Bronze : 
                                  (i % 953 == 0)    ?   frequentFlyer::Gold :
                                  (i % 10999 == 0)  ?   frequentFlyer::InviteOnly : 
                                                        frequentFlyer::Regular;
        passenger p(paxName,age++,sp, freqFlyer, employee, banned);

        age = (age > 99) ? 18U : age;  //if age is greater than 99, let's bring it back to 18
        px.emplace(last, p);
        vecPax.emplace_back(p);
        i++;
    }

} 
 

int main()
{
    //for homework #1 we will use simple parameters. You will need to parsing later
    
    //reads names for passangers
    std::array<std::string,getFileFixedSize()> lastNameArr;
    readFixedNamesFile(std::string("nameofpeople.txt"),lastNameArr);
   

    //creates std::array and shuffles the array of ints to user it for firstname using the lastNameArr
    std::array<int,getFileFixedSize()> arrIndex;
    std::iota(arrIndex.begin(),arrIndex.end(),0); 
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::ranges::shuffle(arrIndex,gen);
    
    //read US Airports 
    std::map<std::string,airport> mapAirportsInUSA; 
    readAirportCsvFile(std::string("airports.csv"), mapAirportsInUSA);
    // // create passangers
    std::map<std::string, passenger> mapPax; 
    std::vector<passenger> vecPax; 


    createPassengers(lastNameArr, arrIndex, mapPax, vecPax);
    //create cabins
    std::vector<cabin> cabins;
    createCabins(cabins);
    
    //create planes
    std::vector<airplane> planes;
   
    size_t howManyPlanes = createPlanes(planes, cabins); 
    //create flight paths
    std::vector<flight> vFlights = createFlights(vecPax,mapAirportsInUSA,
                            planes,howManyPlanes);
    
    flights allFlights(vFlights, mapPax);
    allFlights.flyAll(); 
    std::cout << allFlights << std::endl; 
    std::cout << "done" << std::endl; 
    return 0;
}

