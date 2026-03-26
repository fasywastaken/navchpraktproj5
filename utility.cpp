//
// Created by fasy on 26/3/26.
//

#include <iostream>
#include <fstream>
#include "utility.h"

#include <vector>

#include "destination.h"

using namespace std;

void openFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "File" << filename << " not found" << endl;
        exit(1);
    }
}

void readDestinations(Destination*& destinations) {
}

