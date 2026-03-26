#include <iostream>
#include "destinations.h"
using namespace std;

int main() {
    Destinations dests;
    dests.read_dests();
    dests.display_dests();
}