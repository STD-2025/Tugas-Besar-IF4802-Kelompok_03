#pragma once
#include "bus_fwd.h"

typedef struct {
    int passengerID;
    std::string name;
    std::string dateOfBirth;
} Passenger;

struct passengerElement {
    Passenger info;
    psgAddress next;
    psgAddress prev;
};