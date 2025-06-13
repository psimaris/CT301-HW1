#include "haversine.h"

double haversine::calculate(double lat1, double lon1, double lat2, double lon2)
{
    // Earth's radius in kilometers
    const double earthRadius = getEarthRadius(); 

    // Convert latitude and longitude from degrees to radians
    double lat1Rad = degreesToRadians(lat1);
    double lon1Rad = degreesToRadians(lon1);
    double lat2Rad = degreesToRadians(lat2);
    double lon2Rad = degreesToRadians(lon2);

    
    // Differences in latitude and longitude
    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;

    // Haversine formula
    double a = std::pow(std::sin(dLat / 2), 2) + std::cos(lat1Rad) * 
                                std::cos(lat2Rad) * std::pow(std::sin(dLon / 2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    // Distance in kilometers
    double distance = earthRadius * c;

    return distance;
}

