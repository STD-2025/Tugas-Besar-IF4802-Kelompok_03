#include "psg_operation.h"
#include <iostream>

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

void insertPassengerBySeat(psgAddress psg, busAddress bus){
    if (bus->info.passengerCount >= bus->info.capacity){
        return;
    }
    
    psgAddress curr;
    curr = bus->firstPsg;

    if (bus->firstPsg == nullptr || psg->info.seatNo < curr->info.seatNo){
        insertFirstPassenger(psg, bus);
    }

    while (curr->next != nullptr && curr->next->info.seatNo < psg->info.seatNo)
    {
        curr = curr->next;
    }
    
    if (curr->next == nullptr) {
        insertLastPassenger(psg, bus);
    } else {
        insertAfterPassenger(curr, psg, bus);
    }
}

void removePassengerBySeat(busAddress bus, int seatNo) {
    if (bus->firstPsg == nullptr) {
        return;
    }

    psgAddress curr = bus->firstPsg;

    // jika di awal
    if (curr->info.seatNo == seatNo) {
        bus->firstPsg = curr->next;
        if (bus->firstPsg != nullptr) {
            bus->firstPsg->prev = nullptr;
        }
        delete curr;
        bus->info.passengerCount--;
        return;
    }

    // di tengah / akhir
    while (curr != nullptr && curr->info.seatNo != seatNo) {
        curr = curr->next;
    }

    if (curr != nullptr) {
        curr->prev->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        delete curr;
        bus->info.passengerCount--;
    }
}
