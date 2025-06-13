#include "cabin.h"

#include <algorithm>
#include <random> 
#include <memory>
#include <typeinfo>
#include <ostream>
#include <iostream>
#include <exception>
#include "seat.h"
#include "passenger.h"

//cabin incomplete for students 
//you are responsible for all code


cabin::cabin(const vecVecSeatsPtr & cSeats)
        : cabSeats(cSeats), cabinCapacity(0), cabinRows(0)
{

    //calculate cabinCapacity here as you need to check CabSeats
    //Calculated only one time. 
    //how would you do this?
    // do it below 

    
}

cabin::optTupleSeatPax cabin::findPassenger(const passenger & pax)
{
    //this is slow if you use the vector provided
    //  -- how would you handle this faster? 
    return std::nullopt; 
}
iSeatPtr cabin::getSeat(const unsigned int row, seatLetter letter)
{
    ///for a given row and leatter, returned a shared pointer. 
    /// in this case, return an iSeatPtr, since this is a shared_ptr<iSeat> 

    return nullptr; 
}
vecSeatsPtr cabin::getRow(const unsigned int row)
{
    //return a row from the cabin.
    auto v = cabSeats[row];
    return v; 
}

bool cabin::autoAssignPassengers(std::vector<passenger> & vPax,
                                 bool useCriteria)
{
    //if vector is empty, return false. Otherwise, it is true.
    if (vPax.size() == 0)
        return false; 
    //if criteria is true, do the following below. 
    //regardless of criteria, the passenger cannot be in a plane if is banned. 
    if (useCriteria)
    {
        //call this one below  
        //autoAssignedPassengerCriteria function 
    }
    else
    {
      
        // assigned first come first serve (meaning, whoever you find first )
        // but it must be random
        //use autoAssignedPassengerRandom function 
    }

    return true;
} 

void cabin::autoAssignPassengersRandom(std::vector<passenger> & vPax)
{
    //it will write in top of existing passengers 

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vPax.begin(), vPax.end(), g);
    //this gives you a vector of passengers shuffle... since this was randomized already. 
    //careful that vPax is a reference so know who is passing it to be careful
    //if you want to be save, you could create a new vector, such as 
    // to create a new one, you an do auto vPaxShuffle = vPax; This will create a copy. 
    // randomoly asigned them using your shuffle array. No need for criteria here. 
} 

void cabin::autoAssignPassengersCriteria(std::vector<passenger> & vPax)
{
    //it can write on top of passengers 
     //criteria 
    //1. Fill the firtt class seats with invite only and gold. 
    //2. if still seats left, give it to silver 
    //3. If you have more of invite only, gold, (and silver), then put them in the cabin. 
    //   meaning, first come first serve (or whoever you find first)
    //4. Then assigned all the bronze 
    //5. Then from highest to lowest (invite only, gold, ... ) fill the emergency seats if they exist. 
    //5. then assigned everyone else. 
    //6. If there are more passengers after that, ignore them
    //this logic should be placed inside the function below 
} 

size_t cabin::getCabinCapacity() 
{
    return cabinCapacity;
}

size_t cabin::getCabinRows() 
{
    return cabinRows;
}

size_t cabin::getCabinOpenSeats() 
{
    //calculate it. 
    return 0;
}

bool cabin::clearAllPassengers() 
{
    //return false if there were no passangers, else true. 
    //remove all passengers from cabSeats
    return false;
}

bool cabin::processAllPassengers
                    (const double theMiles, const double money, 
                        std::shared_ptr<mapPassengers> & mPaxPtr)
{
    size_t countPax =0; 
    for (auto & outer : cabSeats)
    {
        for (auto & s : outer)
        {
            auto optPax = s->getPassenger();
            if (optPax.has_value())
            {
                countPax++;
                auto pax = optPax.value();
                auto lastName = pax.getPassengerName().getPassengerLastName();
                std::tuple<double, double> processedValues = 
                    processPassengerValues(theMiles, money, pax);
                auto newMoney = std::get<0>(processedValues);
                auto newMiles = std::get<1>(processedValues);
                pax.addMiles(newMoney);
                pax.AddMoneySpent(newMiles);
                //s->setPassenger(pax); //update the passenger in the seat
                //update DB from flights 
                try 
                {
                    mPaxPtr->at(pax.getPassengerName().getPassengerLastName()) = pax; 
                }
                  catch (const std::out_of_range& e) {
                    std::cerr << "Error: Key  not found for update in cabin." << std::endl;
                    //insert 
                    mPaxPtr->emplace(lastName, pax);
                }
            }
        }
    }
 
    return (countPax == 0) ? false: true;
}

std::tuple<double, double> cabin::processPassengerValues(const double miles, const double money
                                                      ,  passenger & pax)
{
    //this is a helper function to process the values
    //you can use it to return a tuple of values
    //for example, you can return the miles and money
    //or you can return the miles and money spent
    double newMiles = 0;
    double newMoney = 0;
    
    auto fFlyer = pax.getFrequentFlyer();
    //criteria 
    //miles: 10% bonus for bronze, 20% bonus for silver, 40% bonus for gold, 60% bonus for invite only
    // in other words, this means * 1.2, 1.3.. 
    //money: if employee, 50% less but they also get no miles. 
    //money: if flying in first or business class, it is money * 1.75
    //money: if flying in premiun econonomy it is money * 1.25
    //money: if flying in economy is money * 1
    //money: if flying in basic econ, it is .85 (meaning ,15% discount.)
    //you must use a switch statement but for stuff that don't fit in the switch statement
    // you can use IFs or any other methods. 
 

   
    return std::make_tuple(miles, money);
}


 
bool cabin::processAllPassengers(const std::vector<std::tuple<double,double>> & vData, std::shared_ptr<mapPassengers> & mPaxPtr)
{
    for (auto v : vData)
    {
        auto const [miles, money] = v;
        processAllPassengers(miles, money, mPaxPtr); 
    }
    return true; 
} 