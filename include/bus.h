#pragma once
#include <string>
#include "passenger.h"

typedef struct {
    int busID;
    int capacity;
    std::string rute;
} Bus;

typedef struct busElement *busAddress;

struct busElement {
    Bus info;
    busAddress next;
    psgAddress firstPsg;
};

typedef struct {
    busAddress first;
} BusList;

void createListBus(BusList &L);
busAddress createElmBus(int idBus, int kapasitas, std::string rute);
void insertFirstBus(BusList  &L, busAddress bus);
void insertLastBus(BusList &L, busAddress bus);
void insertAfterBus(BusList &L, busAddress bus, busAddress prec);