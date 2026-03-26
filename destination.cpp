//
// Created by fasy on 20/3/26.
//
#include <iostream>
#include <iomanip>
#include <utility>
#include "destination.h"

Destination::Destination(string nam, double lat, double lon) {
    name = std::move(nam);
    latitude = lat;
    longitude = lon;
}

string Destination::getName() const {
    return name;
}

double Destination::getLatitude() const {
    return latitude;
}

double Destination::getLongitude() const {
    return longitude;
}
