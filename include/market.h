#pragma once

#include "bus.h"

typedef struct {
    BusList busList;
} Market;

void initializeMarket(Market *market);
void refreshStock(Market *market);