//
// Created by User on 27/03/2026.
//
#ifndef NAVCHPRAKT5_TRAIN_H
#define NAVCHPRAKT5_TRAIN_H
#include <iostream>
using namespace std;


class Train {
private:
    string from; string to; string departure; double time{}; double price{};
    public:
    Train() = default;
    Train(string  from, string  to, string  departure,double time, double price);

    [[nodiscard]] string getFrom() const;
    [[nodiscard]] string getTo() const;
    [[nodiscard]] string getDeparture() const;
    [[nodiscard]] double getTime() const;
    [[nodiscard]] double getPrice() const;

    static void readTrains(Train*& trains, int& trainCount);
    static void clearTrains(Train*& trains);

    ~Train() = default;
};

#endif //NAVCHPRAKT5_TRAIN_H

