#pragma once

#include "bus.h"
#include "player.h"

typedef struct {
    BusList busList;
} Market;

void initializeMarket(Market *market);
void refreshStock(Market *market);

bool BuyBus(PlayerState player, BusList marketBusList, Bus bus);
bool SellBus(PlayerState player, Bus bus);