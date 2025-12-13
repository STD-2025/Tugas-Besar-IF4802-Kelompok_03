#include "app.h"

int main() {
    AppState app;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    app_init(&app);
    app_run(&app);

    endwin();
    return 0;
}