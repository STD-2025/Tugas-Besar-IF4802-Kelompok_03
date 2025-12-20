#include "app.h"
#include "screen.h"
#include "screen_helper.h"
#include <thread>

AppState createApp(PlayerState *player, Market *market, Config *cfg) {
    initializePlayer(player, cfg);
    initializeMarket(market, cfg);

    TimerManager tm;

    AppState app = {
        .current = SCREEN_MENU,
        .isRunning = true,
        .config = cfg,
        .tm = tm
    };

    addTimer(&app.tm, seconds(cfg->market_refresh_interval),
        [market]() {
            refreshStock(market);
        }
    );

    return app;
}

void runApp(AppState *app, PlayerState *player, Market *market) {
    const Config *cfg = app->config;

    while (app->isRunning) {
        update(&app->tm);

        switch (app->current) {
            case SCREEN_MENU:
                MainMenuScreen(app, getCenterPosY(cfg->main_menu_content_height), getCenterPosX(cfg->main_menu_content_width));
                break;

            case SCREEN_HOME:
                HomeScreen(app, player, getCenterPosY(cfg->home_content_height), getCenterPosX(cfg->home_content_width));
                break;

            // case SCREEN_BUS:
            //     BusScreen(app, player, getCenterPosY(cfg->home_content_height), getCenterPosX(cfg->home_content_width));
            //     break;

            case SCREEN_BUY_BUS:
                BuyBusScreen(app, player, market, getCenterPosY(cfg->home_content_height), getCenterPosX(cfg->home_content_width));
                break;

            // case SCREEN_SELL_BUS:
            //     SellBusScreen(app, player, getCenterPosY(cfg->home_content_height), getCenterPosX(cfg->home_content_width));
            //     break;

            case SCREEN_EXIT:
                app->isRunning = false;
                break;
        }

        refresh();
        std::this_thread::sleep_for(milliseconds(16));
    }
}
