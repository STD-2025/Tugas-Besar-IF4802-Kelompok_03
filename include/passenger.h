#pragma once

typedef struct {
    int passengerID;;
} infotype;

typedef struct psgElement *psgAddress;

struct psgElement {
    infotype info;
    psgAddress next;
};

typedef struct {
    psgAddress first;
} psgList;