#include "app.h"
#include "menu_screen.h"
#include "screenA.h"

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
                menuScreen(app, getCenterPosY(MENU_CONTENT_HEIGHT), getCenterPosX(MENU_CONTENT_WIDTH));
                break;

            case SCREEN_A:
                screenA_run(app);
                break;

            case SCREEN_EXIT:
                app->isRunning = false;
                break;
        }
    }
}
