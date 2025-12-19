#include "market.h"
#include "randomizer.h"
#include "bus_operation.h"

void initializeMarket(Market *market) {

}

void refreshStock(Market *market) {
    int deletedCount = randomInt(0, market->busCount);

    for (int i = 0; i < deletedCount; ++i) {
        
    }
}

bool buyBus(Market *market, PlayerState *player, Bus bus) {
    BusList marketBusList = market->busList; 

    busAddress adrBus = findElmBus(marketBusList, bus.busID);
    if (adrBus == nullptr) {
        return false;
    }

    if (player->money < bus.price) {
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

    insertLastBus(player->busList, deleted);

    player->money -= bus.price;

    return true;
}

bool sellBus(PlayerState *player, Bus bus) {
    busAddress adrBus = findElmBus(player->busList, bus.busID);
    if (adrBus == nullptr) {
        return false;
    }

    busAddress deleted;

    if (player->busList.first == adrBus) {
        deleteFirstBus(player->busList, deleted);
    } else {
        busAddress prec = player->busList.first;
        while (prec->next != adrBus) {
            prec = prec->next;
        }
        deleteAfterBus(player->busList, prec, deleted);
    }

    player->money += bus.price;

    return true;
}