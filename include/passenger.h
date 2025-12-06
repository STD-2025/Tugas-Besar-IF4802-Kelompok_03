#pragma once
#include <string>

typedef struct {
    int passengerID;
    std::string name;
    std::string dateOfBirth;
} Passenger;

typedef struct passengerElement *psgAddress;

struct passengerElement {
    Passenger info;
    psgAddress next;
    psgAddress prev;
};

typedef struct {
    psgAddress first;
    psgAddress last;
} PassengerList;

void createListPassenger(PassengerList &L);

psgAddress createElmPassengger(int id, std::string name, std::string dateOfBirth);

void insertFirstPassenger(PassengerList &L, psgAddress psg, busAddress bus);

void insertLastPassenger(PassengerList &L, psgAddress psg, busAddress bus);

void insertAfterPassenger(PassengerList &L, psgAddress prec, psgAddress psg, busAddress bus);

void deleteFirstPsg(PassengerList  &L);

void deleteFirstPsg(PassengerList &L, psgAddress &deleted);

void deleteLastPsg(PassengerList &L);

void deleteLastPsg(PassengerList &L, psgAddress &deleted);

void deleteAfterPsg(PassengerList &L, psgAddress prec);

void deleteAfterPsg(PassengerList &L, psgAddress prec, psgAddress &deleted);

psgAddress findElmPassenger(PassengerList L, int id);

void displayListPassenger(PassengerList L);