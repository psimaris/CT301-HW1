#ifndef _SEATS_H
#define _SEATS_H


#include <optional> 
#include <tuple> 
#include "passenger.h" 
#include "iSeat.h"
//forward declator so you see how it works
//but somewhat redundant with modules





class seat : public iSeat 
{
public: 
    
    seat(seatLetter lt, bool o = false, std::optional<passenger> oPax = std::nullopt);
    //seat() = default; 
   
    bool isOccupied();
    std::optional<passenger> getPassenger(); 
    seatLetter getLetter();
    bool getEmergencySeat() ;
    void setEmergencySeat(bool emergency) ; 
    void setReclining(bool recline)  {} //not implemented in this class
    bool isReclining() const override { return false; } //not implemented in this class     
  
    bool removePassenger();
    bool setPassenger(const std::optional<passenger> & pax);
    std::optional<passenger> replacePassenger(const std::optional<passenger> & pax);
    ~seat() = default; //virtual destructor to allow for polymorphism

    //for grading purposes 
    friend class ct301Tester;
    
private: 

    bool occupied;
    std::optional<passenger> optPax; 
    seatLetter letter;
    
     

};




#endif 