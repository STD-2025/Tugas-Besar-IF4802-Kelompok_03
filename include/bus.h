#pragma once

#include "passenger.h"

typedef struct {
    int busID;
    int capacity;
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

