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
psgAddress createElmPassengger(int idUser, std::string nama);
void insertFirstPassenger(PsgList &L, psgAddress user);
void insertLastPassenger(PsgList &L, psgAddress user);
void insertAfterPassenger(PsgList &L, psgAddress prec, psgAddress user);
