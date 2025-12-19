#include "screen.h"
#include "config.h"

void HomeScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x) {
    clear();

    int pos_y = 2;

    mvprintw(pos_y++, initial_pos_x, "============================================");
    mvprintw(pos_y++, initial_pos_x, "Balance : %g", player->money);
    mvprintw(pos_y++, initial_pos_x, "============================================");
    mvprintw(pos_y++, initial_pos_x, "Bus count : %d / %d", player->busCount, app->config->max_bus);

    move(pos_y++, initial_pos_x++);

    if (player->busList.first == nullptr) {
        mvprintw(pos_y++, initial_pos_x, "You dont have any bus");
    } else {
        for (busElement *bus = player->busList.first; bus; bus = bus->next) {
            mvprintw(
                pos_y++, initial_pos_x, "%s : (%d/%d)", 
                bus->info.busName.c_str(), 
                bus->info.passengerCount,
                bus->info.capacity
            );
        }
    }

    move(pos_y++, initial_pos_x--);

    mvprintw(pos_y++, initial_pos_x, "============================================");
    mvprintw(pos_y++, initial_pos_x, "1 : View bus passenger");
    mvprintw(pos_y++, initial_pos_x, "2 : Buy bus");
    mvprintw(pos_y++, initial_pos_x, "3 : Sell bus");
    mvprintw(pos_y++, initial_pos_x, "4 : See all passenger");
    mvprintw(pos_y++, initial_pos_x, "q : Exit game");
    mvprintw(pos_y++, initial_pos_x, "============================================");

    refresh();

    while (true) {
        int ch = getch();
        switch (ch) {
            case '1':
                app->current = SCREEN_MENU;
                return;
            
            case '2':
                app->current = SCREEN_MENU;
                return;

            case '3':
                app->current = SCREEN_MENU;
                return;
            case '4':
                app->current = SCREEN_MENU;
                return;

            case 'q':
            case 27: // ESC
                app->current = SCREEN_EXIT;
                return;
        }
    }
}