//
// Created by fasy on 20/3/26.
//

#ifndef NAVCHPRAKT5_DESTINATIONS_H
#define NAVCHPRAKT5_DESTINATIONS_H
using namespace std;

struct Dest {
    string dest_name;
    string country;
    double latitude{};
    double longitude{};

};

class Destinations {
private:
    Dest* dests;
    int dests_cnt;
public:
    Destinations() : dests(nullptr), dests_cnt(0) {}

    void read_dests();
    void display_dests() const;
    double haversine(int i1, int i2) const;

    ~Destinations() {
        delete[] dests;
    }
};


#endif //NAVCHPRAKT5_DESTINATIONS_H