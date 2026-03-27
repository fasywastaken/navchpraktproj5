//
// Created by User on 27/03/2026.
//

#include "train.h"
#include <iostream>
#include <fstream>
#include <utility>

// FIX: Actually assign the text file data to the object's variables
Train::Train(string  from, string  to, string departure, double time, double price)
    : from(std::move(from)), to(std::move(to)), departure(std::move(departure)), time(time), price(price) {
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
double Train::getTime() const {
    return time;
}
double Train::getPrice() const {
    return price;
}

void Train::readTrains(Train*& trains, int& trainCount) {
    ifstream file("trains.txt");
    if (!file.is_open()) {
        cerr << "trains.txt.txt not found" << endl;
        exit(1);
    }
    trainCount=0;

    string from, to, departure; double time, price;
    while (file >> from >> to >> departure >> time >> price) {
        trainCount++;
    }
    if (trainCount <= 0) {
        cerr << "trains.txt.txt empty" << endl;
        exit(1);
    }
    file.clear();
    file.seekg(0, ios::beg);

    trains = new Train[trainCount];

    for (int i=0; i<trainCount; i++) {
        file >> from >> to >> departure >> time >> price;
        trains[i] = Train(from, to, departure, time, price);
    }

} //Filling in the Array

void Train::clearTrains(Train*& trains) {
    if (trains != nullptr) {
        delete[] trains;
        trains = nullptr;
    }
}