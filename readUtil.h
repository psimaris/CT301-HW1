#ifndef _READ_UTIL_H
#define _READ_UTIL_H

#include <string> 
#include <map> 
#include <vector>
#include "airport.h"

constexpr size_t cFileFixedSize = 197247; 
constexpr size_t getFileFixedSize() {return cFileFixedSize;}



void readFixedNamesFile(const std::string & fileName, std::array<std::string, cFileFixedSize> & peopleArr );
void readAirportCsvFile(const std::string & fileName, std::map<std::string,airport> & m);
void tokenizeBySeperator(char sep, std::string str, std::vector<std::string> & tokens);


#endif 