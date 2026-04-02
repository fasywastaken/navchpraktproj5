//
// Created by fasy on 27/3/26.
//
#include <iostream>
#include <fstream>
#include "destination.h"
#include "train.h"
#include "utility.h"
#include "dijkstra.h"

using namespace std;

int main() {
    Destination* destinations = nullptr;
    int destCount = 0;
    Destination::readDestinations(destinations, destCount);

    Train* trains = nullptr;
    int trainCount = 0;
    Train::readTrains(trains, trainCount);

    cout << "Destination info:" << endl;
    for (int i = 0; i < destCount; i++) {
        cout << destinations[i].getName() <<" " << destinations[i].getLatitude() << " "<< destinations[i].getLongitude() << endl;
    }

    cout << endl << "Trains info:" << endl;
    for (int i = 0; i < trainCount; i++) {
        cout << "From: " << trains[i].getFrom() << " | To: " << trains[i].getTo() << " | Departure: " << trains[i].getDeparture()<< " | Duration: " << trains[i].getDuration() << " | Price: " << trains[i].getPrice() << endl;
    }

    string city1; string city2;
    cout <<endl << " Input the first city: "; cin >> city1 ;
    cout << "Input the second city: "; cin >> city2;

    Destination* d1 = nullptr;
    Destination* d2 = nullptr;

    for (int i = 0; i < destCount; i++) {
        if (destinations[i].getName() == city1) {
            d1 = &destinations[i];
        }
        if (destinations[i].getName() == city2) {
            d2 = &destinations[i];
        }
    }

    if (d1 != nullptr && d2 != nullptr) {
        double distance = utility::haversine(*d1, *d2);
        cout <<endl << " The Straight line distance is: " <<  distance << "km" << endl;

        Graph ukrzaliznytsia;
        Dijkstra googleMaps(ukrzaliznytsia);
        googleMaps.dijkstra_funct(ukrzaliznytsia, city1, city2); //КРИВІ РЕЙКИ СТРЬОМНІ ШПАЛИ

    } else {
        cerr <<"Invalid cities lol" << endl;
    }

    Destination::clearDestinations(destinations);
    Train::clearTrains(trains);
    return 0;
}