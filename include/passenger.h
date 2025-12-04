#pragma once
#include <string>

typedef struct {
    int userID;
    std::string nama;
} userData;

typedef struct usrElement *usrAddress;

struct usrElement {
    userData info;
    usrAddress next;
    usrAddress prev;
};

typedef struct {
    usrAddress first;
    usrAddress last;
} usrList;

void createListPassenger(usrList &L);
usrAddress createElmPassengger(int idUser, std::string nama);
void insertFirstPassenger(usrList &L, usrAddress user);
void insertLastPassenger(usrList &L, usrAddress user);
void insertAfterPassenger(usrList &L, usrAddress prec, usrAddress user);
