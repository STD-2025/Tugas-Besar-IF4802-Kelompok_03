#pragma once
#include <string>

typedef struct {
    int userID;
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
} PsgList;

void createListPassenger(PsgList &L);

psgAddress createElmPassengger(int id, std::string name);

void insertFirstPassenger(PsgList &L, psgAddress psg);

void insertLastPassenger(PsgList &L, psgAddress psg);

void insertAfterPassenger(PsgList &L, psgAddress prec, psgAddress psg);

void deleteFirstPsg(PsgList  &L);

void deleteFirstPsg(PsgList &L, psgAddress &deleted);

void deleteLastPsg(PsgList &L);

void deleteLastPsg(PsgList &L, psgAddress &deleted);

void deleteAfterPsg(PsgList &L, psgAddress prec);

void deleteAfterPsg(PsgList &L, psgAddress prec, psgAddress &deleted);