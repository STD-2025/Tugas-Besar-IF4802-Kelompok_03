#include "bus.h"

void createListPassenger(PsgList &L){
    L.first = nullptr;
    L.last = nullptr;
}

psgAddress createElmPassengger(int idUser, std::string nama){
    psgAddress user;

    user = new usrElement;
    user->info.nama = nama;
    user->info.userID = idUser;
    user->next = nullptr;
    user->prev = nullptr;

    return user;
}

void insertFirstPassenger(PsgList &L, psgAddress user){
    if(L.first == nullptr && L.last == nullptr){
        L.first = user;
        L.last = user;
    }else{
        user->next = L.first;
        L.first->prev = user;
        L.first = user;
    }
}

void insertLastPassenger(PsgList &L, psgAddress user){
    if(L.first == nullptr && L.last == nullptr){
        L.first = user;
        L.last = user;
    }else{
        L.last->next = user;
        user->prev = L.last;
        L.last = user;
    }
}

void insertAfterPassenger(PsgList &L, psgAddress prec, psgAddress user){
    user->next = prec->next;
    user->prev = prec;
    prec->next = user;
    prec->next->prev = user;
}