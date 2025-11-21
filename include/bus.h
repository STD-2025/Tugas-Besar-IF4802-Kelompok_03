#pragma once

typedef struct {
    int busID;
    int capacity;
} infotype;

typedef struct busElement *busAddress;

struct busElement {
    infotype info;
    busAddress next;
};

