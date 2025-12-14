#include "psg_operation.h"
#include <iostream>

using namespace std;
psgAddress createElmPassengger(Passenger passenger_info) {
    psgAddress psg;

    psg = new passengerElement;
    psg->info = passenger_info;
    psg->next = nullptr;
    psg->prev = nullptr;

    return psg;
}

void insertFirstPassenger(psgAddress psg, busAddress bus) {
    if(bus->firstPsg == nullptr){
        bus->firstPsg = psg;
    }else if(bus->info.passengerCount == bus->info.capacity){
        return;
    }else{
        psg->next = bus->firstPsg;
        bus->firstPsg->prev = psg;
        bus->firstPsg = psg;
    }
    bus->info.passengerCount++;
}

void insertLastPassenger(psgAddress psg, busAddress bus) {
    psgAddress q;
    if(bus->firstPsg == nullptr){
       bus->firstPsg = psg;
    }else if(bus->info.passengerCount == bus->info.capacity){
        return;
    }else{
        q = bus->firstPsg;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = psg;
        psg->prev = q;
    }
    bus->info.passengerCount++;
}

void insertAfterPassenger(psgAddress prec, psgAddress psg, busAddress bus){
    if(bus !=  nullptr && bus->info.passengerCount == bus->info.capacity){
      return;
    }
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

    bus->info.passengerCount++;
} 