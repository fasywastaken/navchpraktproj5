//
// Created by Roman on 20/3/26.
//
#ifndef NAVCHPRAKT5_DESTINATIONS_H
#define NAVCHPRAKT5_DESTINATIONS_H
#include <iostream>
using namespace std;

class Destination {
    string name;
    double latitude{};
    double longitude{};

public:
    Destination() = default;
    Destination(string n, double lat, double lon);

    [[nodiscard]] string getName() const;
    [[nodiscard]] double getLatitude() const;
    [[nodiscard]] double getLongitude() const;

    static void readDestinations(Destination*& destinations, int& destCount);//avoid memleak
    static void clearDestinations(const Destination* destinations);

    ~Destination() = default;
};

#endif //NAVCHPRAKT5_DESTINATIONS_H