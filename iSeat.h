#ifndef _I_SEATS_H
#define _I_SEATS_H


#include <optional> 
#include <tuple> 
#include <memory>
#include <vector> 
#include "passenger.h" 




//we are assuming a max configuration of 3 - 5 - 3 = 11. 
enum class seatLetter
{
    A, B, C, D, E, F, G, H, I, J, K 
};

enum class cabinTypes
{
    first,
    business,
    premiumEconomy,
    economy,
    basicEconomy,
    unknown 
};

class iSeat; //forward declatator so you see how it works
using iSeatPtr = std::shared_ptr<iSeat>;
using vecVecSeatsPtr = std::vector<std::vector<iSeatPtr>>;
using vecSeatsPtr = std::vector<iSeatPtr>;
// using vecVecSeats = std::vector<std::vector<iSeat>>;

/// @brief Interface for a seat in an airplane cabin.
/// This interface defines the basic operations that can be performed on a seat,
/// such as checking if it is occupied, getting the passenger assigned to it,
/// removing or setting a passenger, and replacing a passenger.
/// It is designed to be implemented by specific seat classes, allowing for
/// different seat types (e.g., economy, business, first class) to have their own
/// implementations while adhering to a common interface.
/// Note: You will have to implement a seat like class using this interface
/// that allows for reclining without modifying the one I created called seat. 
/// You must call it recliningSeat. The idea is for you to get used to implementing a class
/// so you will be required to have a .h and .cpp files for this recliningSeat class.
/// I may choose to use it with the grader.  
class iSeat
{
public: 
 
    using optTupleSeatPax = std::optional<std::tuple<passenger,iSeatPtr>>;

    virtual bool isOccupied() = 0;
    virtual std::optional<passenger> getPassenger() = 0; 
    virtual seatLetter getLetter() = 0; 
    virtual bool removePassenger() = 0;
    virtual bool setPassenger(const std::optional<passenger> & pax) =0;
    virtual std::optional<passenger>  replacePassenger(const std::optional<passenger> & pax) = 0;
   
    virtual bool getEmergencySeat() = 0;
    virtual void setEmergencySeat(bool emergency) = 0;
    virtual bool isReclining() const = 0; //to be implemented in deluxedSeat
    virtual void setReclining(bool recline) = 0; //to be implemented in delexuedSeat
    virtual ~iSeat() = default;
};



 //using vecSeats = std::vector<iSeat>;

#endif 