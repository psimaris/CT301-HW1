#ifndef _HAVERSINE_H
#define _HAVERSINE_H
#include <iostream>
#include <cmath>
#include <iomanip>


//showing how to do static functions in class.
//prefer not to use them

//function modified from output form Gemini 
class haversine
{
public:
// Haversine formula function
static double calculate(double lat1, double lon1, double lat2, double lon2);

private:
    constexpr static double getEarthRadius() {
        return 6371.0; // Earth's radius in kilometers
    };
    constexpr static double getPI() {
        return 4 * std::atan(1.0);
    };
    constexpr double static degreesToRadians(double degrees) {
            return degrees * getPI() / 180.0;
    };
};

#endif 