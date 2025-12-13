#include "menu_screen.h"

static const char *menu_items[] = {
    "Go to Screen A",
    "Exit"
};

#define MENU_COUNT 2

void menu_screen(AppState *app) {
    int selected = 0;

    while (true) {
        clear();

        mvprintw(1, 2, "=== MENU ===");
        for (int i = 0; i < MENU_COUNT; i++) {
            if (i == selected)
                attron(A_REVERSE);

            mvprintw(3 + i, 4, "%s", menu_items[i]);

            if (i == selected)
                attroff(A_REVERSE);
        }

        refresh();

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                selected = (selected - 1 + MENU_COUNT) % MENU_COUNT;
                break;

            case KEY_DOWN:
                selected = (selected + 1) % MENU_COUNT;
                break;

            case '\n':  // Enter
                if (selected == 0) {
                    app->current = SCREEN_A;
                    return;
                } else if (selected == 1) {
                    app->current = SCREEN_EXIT;
                    return;
                }
                break;

            case 27: // ESC
            case 'q':
                app->current = SCREEN_EXIT;
                return;
        }
    }
}