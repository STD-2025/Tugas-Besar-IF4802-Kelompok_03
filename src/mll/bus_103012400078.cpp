#include "bus_operation.h"

void deleteFirstBus(BusList  &L) {
    if (L.first == nullptr) return;

    busAddress p = L.first;
    L.first = p->next;
    delete p;
}

void deleteFirstBus(BusList  &L, busAddress &deleted) {
    if (L.first == nullptr) {
        deleted = nullptr;
        return;
    }

    deleted = L.first;
    L.first = deleted->next;
    deleted->next = nullptr;
}

void deleteLastBus(BusList &L) {
    if (L.first == nullptr) {
        return;
    }

    if (L.first->next == nullptr) {
        delete L.first;
        L.first = nullptr;
    }
    else {
        busAddress p = L.first;
        while (p->next->next) p = p->next;
        delete p->next;
        p->next = nullptr;
    }
}

void deleteLastBus(BusList &L, busAddress &deleted) {
    if (L.first == nullptr) {
        deleted = nullptr;
        return;
    }

    if (L.first->next == nullptr) {
        deleted = L.first;
        L.first = nullptr;
    }
    else {
        busAddress p = L.first;
        while (p->next->next) p = p->next;
        deleted = p->next;
        p->next = nullptr;
    }
}

void deleteAfterBus(BusList &L, busAddress prec) {
    if (prec == nullptr || prec->next == nullptr) {
        return;
    }

    busAddress p = prec->next;
    prec->next = prec->next->next;
    delete p;
}

void deleteAfterBus(BusList &L, busAddress prec, busAddress &deleted) {
    if (prec == nullptr || prec->next == nullptr) {
        return;
    }

    deleted = prec->next;
    prec->next = prec->next->next;
    deleted->next = nullptr;
}

busAddress findElmBus(BusList L, int id) {
    busAddress p = L.first;
    while (p && p->info.busID != id) p = p->next;
    return p;
}