#include "bus.h"

void createListPassenger(usrList &L){
    L.first = nullptr;
    L.last = nullptr;
}

usrAddress createElmPassengger(int idUser, std::string nama){
    usrAddress user;

    user = new usrElement;
    user->info.nama = nama;
    user->info.userID = idUser;
    user->next = nullptr;
    user->prev = nullptr;

    return user;
}

void insertFirstPassenger(usrList &L, usrAddress user){
    if(L.first == nullptr && L.last == nullptr){
        L.first = user;
        L.last = user;
    }else{
        user->next = L.first;
        L.first->prev = user;
        L.first = user;
    }
}

void insertLastPassenger(usrList &L, usrAddress user){
    if(L.first == nullptr && L.last == nullptr){
        L.first = user;
        L.last = user;
    }else{
        L.last->next = user;
        user->prev = L.last;
        L.last = user;
    }
}

void insertAfterPassenger(usrList &L, usrAddress prec, usrAddress user){
    user->next = prec->next;
    user->prev = prec;
    prec->next = user;
    prec->next->prev = user;
}