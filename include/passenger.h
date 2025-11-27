#pragma once

typedef struct {
    int passengerID;
} infotype;

typedef struct psgElement *psgAddress;

struct psgElement {
    infotype info;
    psgAddress next;
    psgAddress prev;
};

typedef struct {
    psgAddress first;
    psgAddress last;
} psgList;