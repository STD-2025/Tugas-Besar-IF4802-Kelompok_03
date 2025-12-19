#pragma once

#include <ncurses.h>
#include "player.h"
#include "config.h"

typedef enum {
    SCREEN_EXIT,
    SCREEN_MENU,
    SCREEN_HOME,
    SCREEN_BUS,
    SCREEN_BUY_BUS,
    SCREEN_SELL_BUS,
    SCREEN_PASSENGER
} Screen;

typedef struct {
    Screen current;
    bool isRunning;
    const Config *config;
} AppState;

AppState createApp(PlayerState *player, Config *cfg);
void runApp(AppState *app, PlayerState *player);