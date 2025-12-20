#include "screen.h"
#include "passenger.h"

void BusScreen(AppState *app, PlayerState *player, int initial_pos_y, int initial_pos_x) {
     clear();

    static busAddress currentBus = nullptr;

    // inisialisasi pertama kali
    if (currentBus == nullptr) {
        currentBus = player->busList.first;
    }

    int pos_y = 2;
    int x_spacing = 1;
    int pos_x = initial_pos_x + x_spacing;

    // ================= HEADER =================
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x, "Balance : %g", player->money);
    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);

    // ================= NO BUS =================
    if (currentBus == nullptr) {
        mvprintw(pos_y++, pos_x, "You dont have any bus");
        move(pos_y++, pos_x);
        mvprintw(pos_y++, pos_x, "b : Back to home");

        refresh();
        int ch = getch();
        if (ch == 'b') {
            app->current = SCREEN_HOME;
        }
        return;
    }

    // ================= BUS INFO =================
    mvprintw(
        pos_y++, pos_x,
        "Bus [%03d] %s",
        currentBus->info.busID,
        currentBus->info.busName.c_str()
    );

    move(pos_y++, pos_x);

    // ================= PASSENGER LIST =================
    psgAddress p = currentBus->firstPsg;

    if (p == nullptr) {
        mvprintw(pos_y++, pos_x, "No passenger on this bus");
    } else {
        while (p != nullptr) {
            mvprintw(
                pos_y++, pos_x,
                "Seat #%d [%03d] %s : %d y.o.",
                p->info.seatNo,
                p->info.passengerID,
                p->info.name.c_str(),
                p->info.age
            );
            p = p->next;
        }
    }

    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");
    move(pos_y++, pos_x);

    // ================= MENU =================
    mvprintw(pos_y++, pos_x, "1 : Next bus");
    mvprintw(pos_y++, pos_x, "2 : Prev bus");
    mvprintw(pos_y++, pos_x, "3 : Advertize");
    mvprintw(pos_y++, pos_x, "4 : Remove passenger");
    mvprintw(pos_y++, pos_x, "b : Back to home");

    move(pos_y++, pos_x);
    mvprintw(pos_y++, pos_x-x_spacing, "================================================================================");

    refresh();

    // ================= INPUT =================
    int ch = getch();

    if (ch == '1') { // Next bus
        if (currentBus->next != nullptr) {
            currentBus = currentBus->next;
        }
    }
    else if (ch == '2') { // Prev bus
        busAddress prev = nullptr;
        for (busAddress b = player->busList.first; b != nullptr && b != currentBus; b = b->next) {
            prev = b;
        }
        if (prev != nullptr) {
            currentBus = prev;
        }
    }
    else if (ch == '3') {
        // Advertize (belum diimplementasi)
    }
    else if (ch == '4') {
        // Remove passenger (belum diimplementasi)
    }
    else if (ch == 'b') {
        currentBus = nullptr; // reset saat keluar
        app->current = SCREEN_HOME;
    }
}