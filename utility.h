//
// Created by fasy on 26/3/26.
//

#ifndef NAVCHPRAKT5_UTILITY_H
#define NAVCHPRAKT5_UTILITY_H
#define UTILITY_H

#include "destination.h"

class utility {
    public:
    utility() = default;

    static double haversine(const Destination &d1, const Destination &d2);

    ~utility() = default;
};



#endif //NAVCHPRAKT5_UTILITY_H
