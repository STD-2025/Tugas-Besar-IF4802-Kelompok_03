#pragma once
#include "bus.h"
#include "passenger.h"

void createListBus(BusList &L);

busAddress createElmBus(int id, int capacity, std::string route);

void insertFirstBus(BusList  &L, busAddress bus);

void insertLastBus(BusList &L, busAddress bus);

void insertAfterBus(BusList &L, busAddress bus, busAddress prec);

void deleteFirstBus(BusList  &L);

void deleteFirstBus(BusList &L, busAddress &deleted);

void deleteLastBus(BusList &L);

void deleteLastBus(BusList &L, busAddress &deleted);

void deleteAfterBus(BusList &L, busAddress prec);

void deleteAfterBus(BusList &L, busAddress prec, busAddress &deleted);

busAddress findElmBus(BusList L, int id);

void displayListBus(BusList L);