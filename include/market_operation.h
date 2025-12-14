#pragma once

#include "player_state.h"
#include "bus.h"
#include "market_list.h"

bool BuyBus(PlayerState player, BusList marketBusList, Bus bus);

bool SellBus(PlayerState player, Bus bus);