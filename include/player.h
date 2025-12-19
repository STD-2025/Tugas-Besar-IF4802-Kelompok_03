#pragma once

#include "bus.h"
#include "config.h"

typedef struct {
    double money;
    BusList busList;
    int busCount;
} PlayerState;

void initializePlayer(PlayerState *player, Config *cfg);