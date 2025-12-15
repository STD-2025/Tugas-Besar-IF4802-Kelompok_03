#include "bus_operation.h"

void createListBus(BusList &L){
    L.first = nullptr;
}

busAddress createElmBus(Bus bus_data) {
    busAddress bus;

    bus = new busElement;
    bus->info = bus_data;
    bus->next = nullptr;
    bus->firstPsg = nullptr;
    return bus;
}

void insertFirstBus(BusList  &L, busAddress bus){
    if(L.first == nullptr){
        L.first = bus;
    }else{
        bus->next = L.first;
        L.first = bus;
    }
}

void insertLastBus(BusList &L, busAddress bus){
    busAddress q;

    if(L.first == nullptr){
        L.first = bus;
    }else{
        q = L.first;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = bus;
    }
}

void insertAfterBus(BusList &L, busAddress bus, busAddress prec){
    if(prec->next == nullptr){
        insertLastBus(L, bus);
    }else{
        bus->next = prec->next;
        prec->next =  bus;
    }
}

float hitungRatioBus(busAddress bus){
   return float(bus->info.passengerCount) / float(bus->info.capacity); 
}

void insertionSortBus(BusList &L){
    if (L.first == nullptr || L.first->next == nullptr) {
        return;
    }

    busAddress sorted;
    sorted = nullptr;

    busAddress curr;
    curr = L.first;
    while (curr != nullptr) {
        busAddress next;
        next = curr->next; 

        if (sorted == nullptr || hitungRatioBus(curr) < hitungRatioBus(sorted)) {
            curr->next = sorted;
            sorted = curr;
        } else {
            busAddress temp;
            temp = sorted;
            while (temp->next != nullptr &&
                   hitungRatioBus(temp->next) <= hitungRatioBus(curr)) {
                temp = temp->next;
            }

            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next;
    }

    L.first = sorted;
}
