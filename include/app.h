#pragma once

#include <ncurses.h>
#include "player_state.h"

typedef enum {
    SCREEN_MENU,
    SCREEN_A,
    SCREEN_EXIT
} ScreenType;

typedef struct {
    ScreenType current;
    bool isRunning;
} AppState;

void app_init(AppState *app, PlayerState *player);
void app_run(AppState *app, PlayerState *player);