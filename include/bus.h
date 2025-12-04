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

void createListBus(busList &L);
busAddress createElmBus(int idBus, int kapasitas, std::string rute);
void insertFirstBus(busList  &L, busAddress bus);
void insertLastBus(busList &L, busAddress bus);
void insertAfterBus(busList &L, busAddress bus, busAddress prec);