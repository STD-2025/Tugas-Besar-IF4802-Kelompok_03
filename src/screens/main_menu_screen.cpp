#include "screen.h"
#include "ascii_items.h"

#define MENU_COUNT 2

const ASCII_ART menu_items[] = {ART_START, ART_EXIT};

void MainMenuScreen(AppState *app, int initial_py, int initial_px) {
    static int selected = 0;

    clear();

    int py = initial_py + 1 + printArt(ART_TITLE.art, ART_TITLE.lines, initial_py, initial_px);    

    for (int i = 0; i < MENU_COUNT; i++) {
        if (i == selected)
            printArt(ART_ARROW.art, ART_ARROW.lines, py, initial_px);
        
        py = py + 1 + printArt(menu_items[i].art, menu_items[i].lines, py, initial_px + 5);
    }

    mvprintw(py, initial_px, "=======================================================================================");

    refresh();

    int ch = getch();

    switch (ch) {
    case KEY_UP:
        selected = (selected - 1 + MENU_COUNT) % MENU_COUNT;
        break;

    case KEY_DOWN:
        selected = (selected + 1) % MENU_COUNT;
        break;

    case '\n':
        switch (selected)
        {
        case 0:
            app->current = SCREEN_HOME;
            break;
        
        case 1:
            app->current = SCREEN_EXIT;
            break;
        }
        return;
    }
}