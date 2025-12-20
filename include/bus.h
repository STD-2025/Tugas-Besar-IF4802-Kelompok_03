#pragma once
#include "bus_fwd.h"
#include <vector>

typedef struct {
    int routeID;
    std::string start;
    std::string end;
    float attractiveness;
} BusRoute;

typedef struct {
    int busID;
    std::string busName;
    int capacity;
    BusRoute route;
    int passengerCount;
    double price;
} Bus;

struct busElement {
    Bus info;
    busAddress next;
    psgAddress firstPsg;
};

typedef struct {
    busAddress first;
} BusList;