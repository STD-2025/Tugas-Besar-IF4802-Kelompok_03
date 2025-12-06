#include "passenger.h"
#include <iostream>

void deleteFirstPsg(PassengerList  &L) {
    if (L.first == nullptr) return;

    if (L.first == L.last) {
        L.last = nullptr;
    }

    psgAddress p = L.first;
    L.first = p->next;
    delete p;
}

void deleteFirstPsg(PassengerList &L, psgAddress &deleted) {
    if (L.first == nullptr) {
        deleted = nullptr;
        return;
    }

    if (L.first == L.last) {
        L.last = nullptr;
    }

    deleted = L.first;
    L.first = deleted->next;
    deleted->next = nullptr;
}

void deleteLastPsg(PassengerList &L) {
    if (L.first == nullptr) {
        return;
    }

    if (L.first == L.last) {
        delete L.first;
        L.first = nullptr;
        L.last = nullptr;
    }
    else {
        L.last = L.last->prev;
        delete L.last->next;
        L.last->next = nullptr;
    }
}

void deleteLastPsg(PassengerList &L, psgAddress &deleted) {
    if (L.first == nullptr) {
        deleted = nullptr;
        return;
    }

    if (L.first == L.last) {
        deleted = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }
    else {
        L.last = L.last->prev;
        deleted = L.last->next;
        L.last->next = nullptr;
    }
}

void deleteAfterPsg(PassengerList &L, psgAddress prec) {
    if (prec == nullptr || prec->next == nullptr) {
        return;
    }

    psgAddress p = prec->next;

    if (prec->next == L.last) {
        L.last = prec;
    } else {
        p->next->prev = prec;
    }

    prec->next = p->next;
    delete p;
}

void deleteAfterPsg(PassengerList &L, psgAddress prec, psgAddress &deleted) {
    if (prec == nullptr || prec->next == nullptr) {
        return;
    }

    deleted = prec->next;

    if (prec->next == L.last) {
        L.last = prec;
    }
    else {
        deleted->next->prev = prec;
    }

    prec->next = deleted->next;
    deleted->next = nullptr;
    deleted->prev = nullptr;
}

psgAddress findElmPassenger(PassengerList L, int id) {
    psgAddress p = L.first;
    while (p && p->info.passengerID != id) p = p->next;
    return p;
}

void displayListPassenger(PassengerList L) {
    int i = 1;
    for (psgAddress p = L.first; p; p = p->next) {
        std::cout << "Passenger-" << i << ":\n";
        std::cout << "ID: "<< p->info.passengerID << "\n";
        std::cout << "Nama: "<< p->info.name << "\n" << std::endl;
        std::cout << "Date of Birth: "<< p->info.dateOfBirth << "\n" << std::endl;
        ++i;
    }
}