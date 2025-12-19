#include "player.h"
#include "bus_operation.h"

void initializePlayer(PlayerState *player, Config *cfg) {
    player->money = cfg->initial_money;
    player->busCount = 0;
    createListBus(player->busList);
}