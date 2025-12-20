#include "screen.h"
#include <algorithm>

void BuyBusScreen(
    AppState *app,
    PlayerState *player,
    Market *market,
    int initial_pos_y,
    int initial_pos_x
) {
    clear();

    auto tLeft = timeLeft(app->tm.timers[REFRESH_STOCK]).count() / 1000;
    
    int pos_y = 2;
    int x_spacing = 1;
    int pos_x = initial_pos_x + x_spacing;

    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x, "Balance : %g", player->money);
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x, "Market refresh in: %02lds", tLeft);

    move(pos_y++, pos_x);

    for (int i = 0; i < market->busList.size(); ++i) {
        mvprintw(
            pos_y++, pos_x, "[%03d] %s : Capacity (%d) Route (%s - %s) : $%g",
            market->busList[i].busID,
            market->busList[i].busName.c_str(),
            market->busList[i].capacity,
            market->busList[i].route.start.c_str(),
            market->busList[i].route.end.c_str(),
            market->busList[i].price
        );
    }

    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);

    for (int i = 0; i < std::min(static_cast<int>(market->busList.size()), 8); ++i) {
        mvprintw(
            pos_y++, pos_x, "%d : Buy [%03d] %s",
            i+1,
            market->busList[i].busID,
            market->busList[i].busName.c_str()
        );
    }

    mvprintw(pos_y++, pos_x, "b : Back to home");

    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");

    int ch = getch();

    if (ch != ERR) {
        if (ch >= '1' && ch <= '9') {
            size_t index = ch - '1';

            if (index < market->busList.size()) {
                buyBus(market, player, market->busList[index]);
            }

            return;
        }

        if (ch == 'b') {
            app->current = SCREEN_HOME;
            return;
        }
    }

    refresh();
}