#pragma once
#include <string>

typedef struct {
    int passengerID;
    std::string nama;
} Passenger;

typedef struct usrElement *psgAddress;

struct usrElement {
    Passenger info;
    psgAddress next;
    psgAddress prev;
};

typedef struct {
    psgAddress first;
    psgAddress last;
} PassengerList;

void createListPassenger(PassengerList &L);

psgAddress createElmPassengger(int id, std::string name);

void insertFirstPassenger(PassengerList &L, psgAddress psg);

void insertLastPassenger(PassengerList &L, psgAddress psg);

void insertAfterPassenger(PassengerList &L, psgAddress prec, psgAddress psg);

void deleteFirstPsg(PassengerList  &L);

void deleteFirstPsg(PassengerList &L, psgAddress &deleted);

void deleteLastPsg(PassengerList &L);

void deleteLastPsg(PassengerList &L, psgAddress &deleted);

void deleteAfterPsg(PassengerList &L, psgAddress prec);

void deleteAfterPsg(PassengerList &L, psgAddress prec, psgAddress &deleted);