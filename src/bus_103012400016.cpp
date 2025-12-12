#include "bus_operation.h"

void createListBus(BusList &L){
    L.first = nullptr;
}

busAddress createElmBus(int id, int capacity, std::string route) {
    busAddress bus;

    bus = new busElement;
    bus->info.busID = id;
    bus->info.capacity = capacity;
    bus->info.route = route;
    bus->info.jumPsg = 0;
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

