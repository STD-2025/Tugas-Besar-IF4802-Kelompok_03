#include "screen.h"

void HomeScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x) {
    clear();

    static int menuPage = 0;

    int pos_y = 2;
    int x_spacing = 1;
    int pos_x = initial_pos_x + x_spacing;

    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x, "Balance : $%g", player->money);
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x, "Bus count : %d / %d", player->busCount, app->config->max_bus);

    move(pos_y++, pos_x);

    if (player->busList.first == nullptr) {
        mvprintw(pos_y++, pos_x, "You dont have any bus");
    } else {
        for (busElement *bus = player->busList.first; bus; bus = bus->next) {
            mvprintw(
                pos_y++, pos_x, "%s : (%d/%d)", 
                bus->info.busName.c_str(), 
                bus->info.passengerCount,
                bus->info.capacity
            );
        }
    }

    move(pos_y++, pos_x);

    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);
    
    switch (menuPage)
    {
    case 0:
        mvprintw(pos_y++, pos_x, "1 : View bus passenger");
        mvprintw(pos_y++, pos_x, "2 : Buy bus");
        mvprintw(pos_y++, pos_x, "3 : Sell bus");
        mvprintw(pos_y++, pos_x, "4 : See all passenger");
        mvprintw(pos_y++, pos_x, "q : Exit game");

        break;
    
    case 1:
        int i = 1;
        for (busElement *bus = player->busList.first; bus; bus = bus->next) {
            mvprintw(
                pos_y++, pos_x, "%d : Sell [%03d] %s for $",
                i++,
                bus->info.busID,
                bus->info.busName.c_str(),
                bus->info.price                
            );
        }
        mvprintw(pos_y++, pos_x, "b : Back to page 1");

        break;
    }

    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");

    refresh();

    int ch = getch();
    switch (menuPage)
    {
    case 0:
        switch (ch) {
            case '1':
                app->current = SCREEN_BUS;
                return;
            
            case '2':
                app->current = SCREEN_BUY_BUS;
                return;

            case '3':
                menuPage = 1;
                return;

            case '4':
                app->current = SCREEN_MENU;
                return;

            case 'q':
                app->current = SCREEN_EXIT;
                return;
        }
        break;
    
    case 1:
        if (ch != ERR) {
            if (ch >= '1' && ch <= '9') {
                size_t index = ch - '1';

                if (index < player->busCount) {
                    busAddress p = player->busList.first;
                    for (int i = 0; i < index; ++i) {
                        p = p->next;
                    }

                    sellBus(player, p->info);
                }

                return;
            }

            if (ch == 'b') {
                menuPage = 0;
                return;
            }
        }
        break;
    }
}