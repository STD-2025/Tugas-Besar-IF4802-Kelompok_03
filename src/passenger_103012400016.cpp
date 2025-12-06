#include "bus.h"

void createListPassenger(PassengerList &L){
    L.first = nullptr;
    L.last = nullptr;
}

psgAddress createElmPassengger(int id, std::string name) {
    psgAddress psg;

    psg = new passengerElement;
    psg->info.nama = name;
    psg->info.passengerID = id;
    psg->next = nullptr;
    psg->prev = nullptr;

    return psg;
}

void insertFirstPassenger(PassengerList &L, psgAddress psg, busAddress bus) {
    if(L.first == nullptr && L.last == nullptr){
        bus->firstPsg = psg;
        L.first = psg;
        L.last = psg;
    }else{
        psg->next = bus->firstPsg;
        bus->firstPsg->prev = psg;
        bus->firstPsg = psg;
        L.first = psg;
    }
}

void insertLastPassenger(PassengerList &L, psgAddress psg, busAddress bus) {
    psgAddress q;
    if(L.first == nullptr && L.last == nullptr){
        L.first = psg;
        L.last = psg;
    }else{
        q = bus->firstPsg;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = psg;
        psg->prev = L.last;
        L.last = psg;
    }
}

void insertAfterPassenger(PassengerList &L, psgAddress prec, psgAddress psg, busAddress bus){
    psgAddress q;
    q = bus->firstPsg;
    while (q != prec)
    {
        q = q->next;
    }
    psg->next = prec->next;
    psg->prev = prec;
    prec->next = psg;
    prec->next->prev = psg;
} 