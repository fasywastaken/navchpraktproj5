//
// Created by fasy on 20/3/26.
//

#ifndef NAVCHPRAKT5_DESTINATIONS_H
#define NAVCHPRAKT5_DESTINATIONS_H
using namespace std;

class Destination {
private:
    string name;
    double latitude;
    double longitude;
public:
    Destination(string n, double lat, double lon);

    [[nodiscard]] string getName() const;
    [[nodiscard]] double getLatitude() const;
    [[nodiscard]] double getLongitude() const;
};

#endif //NAVCHPRAKT5_DESTINATIONS_H