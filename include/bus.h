#pragma once
#include "bus_fwd.h"

typedef struct {
    int busID;
    int capacity;
    std::string route;
    int jumPsg;
} Bus;

struct busElement {
    Bus info;
    busAddress next;
    psgAddress firstPsg;
};

typedef struct {
    busAddress first;
} BusList;