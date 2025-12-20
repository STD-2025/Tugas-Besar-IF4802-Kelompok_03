#pragma once
#include "bus_fwd.h"

typedef struct {
    int passengerID;
    std::string name;
    int age;
    int seatNo;
} Passenger;

struct passengerElement {
    Passenger info;
    psgAddress next;
    psgAddress prev;
};