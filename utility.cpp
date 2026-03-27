//
// Created by fasy on 26/3/26.
//

#define USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include "utility.h"
#include "destination.h"

using namespace std;

double utility::haversine(const Destination &d1, const Destination &d2) {
    double lat1 = d1.getLatitude()*(M_PI/180); double lon1 = d1.getLongitude()*(M_PI/180);
    double lat2 = d2.getLatitude()*(M_PI/180); double lon2 = d2.getLongitude()*(M_PI/180);

    double a = (pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((lon2 - lon1) / 2), 2));
    return 2 * 6371 * asin(sqrt(a));
} //Haversine Dist

