#include "passenger.h"

void createListPassenger(PassengerList &L){
    L.first = nullptr;
    L.last = nullptr;
}

psgAddress createElmPassengger(int id, std::string name) {
    psgAddress psg;

    psg = new usrElement;
    psg->info.nama = name;
    psg->info.passengerID = id;
    psg->next = nullptr;
    psg->prev = nullptr;

    return psg;
}

void insertFirstPassenger(PassengerList &L, psgAddress psg) {
    if(L.first == nullptr && L.last == nullptr){
        L.first = psg;
        L.last = psg;
    }else{
        psg->next = L.first;
        L.first->prev = psg;
        L.first = psg;
    }
}

void insertLastPassenger(PassengerList &L, psgAddress psg) {
    if(L.first == nullptr && L.last == nullptr){
        L.first = psg;
        L.last = psg;
    }else{
        L.last->next = psg;
        psg->prev = L.last;
        L.last = psg;
    }
}

void insertAfterPassenger(PassengerList &L, psgAddress prec, psgAddress psg){
    psg->next = prec->next;
    psg->prev = prec;
    prec->next = psg;
    prec->next->prev = psg;
}