#pragma once
#include <string>

typedef struct {
    int passengerID;
    std::string nama;
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

void insertFirstPassenger(psgAddress psg, busAddress bus);

void insertLastPassenger(psgAddress psg, busAddress bus);

void insertAfterPassenger(psgAddress prec, psgAddress psg, busAddress bus);

void deleteFirstPsg(PassengerList  &L);

void deleteFirstPsg(PassengerList &L, psgAddress &deleted);

void deleteLastPsg(PassengerList &L);

void deleteLastPsg(PassengerList &L, psgAddress &deleted);

void deleteAfterPsg(PassengerList &L, psgAddress prec);

void deleteAfterPsg(PassengerList &L, psgAddress prec, psgAddress &deleted);

psgAddress findElmPassenger(PassengerList L, int id);

void displayListPassenger(PassengerList L);