//
// Created by Roman on 26/3/26.
//

#define USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include "utility.h"
#include "destination.h"

using namespace std;

double utility::haversine(double lat1, double lan1, double lat2, double lan2) {
    double lt1 = lat1*(M_PI/180); double ln1 = lan1*(M_PI/180);
    double lt2 = lat2*(M_PI/180); double ln2 = lan2*(M_PI/180);
    double a = (pow(sin((lt2 - lt1) / 2), 2) + cos(lt1) * cos(lt2) * pow(sin((ln2 - ln1) / 2), 2));
    return 2 * 6371 * asin(sqrt(a));
} //Haversine Dist

double utility::haversine(const Destination &d1, const Destination &d2) {
    return haversine(d1.getLatitude(), d1.getLongitude(), d2.getLatitude(), d2.getLongitude());
} //Haversine overload
