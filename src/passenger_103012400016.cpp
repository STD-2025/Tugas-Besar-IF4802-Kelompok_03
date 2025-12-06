#include "psg_operation.h"

psgAddress createElmPassengger(int id, std::string name, std::string tglLahir) {
    psgAddress psg;

    psg = new passengerElement;
    psg->info.name = name;
    psg->info.passengerID = id;
    psg->info.dateOfBirth = tglLahir;
    psg->next = nullptr;
    psg->prev = nullptr;

    return psg;
}

void insertFirstPassenger(psgAddress psg, busAddress bus) {
    if(bus->firstPsg == nullptr){
        bus->firstPsg = psg;
    }else{
        psg->next = bus->firstPsg;
        bus->firstPsg->prev = psg;
        bus->firstPsg = psg;
    }
}

void insertLastPassenger(psgAddress psg, busAddress bus) {
    psgAddress q;
    if(bus->firstPsg == nullptr){
       bus->firstPsg = psg;
    }else{
        q = bus->firstPsg;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = psg;
        psg->prev = q;
    }
}

void insertAfterPassenger(psgAddress prec, psgAddress psg, busAddress bus){
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