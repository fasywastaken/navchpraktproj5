//
// Created by Roman on 20/3/26.
//
#include "destination.h"
#include <iostream>
#include <fstream>
using namespace std;

Destination::Destination(std::string n, double lat, double lon)
    : name(std::move(n)), latitude(lat), longitude(lon) {}

string Destination::getName() const {
    return name;
}

double Destination::getLatitude() const {
    return latitude;
}

double Destination::getLongitude() const {
    return longitude;
}

void Destination::readDestinations(Destination*& destinations,int& destCount) {
    ifstream file("destinations.txt");
    if (!file.is_open()) {
        cerr << "Destinations.txt not found" << endl;
        exit(1);
    }
    string name; double lat, lon; destCount=0;

    while (file >> name >> lat >> lon) {
        destCount++;
    }
    if (destCount <= 0) {
        cerr << "destinations.txt empty" << endl;
        exit(1);
    }
    file.clear();
    file.seekg(0, ios::beg);

    destinations = new Destination[destCount];

    for (int i=0; i<destCount; i++) {
        file >> name >> lat >> lon;
        destinations[i] = Destination(name, lat, lon);
    }
} //Filling in the Array

void Destination::clearDestinations(const Destination* destinations) {
    delete[] destinations;
} //Clearing the Array