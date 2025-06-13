#ifndef _AIRPORT_H
#define _AIRPORT_H

#include <map>
#include <vector>
#include <string>
#include <optional>
struct airport {
    std::string iataCode; 
    std::string airportName; 
    std::string city;
    std::string state; 
    std::string country; 
    double latitute; 
    double longitude; 
    bool active; 
}; 

class airports
{
public:
    airports(const std::map<std::string, airport> & m, 
             const std::vector<airport> & v);
    std::vector<std::string> getAirportCodes() const;
    std::vector<airport> getAirports() const;
    std::optional<airport> getAirportByCode(const std::string & code) const;
    std::optional<airport> getAirportByName(const std::string & name) const;

private: 
    std::map<std::string, airport> airportMap; //key is IATA code
    std::vector<airport> airportVector; //to keep the order of insertion
};
//airport grounds who whols the struct and do more

//and then we need flying system and I thikn we are good. 

//and a way to calcualte the miles 


#endif 