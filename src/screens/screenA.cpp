#include "screenA.h"

void screenA_run(AppState *app) {
    clear();
    mvprintw(2, 2, "=== SCREEN A ===");
    mvprintw(4, 2, "Press 'b' to go back to menu");
    mvprintw(5, 2, "Press 'q' or ESC to exit");

    refresh();

    while (1) {
        int ch = getch();
        switch (ch) {
            case 'b':
                app->current = SCREEN_MENU;
                return;

            case 'q':
            case 27: // ESC
                app->current = SCREEN_EXIT;
                return;
        }
    }
}