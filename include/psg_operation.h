#pragma once

#include "bus.h"
#include "passenger.h"

psgAddress createElmPassengger(int id, std::string name, std::string dateOfBirth);

void insertFirstPassenger(psgAddress psg, busAddress bus);

void insertLastPassenger(psgAddress psg, busAddress bus);

void insertAfterPassenger(psgAddress prec, psgAddress psg, busAddress bus);

void deleteFirstPsg(busAddress &bus);

void deleteFirstPsg(busAddress &bus, psgAddress &deleted);

void deleteLastPsg(busAddress &bus);

void deleteLastPsg(busAddress &bus, psgAddress &deleted);

void deleteAfterPsg(busAddress &bus, psgAddress prec);

void deleteAfterPsg(busAddress &bus, psgAddress prec, psgAddress &deleted);

psgAddress findElmPassenger(busAddress bus, int id);

void displayListPassenger(busAddress bus);