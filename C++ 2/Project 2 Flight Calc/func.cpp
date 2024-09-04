#include "func.h"

using namespace std;

double haversine(double lat1, double lat2, double long1, double long2, double radius) {
    const double PI = 3.14159265359; // pi constant
    double d = 0; // calculated distance
    
    // Convert degrees to rads
    double latRad1 = lat1 * (PI/180);
    double latRad2 = lat2 * (PI/180);
    double longRad1 = long1 * (PI/180);
    double longRad2 = long2 * (PI/180);
    
    // inner parts of formula for brevity
    double latDifSin = pow(sin((latRad2 - latRad1) / 2), 2);
    double longDifSin = pow(sin((longRad2 - longRad1) / 2), 2);

    d = 2 * radius * asin(sqrt(latDifSin + (cos(latRad1) * cos(latRad2) * longDifSin)));

    return d;
}
double getFlgihtTime(double lat1, double lat2, double long1, double long2) {
    const double RADIUS = 3958.8;
    double flightSpeed = 525; // mph
    double flightTime = 0; // hours
    
    // using previous function for brevity
    double distance = haversine(lat1, lat2, long1, long2, RADIUS);
    
    flightTime = distance / flightSpeed;
    
    return flightTime;
}