#include "app.h"

int main() {
    Config cfg = {
        .main_menu_content_width = 87,
        .main_menu_content_height = 30,

        .home_content_width = 80,
        .home_content_height = 30,

        .max_bus = 8,
        .max_market_bus = 10,

        .initial_m_bus_count = 5,
        .initial_money = 1000.0,

        .market_refresh_interval = 20,
    };

    PlayerState player;
    Market market;
    
    AppState app = createApp(&player, &market, &cfg);

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(0);

    runApp(&app, &player, &market);

    endwin();
    
    return 0;
}