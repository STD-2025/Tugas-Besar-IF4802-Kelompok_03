#pragma once

#include "bus.h"
#include "player.h"
#include "config.h"
#include <vector>

typedef struct {
    std::vector<Bus> busList;
    int maxBus;
} Market;

void initializeMarket(Market *market, Config *cfg);
void refreshStock(Market *market);

bool buyBus(Market *market, PlayerState *player, Bus bus);
bool sellBus(PlayerState *player, Bus bus);