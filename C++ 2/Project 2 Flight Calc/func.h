#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double haversine(double lat1, double lat2, double longs1, double longs2, double radius);
double getFlgihtTime(double lat1, double lat2, double long1, double long2);

#endif