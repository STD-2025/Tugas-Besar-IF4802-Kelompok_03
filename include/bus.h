#pragma once
#include <string>
#include "passenger.h"

typedef struct {
    int busID;
    int capacity;
    std::string rute;
} infotype;

typedef struct busElement *busAddress;

struct busElement {
    infotype info;
    busAddress next;
    usrAddress firstPsg;
};

typedef struct {
    busAddress first;
} busList;

