#include "app.h"

int main() {
    Config cfg = {
        .main_menu_content_width = 87,
        .main_menu_content_height = 30,

        .home_content_width = 60,
        .home_content_height = 30,

        .max_bus = 12,

        .initial_money = 1000.0,
    };

    PlayerState player;
    
    AppState app = createApp(&player, &cfg);

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    runApp(&app, &player);

    endwin();
    
    return 0;
}