#include "app.h"
#include "menu_screen.h"
#include "screenA.h"

void app_init(AppState *app) {
    app->current = SCREEN_MENU;
    app->isRunning = true;
}

void app_run(AppState *app) {
    while (app->isRunning) {
        switch (app->current) {
            case SCREEN_MENU:
                menu_screen(app);
                break;

            case SCREEN_A:
                screenA_run(app);
                break;

            case SCREEN_EXIT:
                app->isRunning = 0;
                break;
        }
    }
}
