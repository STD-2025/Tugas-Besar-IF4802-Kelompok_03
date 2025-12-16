#include "app.h"

int main() {
    AppState app;
    PlayerState player;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    app_init(&app, &player);
    app_run(&app, &player);

    endwin();
    return 0;
}