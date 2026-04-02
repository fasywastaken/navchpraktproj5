//
// Created by Roman on 27/03/2026.
//

#include "train.h"
#include <iostream>
#include <fstream>
#include <utility>

Train::Train(string  from, string  to, string departure, double duration, double price)
    : from(std::move(from)), to(std::move(to)), departure(std::move(departure)), duration(duration), price(price) {
}

string Train::getFrom() const {
    return from;
}

string Train::getTo() const {
    return to;
}

string Train::getDeparture() const {
    return departure;
}
double Train::getDuration() const {
    return duration;
}
double Train::getPrice() const {
    return price;
}

void Train::readTrains(Train*& trains, int& trainCount) {
    ifstream file("trains.txt");
    if (!file.is_open()) {
        cerr << "trains.txt not found" << endl;
        exit(1);
    }
    trainCount=0;

    string from, to, departure; double duration; double price;
    while (file >> from >> to >> departure >> duration >> price) {
        trainCount++;
    }
    if (trainCount <= 0) {
        cerr << "trains.txt empty" << endl;
        exit(1);
    }
    file.clear();
    file.seekg(0, ios::beg);

    trains = new Train[trainCount];

    for (int i=0; i<trainCount; i++) {
        file >> from >> to >> departure >> duration >> price;
        trains[i] = Train(from, to, departure, duration, price);
    }

} //Filling in the Array

void Train::clearTrains(const Train* trains) {
    delete[] trains;
}