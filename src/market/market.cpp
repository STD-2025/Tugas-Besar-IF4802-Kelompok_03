#include "market.h"
#include "bus_operation.h"

void initializeMarket(Market *market) {

}

void refreshStock(Market *market) {
    
}

bool BuyBus(PlayerState player, BusList marketBusList, Bus bus) {
    /**
     * TODO
     * 
     * 1. Cek apakah uang player cukup untuk membeli bus
     * 2. Jika uang tidak cukup return false
     * 3. Jika cukup, hapus bus dari marketBusList, lalu tambahkan
     *      ke BusList pada player.
     * 4. Kurangi uang player
     * 5. Return true untuk mengindikasikan operasi berhasil
     */
    busAddress adrBus = findElmBus(marketBusList, bus.busID);
    if (adrBus == nullptr) {
        return false;
    }

    if (player.money < adrBus->info.price) {
        return false;
    }

    busAddress deleted;

    if (marketBusList.first == adrBus) {
        deleteFirstBus(marketBusList, deleted);
    } else {
        busAddress prec = marketBusList.first;
        while (prec->next != adrBus) {
            prec = prec->next;
        }
        deleteAfterBus(marketBusList, prec, deleted);
    }

    insertLastBus(player.busList, deleted);

    player.money -= deleted->info.price;

    return true;
}

bool SellBus(PlayerState player, Bus bus) {
    /**
     * TODO
     * 
     * 1. Hapus bus dari BusList milik player
     * 2. Tambah uang player
     * 3. Return true untuk mengindikasikan operasi berhasil
     */
    busAddress adrBus = findElmBus(player.busList, bus.busID);
    if (adrBus == nullptr) {
        return false;
    }

    busAddress deleted;

    if (player.busList.first == adrBus) {
        deleteFirstBus(player.busList, deleted);
    } else {
        busAddress prec = player.busList.first;
        while (prec->next != adrBus) {
            prec = prec->next;
        }
        deleteAfterBus(player.busList, prec, deleted);
    }

    player.money += deleted->info.price;

    return true;
}