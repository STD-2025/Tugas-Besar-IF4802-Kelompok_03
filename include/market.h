#pragma once

#include "bus.h"
#include "player.h"

typedef struct {
    BusList busList;
    int busCount;
} Market;

void initializeMarket(Market *market);
void refreshStock(Market *market);

bool buyBus(Market *market, PlayerState *player, Bus bus);
bool sellBus(PlayerState *player, Bus bus);