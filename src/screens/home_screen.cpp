#include "home_screen.h"
#include "config.h"

void HomeScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x) {
    clear();

    int pos_y = 2;

    mvprintw(pos_y++, initial_pos_x, "============================================");
    mvprintw(pos_y++, initial_pos_x, "Balance : %g", player->money);
    mvprintw(pos_y++, initial_pos_x, "============================================");
    mvprintw(pos_y++, initial_pos_x, "Bus count : %d / %d", player->busCount, MAX_BUS);

    move(pos_y++, initial_pos_x++);

    if (player->busList.first == nullptr) {
        mvprintw(pos_y++, initial_pos_x, "You dont have any bus");
    } else {
        for (busElement *bus = player->busList.first; bus; bus = bus->next) {
            mvprintw(
                pos_y++, initial_pos_x, "%s (%d/%d)", 
                bus->info.busName.c_str(), 
                bus->info.passengerCount,
                bus->info.capacity
            );
        }
    }

    move(pos_y++, initial_pos_x--);

    mvprintw(pos_y++, initial_pos_x, "============================================");
    mvprintw(pos_y++, initial_pos_x, "1. Buy bus");
    mvprintw(pos_y++, initial_pos_x, "2. Sell bus");
    mvprintw(pos_y++, initial_pos_x, "3. View bus passenger");
    mvprintw(pos_y++, initial_pos_x, "4. Buy bus");
    mvprintw(pos_y++, initial_pos_x, "5. Buy bus");
    mvprintw(pos_y++, initial_pos_x, "6. Buy bus");
    mvprintw(pos_y++, initial_pos_x, "7. Buy bus");
    mvprintw(pos_y++, initial_pos_x, "8. Buy bus");

    refresh();

    while (true) {
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