#include "psg_operation.h"
#include <iostream>

void deleteFirstPsg(busAddress &bus) {
    if (!bus || bus->firstPsg == nullptr) return;

    psgAddress p = bus->firstPsg;

    if (p->next != nullptr) {
        p->next->prev = nullptr;
    }

    bus->firstPsg = p->next;

    delete p;
}

void deleteFirstPsg(busAddress &bus, psgAddress &deleted) {
    if (!bus || bus->firstPsg == nullptr) {
        deleted = nullptr;
        return;
    }

    deleted = bus->firstPsg;

    if (deleted->next != nullptr) {
        deleted->next->prev = nullptr;
    }

    bus->firstPsg = deleted->next;

    deleted->prev = nullptr;
    deleted->next = nullptr;
}

void deleteLastPsg(busAddress &bus) {
    if (!bus || bus->firstPsg == nullptr) {
        return;
    }

    if (bus->firstPsg->next == nullptr) {
        delete bus->firstPsg;
        bus->firstPsg = nullptr;
    }
    else {
        psgAddress p = bus->firstPsg;
        while (p->next) p = p->next;
        p->prev->next = nullptr;
        delete p;
    }
}

void deleteLastPsg(busAddress &bus, psgAddress &deleted) {
    if (!bus || bus->firstPsg == nullptr) {
        deleted = nullptr;
        return;
    }

    if (bus->firstPsg->next == nullptr) {
        deleted = bus->firstPsg;
        bus->firstPsg = nullptr;
    }
    else {
        psgAddress p = bus->firstPsg;

        while (p->next) p = p->next;

        deleted = p;
        deleted->prev->next = nullptr;
        deleted->prev = nullptr;
    }
}

void deleteAfterPsg(busAddress &bus, psgAddress prec) {
    if (prec == nullptr || prec->next == nullptr) return;

    psgAddress p = prec->next;

    if (p->next != nullptr) {
        p->next->prev = prec;
    }

    prec->next = p->next;

    delete p;
}

void deleteAfterPsg(busAddress &bus, psgAddress prec, psgAddress &deleted) {
    if (prec == nullptr || prec->next == nullptr) return;

    deleted = prec->next;

    if (deleted->next != nullptr) {
        deleted->next->prev = prec;
    }

    prec->next = deleted->next;

    deleted->next = nullptr;

    deleted->prev = nullptr;
}

psgAddress findElmPassenger(busAddress bus, int id) {
    if (!bus) return nullptr;

    psgAddress p = bus->firstPsg;
    while (p && p->info.passengerID != id) p = p->next;
    return p;
}

void displayListPassenger(busAddress bus) {
    if (!bus) return;
    
    int i = 1;
    for (psgAddress p = bus->firstPsg; p; p = p->next) {
        std::cout << "Passenger-" << i << ":\n";
        std::cout << "ID: "<< p->info.passengerID << "\n";
        std::cout << "Nama: "<< p->info.name << "\n";
        std::cout << "Date of Birth: "<< p->info.dateOfBirth << "\n" << std::endl;
        ++i;
    }
}