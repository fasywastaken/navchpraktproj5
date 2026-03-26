#include <iostream>
#include <fstream>
#define USE_MATH_DEFINES
#include <cmath>
#include "destination.h"

using namespace std;

double haversineDistance(const Destination &d1, const Destination &d2) {
    double lat1 = d1.getLatitude()*(M_PI/180); double lon1 = d1.getLongitude()*(M_PI/180);
    double lat2 = d2.getLatitude()*(M_PI/180); double lon2 = d2.getLongitude()*(M_PI/180);

    double haversine = (pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((lon2 - lon1) / 2), 2));
    return 2 * 6371 * asin(sqrt(haversine));
}



int main() {
}