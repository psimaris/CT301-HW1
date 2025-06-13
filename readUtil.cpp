#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "readUtil.h"
#include "airRamException.h"


void readFixedNamesFile(const std::string & fileName, std::array<std::string, cFileFixedSize> & peopleArr )
{
    
    
    std::ifstream textFile(fileName);
    std::string dataLine;

    if (!textFile.is_open())
       throw fixedFileException("Could not open Fixed File");
   
    
    
    
    size_t index =0; 
    while (std::getline(textFile, dataLine) && index < peopleArr.size())
    {
        peopleArr[index] = dataLine; 
        index++; 
    }

    index -= 1; 
    if (index > cFileFixedSize)
        std::cerr << "[Error] File bigger than constant cFileFixed Size " << cFileFixedSize << ". Index = " << index 
                  << "." << "Filename: " << fileName << "." << std::endl; 

    textFile.close(); 
}

void readAirportCsvFile(const std::string & fileName, std::map<std::string,airport> & m)
{
    std::ifstream airportFile(fileName);

    if (!airportFile.is_open())
       throw fixedFileException("Could not open Fixed File");

    std::string line;
    std::getline(airportFile, line); // We don't need the header of the file 

    while (std::getline(airportFile, line))
    {
        std::vector<std::string> v; 
        tokenizeBySeperator(',', line, v);
        airport aport;
        //IATA,AIRPORT,CITY,STATE,COUNTRY,LATITUDE,LONGITUDE
        aport.active = true;  //for now, always true. 
        aport.iataCode = v[0];
        aport.airportName = v[1];
        aport.city = v[2];
        aport.state = v[3]; 
        aport.country = v[4]; 
        aport.latitute = std::stod(v[5]);
        aport.longitude = std::stod(v[6]); 
        m.emplace(v[0],aport); 
    }

    airportFile.close(); 

}

void tokenizeBySeperator(char sep, std::string str, std::vector<std::string> & tokens)
{
     std::string token;
     std::istringstream issToken(str);
     
     while (std::getline(issToken, token, ',')) 
     {
        tokens.emplace_back(token);
     }
}