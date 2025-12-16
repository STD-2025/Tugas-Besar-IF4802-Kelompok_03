#pragma once

#include "bus.h"

typedef struct {
    double money;
    BusList busList;
    int busCount;
} PlayerState;

void initializePlayer(PlayerState *player);