#include "app.h"
#include "main_menu_screen.h"
#include "home_screen.h"

#include "screen_helper.h"
#include "config.h"

void app_init(AppState *app) {
    app->current = SCREEN_MENU;
    app->isRunning = true;
}

void app_run(AppState *app) {
    while (app->isRunning) {
        switch (app->current) {
            case SCREEN_MENU:
                MainMenuScreen(app, getCenterPosY(MAIN_MENU_CONTENT_HEIGHT), getCenterPosX(MAIN_MENU_CONTENT_WIDTH));
                break;

            case SCREEN_A:
                HomeScreen(app, getCenterPosY(HOME_CONTENT_HEIGHT), getCenterPosX(HOME_CONTENT_WIDTH));
                break;

            case SCREEN_EXIT:
                app->isRunning = false;
                break;
        }
    }
}
