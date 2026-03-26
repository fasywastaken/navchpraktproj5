//
// Created by fasy on 20/3/26.
//
#include <iostream>
#include <fstream>
#include "destinations.h"

#include <complex>
#include <iomanip>
using namespace std;
Dest* dests;
int dests_cnt;

    void Destinations::read_dests() {
        ifstream file("dests.txt");
        if (!file.is_open()) {
            cerr << "Bida" << endl;
        }

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                dests_cnt++;
            }
        }

        file.clear();
        file.seekg(0, ios::beg);
        dests = new Dest[dests_cnt];

        for (int i = 0; i < dests_cnt; i++) {
            file >> dests[i].dest_name >> dests[i].country >> dests[i].latitude >> dests[i].longitude;
        }
        file.close();
    }

    void Destinations::display_dests() const {
        cout << "~~~Destinations~~~" << endl;
        for (int i = 0; i < dests_cnt; i++) {
            cout << left << setw(18) << dests[i].dest_name << dests[i].country
                 << " | " << fixed << setprecision(4)
                 << setw(8) << dests[i].latitude << " "
                 << setw(8) << dests[i].longitude << endl;
        }

    }

    double Destinations::haversine(int i1, int i2) const {
        double lat1 = dests[i1].latitude;
        double lat2 = dests[i2].latitude;
        double lon1 = dests[i1].longitude;
        double lon2 = dests[i2].longitude;
        return 2*6371*asin(sqrt(pow(sin((lat2 - lat1)/2 ) )), 2) + cos(dests[i1].latitude)    );

    }
