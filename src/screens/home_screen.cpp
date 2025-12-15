#include "home_screen.h"

void HomeScreen(AppState *app, int initial_pos_y, int initial_pos_x) {
    clear();
    mvprintw(2, initial_pos_x, "=== SCREEN A ===");
    mvprintw(4, initial_pos_x, "Press 'b' to go back to menu");
    mvprintw(5, initial_pos_x, "Press 'q' or ESC to exit");

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