#include "airport.h"


#include "haversine.h"        

airports::airports(const std::map<std::string, airport> & m, 
             const std::vector<airport> & v): airportMap(m), airportVector(v)
{

} 

std::vector<std::string> airports::getAirportCodes() const
{
    std::vector<std::string> codes;
    for (const auto &pair : airportMap) {
        codes.push_back(pair.first);
    }
    return codes;
}

std::vector<airport> airports::getAirports() const
{
    return airportVector;
}


std::optional<airport> airports::getAirportByCode(const std::string & code) const
{
    auto it = airportMap.find(code);
    if (it != airportMap.end()) {
        return it->second;
    }
    return std::nullopt;
}


std::optional<airport> airports::getAirportByName(const std::string & name) const
{
    for (const auto &pair : airportMap) {
        if (pair.second.airportName == name) {
            return pair.second;
        }
    }
    return std::nullopt;
}









