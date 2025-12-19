#pragma once

#include "app.h"
#include "player.h"

void MainMenuScreen(AppState *app, int initial_pos_y, int initial_pos_x);

void HomeScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x);

void BusScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x);

void BuyBusScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x);

void SellBusScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x);